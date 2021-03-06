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
File        : GUITOUCH.C
Purpose     : Generic touch screen routines
----------------------------------------------------------------------
*/

#include <string.h>

#include "GUI_Private.h"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static GUI_PID_STATE _State;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_TOUCH_GetState
*/
int GUI_TOUCH_GetState(GUI_PID_STATE *pState) {
  *pState = _State;
  return (_State.Pressed != 0) ? 1 : 0;
}

/*********************************************************************
*
*       GUI_TOUCH_StoreStateEx
*/
void GUI_TOUCH_StoreStateEx(const GUI_PID_STATE *pState) {
  if (memcmp(pState, &_State, sizeof(_State))) {
    _State = *pState;
    GUI_PID_StoreState(pState);
  }
}

/*************************** End of file ****************************/
