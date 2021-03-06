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
File        : WM_GetWindowSize.c
Purpose     : Implementation of WM_GetWindowSizeX,Y
----------------------------------------------------------------------
*/

#include "WM_Intern.h"

#if GUI_WINSUPPORT    /* If 0, WM will not generate any code */

/*********************************************************************
*
*       Static routines
*
**********************************************************************
*/
/*********************************************************************
*
*       _GetDefaultWin

  When drawing, we have to start at the bottom window !
*/
static WM_HWIN _GetDefaultWin(WM_HWIN hWin) {
  if (!hWin)
    hWin = WM_GetActiveWindow();
  return hWin;
}

/*********************************************************************
*
*       Module internal routines
*
**********************************************************************
*/
/*********************************************************************
*
*       WM__GetWindowSizeX

  Return width of window in pixels
*/
int WM__GetWindowSizeX(const WM_Obj* pWin) {
  return pWin->Rect.x1 - pWin->Rect.x0 +1;
}

/*********************************************************************
*
*       WM__GetWindowSizeY

  Return height of window in pixels
*/
int WM__GetWindowSizeY(const WM_Obj* pWin) {
  return pWin->Rect.y1 - pWin->Rect.y0 +1;
}

/*********************************************************************
*
*      Public API code
*
**********************************************************************
*/
/*********************************************************************
*
*       WM_GetWindowSizeX

  Return width of window in pixels
*/
int WM_GetWindowSizeX(WM_HWIN hWin) {
  int r;
  WM_Obj* pWin;
  WM_LOCK();
  hWin = _GetDefaultWin(hWin);
  pWin = WM_H2P(hWin);
  r = WM__GetWindowSizeX(pWin);
  WM_UNLOCK();
  return r;
}

/*********************************************************************
*
*       WM_GetWindowSizeY

  Return height of window in pixels
*/
int WM_GetWindowSizeY(WM_HWIN hWin) {
  int r;
  WM_Obj* pWin;
  WM_LOCK();
  hWin = _GetDefaultWin(hWin);
  pWin = WM_H2P(hWin);
  r = WM__GetWindowSizeY(pWin);
  WM_UNLOCK();
  return r;
}


#else
  void WM_GetWindowSize_C(void) {} /* avoid empty object files */
#endif   /* GUI_WINSUPPORT */

/*************************** End of file ****************************/
