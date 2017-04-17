/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Copyright (c) 1999 Microsoft Corporation

Module Name:

    VQSurfaces.hpp

Abstract:

   Include file for VQSurfaces

-------------------------------------------------------------------*/

// ++++ Include Files +++++++++++++++++++++++++++++++++++++++++++++++

#include <tchar.h>
#include <windows.h>
#include <ddraw.h>

// ++++ Enumerated Types ++++++++++++++++++++++++++++++++++++++++++++

// Output types
enum toutputlevel { OUTPUT_ALL = 0, OUTPUT_FAILURESONLY };

// ++++ Types +++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Error type
typedef int terr;

// ++++ Defines +++++++++++++++++++++++++++++++++++++++++++++++++++++

// ++++ Global Variables ++++++++++++++++++++++++++++++++++++++++++++

// BasicDDraw.cpp variables
extern HWND                g_hwndApp;                   // HWND of the application
extern HINSTANCE           g_hinst;                     // HINSTANCE of the application

// Error.cpp variables
extern toutputlevel g_outputlevel;                      // Amount of detail in error messages
extern terr g_errLast;                                  // Error return code of last function

// DDUtil.cpp variables
extern LPDIRECTDRAW        g_pdd;                       // The DirectDraw object
extern LPDIRECTDRAWSURFACE g_pddsPrimary;               // Primary directdraw surface
extern LPDIRECTDRAWSURFACE g_pddsBack;                  // Back buffer directdraw surface

// ++++ Global Functions ++++++++++++++++++++++++++++++++++++++++++++

// BasicDDraw.cpp functions
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

// DDUtil.cpp functions
void FlipBuffers();
BOOL InitDirectDraw();
LPDIRECTDRAWSURFACE LoadVQToDDS(LPTSTR tszVQImage);
HRESULT GetSurfaceDesc(LPDDSURFACEDESC pddsurfdesc, LPDIRECTDRAWSURFACE pddsurf);

// Error.cpp functions
BOOL CheckError(TCHAR *tszErr);
void RetailOutput(TCHAR *tszErr, ...);
#ifdef DEBUG
void DebugOutput(TCHAR *tszErr, ...);
#else
__inline void DebugOutput(TCHAR *tszErr, ...) {};
#endif
