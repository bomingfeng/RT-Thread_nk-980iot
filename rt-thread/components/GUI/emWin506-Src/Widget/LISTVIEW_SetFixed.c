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
File        : LISTVIEW_SetFixed.c
Purpose     : Implementation of LISTVIEW_SetFixed
---------------------------END-OF-HEADER------------------------------
*/

#include "LISTVIEW_Private.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Public routines
*
**********************************************************************
*/
/*********************************************************************
*
*       LISTVIEW_SetFixed
*/
unsigned LISTVIEW_SetFixed(LISTVIEW_Handle hObj, unsigned Fixed) {
  unsigned FixedOld = 0;
  if (hObj) {
    LISTVIEW_Obj * pObj;
    WM_LOCK();
    pObj = LISTVIEW_LOCK_H(hObj);
    FixedOld = pObj->Fixed;
    if (Fixed != FixedOld) {
      pObj->Fixed = Fixed;
      if (pObj->hHeader) {
        HEADER_SetFixed(pObj->hHeader, Fixed);
      }
      LISTVIEW__InvalidateInsideArea(hObj);
    }
    GUI_UNLOCK_H(pObj);
    WM_UNLOCK();
  }
  return FixedOld;
}

#else                            /* Avoid problems with empty object modules */
  void LISTVIEW_SetFixed_C(void);
  void LISTVIEW_SetFixed_C(void) {}
#endif

/*************************** End of file ****************************/
