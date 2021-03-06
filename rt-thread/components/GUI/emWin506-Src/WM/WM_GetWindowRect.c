/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2010  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.06 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : WM_GetWindowRect.C
Purpose     : Windows manager, submodule
----------------------------------------------------------------------
*/

#include "GUI_Private.h"
#include "WM_Intern.h"

#if GUI_WINSUPPORT    /* If 0, WM will not generate any code */
#include "GUI_Debug.h"
#define WM_DEBUG_LEVEL 1

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       WM_GetWindowRect
*
* Returns the window rect in screen (desktop) coordinates.
*/
void WM_GetWindowRect(GUI_RECT* pRect) {
  WM_HWIN hWin;
  WM_LOCK();
  if (pRect) {
    WM_Obj* pWin;
    #if WM_SUPPORT_TRANSPARENCY
      hWin = WM__hATransWindow ? WM__hATransWindow : GUI_Context.hAWin;
    #else
      hWin = GUI_Context.hAWin;
    #endif
    pWin = WM_HANDLE2PTR(hWin);
    *pRect = pWin->Rect;
  }
  WM_UNLOCK();
}

/*********************************************************************
*
*       WM_GetWindowRectEx
*/
void WM_GetWindowRectEx(WM_HWIN hWin, GUI_RECT * pRect) {
  if (hWin && pRect) {
    WM_Obj * pWin;
    WM_LOCK();
    pWin = WM_HANDLE2PTR(hWin);
    if (pWin) {
      *pRect = pWin->Rect;
    }
    WM_UNLOCK();
  }
}

#else
  void WM_GetWindowRect(void) {} /* avoid empty object files */
#endif   /* GUI_WINSUPPORT */

/*************************** End of file ****************************/
