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
File        : MENU_DeleteItem.c
Purpose     : Implementation of menu widget
---------------------------END-OF-HEADER------------------------------
*/

#include "MENU.h"
#include "MENU_Private.h"

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MENU_DeleteItem
*/
void MENU_DeleteItem(MENU_Handle hObj, U16 ItemId) {
  if (hObj) {
    int Index;
    WM_LOCK();
    Index = MENU__FindItem(hObj, ItemId, &hObj);
    if (Index >= 0) {
      MENU_Obj * pObj;
      pObj = MENU_LOCK_H(hObj);
      GUI_ARRAY_DeleteItem(pObj->ItemArray, Index);
      GUI_UNLOCK_H(pObj);
      MENU__ResizeMenu(hObj);
    }
    WM_UNLOCK();
  }
}

#else  /* avoid empty object files */
  void MENU_DeleteItem_C(void) {}
#endif

/*************************** End of file ****************************/
