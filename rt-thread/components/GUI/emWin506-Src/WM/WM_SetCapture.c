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
File        : WM_SetCapture.c
Purpose     : Implementation of WM_SetCapture
----------------------------------------------------------------------
*/

#include "WM_Intern.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*        Public data
*
**********************************************************************
*/


/*********************************************************************
*
*        Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       WM__ReleaseCapture
*/
static void WM__ReleaseCapture(void) {
  if (WM__ahCapture[WM__TOUCHED_LAYER]) {
    WM_MESSAGE Msg;
    Msg.MsgId  = WM_CAPTURE_RELEASED;
    WM__SendMessage(WM__ahCapture[WM__TOUCHED_LAYER], &Msg);
    WM__ahCapture[WM__TOUCHED_LAYER] = 0;
  }
}

/*********************************************************************
*
*        Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       WM_SetCapture
*/
void WM_SetCapture(WM_HWIN hObj, int AutoRelease) {
  WM_LOCK();
  if (WM__ahCapture[WM__TOUCHED_LAYER] != hObj) {
    WM__ReleaseCapture();
  }
  WM__ahCapture[WM__TOUCHED_LAYER] = hObj;
  WM__CaptureReleaseAuto = AutoRelease;
  WM_UNLOCK();
}

/*********************************************************************
*
*       WM_ReleaseCapture
*/
void WM_ReleaseCapture(void) {
  WM_LOCK();
  WM__ReleaseCapture();
  WM_UNLOCK();
}

#else
  void WM_SetCapture_c(void) {} /* avoid empty object files */
#endif /* GUI_WINSUPPORT */

/*************************** End of file ****************************/
