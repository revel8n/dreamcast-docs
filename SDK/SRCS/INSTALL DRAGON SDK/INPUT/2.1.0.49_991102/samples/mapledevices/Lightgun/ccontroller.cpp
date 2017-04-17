/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Copyright (c) 1999 Microsoft Corporation

Module Name:

    CController.cpp

Abstract:

    CController functionality for DirectInput

-------------------------------------------------------------------*/

#include "Lightgun.hpp"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::CController

Description:

    Constructor for the CController class.

Arguments:

    GUID          guid          - Guid of the device

    LPDIRECTINPUT pDI           - Pointer to the global DirectInput object

    DWORD         dwDiDevType   - The device type.

Return Value:

    None

-------------------------------------------------------------------*/
CController::CController(GUID guid, DWORD dwDiDevType)
{
    m_guid         = guid;
    m_port         = 0xFF;
    m_pDID         = NULL;
    m_nAxes        = 0;
    m_nButtons     = 0;
    m_dwDiDevType  = GET_DIDEVICE_TYPE(dwDiDevType);
    m_plightgun    = NULL;

    // Clear out the current state.
    memset(m_buttonIndices, g_iInvalid, g_nMaxButtons);
    memset(m_axisIndices,   g_iInvalid, g_nMaxAxes * sizeof(typeAxis));

    memset(m_curButtonValues,       0, g_nMaxButtons);
    memset(m_rgfButtonStateChanged, 0, g_nMaxButtons);
    memset(m_curAxisValues,         0, g_nMaxAxes * sizeof(LONG));
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::~CController

Description:

    Destructor for the CController class.

Arguments:

    None

Return Value:

    None

-------------------------------------------------------------------*/
CController::~CController()
{
    if (m_pDID != NULL)
    {
        m_pDID->Unacquire();
        m_pDID->Release();
    }
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::DIEnumDeviceObjectsProcStub

Description:

    This is a stub function for the EnumerateObjects callback.  Static stubs 
    like this are needed for callbacks that are C++ object member functions.

Arguments:

    LPCDIDEVICEOBJECTINSTANCE pDIDOI - The object being enumerated
    
    LPVOID context                   - pointer to the controller object

Return Value:

    TRUE to continue, FALSE to stop

-------------------------------------------------------------------*/
BOOL CALLBACK
CController::DIEnumDeviceObjectsProcStub(LPCDIDEVICEOBJECTINSTANCE pDIDOI, LPVOID pvContext)
{
    CController *pController = (CController*)pvContext;
    return(pController->DIEnumDeviceObjectsProc(pDIDOI));
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::Initialize

Description:

    Call this on a CController object immediately after creating it.  
    If it fails delete the object.

Arguments:

    None

Return Value:

    TRUE on success, FALSE on failure.

-------------------------------------------------------------------*/
BOOL
CController::Initialize(void)
{
    LPDIRECTINPUTDEVICE pDID1;
    DIPROPDWORD         dipropdword;

    // Create the DirectInput device
    g_errLast = g_pdi->CreateDevice(m_guid, &pDID1, NULL);
    if (CheckError(TEXT("Create Device")))
        return FALSE;
    
    // Get a DirectInput2 interface to the device
    g_errLast = pDID1->QueryInterface(IID_IDirectInputDevice2, (LPVOID*)&m_pDID);
    if (CheckError(TEXT("Query Interface for DirectInputDevice2")))
    {
        pDID1->Release();
        return FALSE;
    }

    // As per COM-rules, release the interface we created and no longer need.
    pDID1->Release();

    // Get the port number of the device
    dipropdword.diph.dwSize       = sizeof(DIPROPDWORD);
    dipropdword.diph.dwHeaderSize = sizeof(DIPROPHEADER);
    dipropdword.diph.dwObj = 0;
    dipropdword.diph.dwHow = DIPH_DEVICE;
    g_errLast = m_pDID->GetProperty(DIPROP_PORTNUMBER, &dipropdword.diph);
    if (CheckError(TEXT("Get Port Number")))
        return FALSE;                                              

    m_port = dipropdword.dwData;
    
    // Get the device's capabilities
    m_devcaps.dwSize = sizeof(DIDEVCAPS);
    g_errLast = m_pDID->GetCapabilities(&m_devcaps);
    if (CheckError(TEXT("Get Device Capabilities")))
        return FALSE;

    // Check if it's a keyboard or joystick
    if (m_dwDiDevType == DIDEVTYPE_KEYBOARD)
    {
        g_errLast = m_pDID->SetDataFormat(&c_dfDIKeyboard);
        if (CheckError(TEXT("Set Data Format (Keyboard)")))
            return FALSE;
    }
    else
    {
        // EnumObjects is how we determine how many buttons and axes this controller
        // has.  By interpreting this data correctly we can automatically work with
        // new controllers that have a different number of buttons, etc.
        // DirectInput will call our DIEnumDeviceObjectsProcStub (which will then
        // call our DIEnumDeviceObjectsProc) once for each object (button or axis)
        // on the device.
        if (m_dwDiDevType == DIDEVTYPE_JOYSTICK)
        {
            g_errLast = m_pDID->EnumObjects(DIEnumDeviceObjectsProcStub, this, 0);
            if (CheckError(TEXT("Enumerate Objects")))
                return FALSE;
        }

        g_errLast = m_pDID->SetDataFormat(&c_dfDIJoystick);
        if (CheckError(TEXT("Set Data Format (Joystick)")))
            return FALSE;

        // Set up the axes
        for (int i = 0; i < g_nMaxAxes; i++)
        {
            if (m_axisIndices[i].iAxis != g_iInvalid)
            {
                // There is an axis here!
                dipropdword.diph.dwSize = sizeof(DIPROPDWORD);
                dipropdword.diph.dwHeaderSize = sizeof(DIPROPHEADER);
                dipropdword.diph.dwHow = DIPH_BYOFFSET;
                dipropdword.dwData = 1000;  //10% (5 on either side)
                switch (m_axisIndices[i].eaxis)
                {
                case eXAxis:
                    // Get the range and dead zone for the X axis.
                    m_diprangeX.diph.dwSize = sizeof(DIPROPRANGE);
                    m_diprangeX.diph.dwHeaderSize = sizeof(DIPROPHEADER);
                    m_diprangeX.diph.dwHow = DIPH_BYOFFSET;
                    m_diprangeX.diph.dwObj = g_uiXAxisOffset;
                    g_errLast = m_pDID->GetProperty(DIPROP_RANGE, (LPDIPROPHEADER)&m_diprangeX);
                    if (CheckError(TEXT("Get Digital X Range")))
                        return FALSE;

                    dipropdword.diph.dwObj = g_uiXAxisOffset;
                    g_errLast = m_pDID->SetProperty(DIPROP_DEADZONE, &dipropdword.diph);
                    if (CheckError(TEXT("Set X DeadZone")))
                        return FALSE;
                    break;

                case eYAxis:
                    // Get the range and dead zone for the Y axis.
                    m_diprangeY.diph.dwSize = sizeof(DIPROPRANGE);
                    m_diprangeY.diph.dwHeaderSize = sizeof(DIPROPHEADER);
                    m_diprangeY.diph.dwHow = DIPH_BYOFFSET;
                    m_diprangeY.diph.dwObj = g_uiYAxisOffset;
                    g_errLast = m_pDID->GetProperty(DIPROP_RANGE, (LPDIPROPHEADER)&m_diprangeY);
                    if (CheckError(TEXT("Get Digital Y Range")))
                        return FALSE;

                    dipropdword.diph.dwObj = g_uiYAxisOffset;
                    g_errLast = m_pDID->SetProperty(DIPROP_DEADZONE, &dipropdword.diph);
                    if (CheckError(TEXT("Set Y DeadZone")))
                        return FALSE;
                    break;

                }
            }
        }
    }

    // Finally, Acquire the port
    g_errLast = m_pDID->Acquire();
    if (CheckError(TEXT("Acquire port")))
        return FALSE;
    
    return TRUE;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::Poll

Description:

    Poll for data

Arguments:

    None

Return Value:

    TRUE on success, FALSE on failure.

-------------------------------------------------------------------*/
BOOL
CController::Poll(void)
{
    g_errLast = m_pDID->Poll();
    if (CheckError(TEXT("Poll")))
        return FALSE;

    return TRUE;
}    

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::GetData

Description:

    This is where all the real work is done.  The app calls this every time it 
    wants new data from a controller.
    This supports the ability to handle any button in the Maple FT0 format.  
    It will skip anything that does not exist on the currently plugged
    in controller.  Because I don't know what Analog Axis 5 and 6 will be used 
    for, I don't know how to support them here.

Arguments:

    None

Return Value:

    TRUE on success, FALSE on failure.

-------------------------------------------------------------------*/
BOOL
CController::GetData(void)
{
    DIJOYSTATE dijoystate;
    DWORD dwNumButtons = m_devcaps.dwButtons;
    LONG lData;
    BYTE index;    
    int iButton;

    // Ignore keyboards for this sample
    if (m_dwDiDevType == DIDEVTYPE_KEYBOARD)
        return TRUE;

    g_errLast = m_pDID->GetDeviceState(sizeof(DIJOYSTATE), &dijoystate);
    if (g_errLast == DIERR_UNPLUGGED)
    {
        DebugOutput(TEXT("port %d unplugged\n"), m_port);
        return FALSE;
    }
    else if (CheckError(TEXT("GetDeviceState")))
        return FALSE;

    // Check Buttons
    for (iButton = g_iAButton; iButton <= g_iAn6Button; iButton++)
    {
        index = m_buttonIndices[iButton];
        if (index != g_iInvalid)
        {
            m_rgfButtonStateChanged[index] = (m_curButtonValues[index] != dijoystate.rgbButtons[index]);
            m_curButtonValues[index] = dijoystate.rgbButtons[index];
        }
    }

    // Check Axes
    for (int i = 0; i < g_nMaxAxes; i++)
    {
        index = m_axisIndices[i].iAxis;
        if (index != g_iInvalid)
        {
            switch (m_axisIndices[i].eaxis) {
            case eXAxis:
                lData = dijoystate.lX;
                break;
            
            case eYAxis:
                lData = dijoystate.lY;
                break;
            }
            m_curAxisValues[index] = lData;
        }
    }
    return TRUE;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::DIEnumDeviceObjectsProc

Description:

    DirectInput will call this (by way of DIEnumDeviceObjectsProc) one time for
    each of the objects (buttons, axes, etc) on the controller.

Arguments:

    LPCDIDEVICEOBJECTINSTANCE pDIDOI        - The object being enumerated

Return Value:

    TRUE to continue, FALSE to stop

-------------------------------------------------------------------*/
BOOL
CController::DIEnumDeviceObjectsProc(LPCDIDEVICEOBJECTINSTANCE pDIDOI)
{
    if ((LOBYTE(LOWORD(pDIDOI->dwType)) & DIDFT_AXIS) != 0)
    {
        if (IsEqualGUID(pDIDOI->guidType, GUID_XAxis))
            m_axisIndices[m_nAxes].eaxis = eXAxis;
        else
            m_axisIndices[m_nAxes].eaxis = eYAxis;

        m_axisIndices[m_nAxes].iAxis = m_nAxes;
        m_nAxes++;
    }
    else if ((LOBYTE(LOWORD(pDIDOI->dwType)) & DIDFT_BUTTON) != 0)
    {
        // USAGE_FIRST_BUTTON is defined in maplusag.h
        m_buttonIndices[pDIDOI->wUsage - USAGE_FIRST_BUTTON] = m_nButtons;
        m_nButtons++;
    }
    else
        DebugOutput(TEXT("Port %d EnumObjects -- UnknownObject 0x%X\n"), m_port, pDIDOI->dwType);

    return(TRUE);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    CController::LightgunExists

Description:

    This is called when an Lightgun device is discovered to be attached to
    the controller.

Arguments:

    GUID        guidLightgun - GUID of the Lightgun device

Return Value:

    None

-------------------------------------------------------------------*/
void
CController::LightgunExists(GUID guidLightgun)
{    
    if (m_plightgun == NULL)
    {
        m_plightgun = new CLightgun(guidLightgun);
        if (m_plightgun == NULL)
            return;
        
        if (m_plightgun->Initialize() == FALSE)
        {
            CLightgun *pLightgunTemp = m_plightgun;

            m_plightgun = NULL;
            delete pLightgunTemp;
            OutputDebugString(TEXT("Error initializing Lightgun\r\n"));

            return;
        }
    }
}
