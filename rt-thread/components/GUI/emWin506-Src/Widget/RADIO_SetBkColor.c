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
File        : RADIO_SetBkColor.c
Purpose     : Implementation of RADIO_SetBkColor
---------------------------END-OF-HEADER------------------------------
*/

#include "RADIO_Private.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       RADIO_SetBkColor
*/
void RADIO_SetBkColor(RADIO_Handle hObj, GUI_COLOR Color) {
  if (hObj) {
    RADIO_Obj* pObj;
    WM_LOCK();
    pObj = RADIO_LOCK_H(hObj);
    if (Color != pObj->Props.BkColor) {
      pObj->Props.BkColor = Color;
      #if WM_SUPPORT_TRANSPARENCY
        if (Color <= 0xFFFFFF) {
          WM_SetTransState(hObj, 0);
        } else {
          WM_SetTransState(hObj, WM_CF_HASTRANS);
        }
      #endif
      WM_InvalidateWindow(hObj);
    }
    GUI_UNLOCK_H(pObj);
    WM_UNLOCK();
  }
}

#else  /* avoid empty object files */

void RADIO_SetBkColor_c(void);
void RADIO_SetBkColor_c(void) {}

#endif  /* #if GUI_WINSUPPORT */

/************************* end of file ******************************/
