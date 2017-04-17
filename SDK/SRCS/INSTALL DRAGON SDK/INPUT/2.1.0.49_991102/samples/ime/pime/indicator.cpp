/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Copyright (c) 1998 Microsoft Corporation

Module Name:

    indicator.cxx

Abstract:

Environment:

    Runs on Dreamcast under Windows CE.


-------------------------------------------------------------------*/


#include "precomp.hpp"


LPDIRECTDRAWSURFACE g_lpddsIndicators = NULL;
KeyboardState       g_swkeybdstate;
KeyboardState       g_hwkeybdstate;
KeyboardState       *g_pkeybdstateCurrent = &g_hwkeybdstate;


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    SetIMEState

Description:

Return Value:

    None.

-------------------------------------------------------------------*/
void
SetIMEState
    (
    KeyboardState* pnewkeybdstate
    )
{
    HIMC            hIMC;
    DWORD           dwConvMode;
    DWORD           dwSentenceMode;

    if (!(hIMC = ImmGetContext (g_hwndEditBox)))
        return;

    ImmSetOpenStatus (hIMC, pnewkeybdstate->fIMEOn);

    ImmGetConversionStatus (hIMC, &dwConvMode, &dwSentenceMode);

    dwConvMode = 0;

    if ((pnewkeybdstate->keyboard == HIRAGANA) || (pnewkeybdstate->keyboard == KATAKANA))
    {
        dwConvMode |= IME_CMODE_JAPANESE;

        if (pnewkeybdstate->keyboard == KATAKANA)
            dwConvMode |= IME_CMODE_KATAKANA;
    }

    if ((!pnewkeybdstate->fHalfWidth) && (pnewkeybdstate->keyboard != ROMANJI))
        dwConvMode |= IME_CMODE_FULLSHAPE;

    if ((pnewkeybdstate->fDoubleWidth) && (pnewkeybdstate->keyboard == ROMANJI))
        dwConvMode |= IME_CMODE_FULLSHAPE;

    if ((pnewkeybdstate->fRKCOn) || (pnewkeybdstate->keyboard == ROMANJI))
        dwConvMode |= IME_CMODE_ROMAN;

    ImmSetConversionStatus (hIMC, dwConvMode, dwSentenceMode);

    ImmReleaseContext (g_hwndEditBox, hIMC);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    ResetSoftKeybdState

Description:

Return Value:

    None.

-------------------------------------------------------------------*/
void
ResetSoftKeybdState
    (
    void
    )
{
    g_swkeybdstate.fIMEOn = TRUE;
    g_swkeybdstate.fRKCOn = FALSE;
    g_swkeybdstate.fCapsOn = TRUE;
    g_swkeybdstate.keyboard = HIRAGANA;
    g_swkeybdstate.fHalfWidth = FALSE;
    g_swkeybdstate.fHalfHeight = FALSE;
    g_swkeybdstate.fDoubleWidth = FALSE;

    SetIMEState (&g_swkeybdstate);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    ResetHardKeybdState

Description:

Return Value:

    None.

-------------------------------------------------------------------*/
void
ResetHardKeybdState
    (
    void
    )
{
    g_hwkeybdstate.fIMEOn = FALSE;
    g_hwkeybdstate.fRKCOn = TRUE;
    g_hwkeybdstate.fCapsOn = GetKeyState(VK_CAPITAL) & 0x01;
    g_hwkeybdstate.keyboard = HIRAGANA;
    g_hwkeybdstate.fHalfWidth = FALSE;
    g_hwkeybdstate.fHalfHeight = FALSE;
    g_hwkeybdstate.fDoubleWidth = FALSE;

    SetIMEState (&g_hwkeybdstate);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    IndicatorCreate

Description:

Return Value:

    TRUE on success, FALSE on failure.

-------------------------------------------------------------------*/
BOOL
IndicatorCreate
    (
    void
    )
{
    g_lpddsIndicators = DDUtilLoadBitmap (g_hinstApp, g_lpdd, INDICATOR_BITMAP_NAME);

    if (g_fHardwareKeyboardPresent)
        ResetHardKeybdState ();
    else
        ResetSoftKeybdState ();

    return (g_lpddsIndicators != NULL);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    IndicatorDestroy

Description:

Return Value:

    none

-------------------------------------------------------------------*/
void
IndicatorDestroy
    (
    void
    )
{
    // release the offscreen surface
    if (g_lpddsIndicators) 
        g_lpddsIndicators->Release();
 
} // IndicatorDestroy


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Function:

    IndicatorBlt

Description:

    This function blits the editbox to the back buffer.

Return Value:

    none

-------------------------------------------------------------------*/
void
IndicatorBlt
    (
    LPDIRECTDRAWSURFACE lpDDSBack
    )
{
    RECT            rc;
    KeyboardState   keybdstate;

    keybdstate = *g_pkeybdstateCurrent;

    if (lpDDSBack)
    {
        // Black border around indicator bar.
        DDrawFillRect (lpDDSBack, INDICATOR_LEFTEDGE - 2, INDICATOR_TOPEDGE - 2,
            INDICATOR_WIDTH * 3 + 5, INDICATOR_HEIGHT + 4, BLACK);

        rc.top = 0;
        rc.bottom = INDICATOR_HEIGHT;

        // IME On/Off indicator
        rc.left = keybdstate.fIMEOn ? INDICATOR_IMEON : INDICATOR_IMEOFF;
        rc.left *= INDICATOR_WIDTH;
        rc.right = rc.left + INDICATOR_WIDTH;
        lpDDSBack->BltFast (INDICATOR_LEFTEDGE, INDICATOR_TOPEDGE,
            g_lpddsIndicators, &rc, DDBLTFAST_NOCOLORKEY | DDBLTFAST_WAIT);

        // RKC On/Off indicator
        rc.left = ((keybdstate.fRKCOn) && (keybdstate.keyboard != ROMANJI)) ? 
            INDICATOR_RKCON : INDICATOR_RKCOFF;
        rc.left *= INDICATOR_WIDTH;
        rc.right = rc.left + INDICATOR_WIDTH;
        lpDDSBack->BltFast (INDICATOR_LEFTEDGE + INDICATOR_WIDTH, INDICATOR_TOPEDGE,
            g_lpddsIndicators, &rc, DDBLTFAST_NOCOLORKEY | DDBLTFAST_WAIT);

        // Hira/Kata/Romanji indicator
        switch (keybdstate.keyboard)
        {
            case HIRAGANA:
                rc.left = keybdstate.fHalfHeight ? INDICATOR_HIRAHALFHEIGHT : INDICATOR_HIRA;
                break;
            case KATAKANA:
                rc.left = keybdstate.fHalfHeight ? INDICATOR_KATAHALFHEIGHT : INDICATOR_KATA;
                if (keybdstate.fHalfWidth)
                    rc.left += 2;
                break;
            case ROMANJI:
                rc.left = keybdstate.fCapsOn ? INDICATOR_ENGLISHUPPER : INDICATOR_ENGLISHLOWER;
                if (keybdstate.fDoubleWidth)
                    rc.left += 2;
                break;
        }

        if (!keybdstate.fIMEOn)
            rc.left = keybdstate.fCapsOn ? INDICATOR_ENGLISHUPPER : INDICATOR_ENGLISHLOWER;

        rc.left *= INDICATOR_WIDTH;
        rc.right = rc.left + INDICATOR_WIDTH;
        lpDDSBack->BltFast (INDICATOR_LEFTEDGE + 2 * INDICATOR_WIDTH, INDICATOR_TOPEDGE,
            g_lpddsIndicators, &rc, DDBLTFAST_NOCOLORKEY | DDBLTFAST_WAIT);
    }
} // IndicatorBlt
