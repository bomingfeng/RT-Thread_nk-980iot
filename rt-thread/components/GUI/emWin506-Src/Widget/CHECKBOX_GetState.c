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
File        : CHECKBOX_GetState.c
Purpose     : Implementation of CHECKBOX_GetState
---------------------------END-OF-HEADER------------------------------
*/

#include "CHECKBOX_Private.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Exported routines
*
**********************************************************************
*/
/*********************************************************************
*
*       CHECKBOX_GetState
*/
int CHECKBOX_GetState(CHECKBOX_Handle hObj) {
  int Result = 0;
  CHECKBOX_Obj * pObj;
  if (hObj) {
    WM_LOCK();
    pObj = CHECKBOX_LOCK_H(hObj);
    Result = pObj->CurrentState;
    GUI_UNLOCK_H(pObj);
    WM_UNLOCK();
  }
  return Result;
}

#else                            /* Avoid problems with empty object modules */
  void CHECKBOX_GetState_C(void);
  void CHECKBOX_GetState_C(void) {}
#endif
