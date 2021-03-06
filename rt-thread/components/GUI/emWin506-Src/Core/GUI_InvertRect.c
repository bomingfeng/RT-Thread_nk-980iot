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
File        : GUI_InvertRect.C
Purpose     : Implementation file for GUI_InvertRect
---------------------------END-OF-HEADER------------------------------
*/

#include "GUI_Private.h"

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_InvertRect
*/
void GUI_InvertRect(int x0, int y0, int x1, int y1) {
  GUI_DRAWMODE PrevDraw;
  #if (GUI_WINSUPPORT)
    GUI_RECT r;
  #endif
  GUI_LOCK();
  PrevDraw = GUI_SetDrawMode(GUI_DRAWMODE_XOR);
  #if (GUI_WINSUPPORT)
    WM_ADDORG(x0, y0);
    WM_ADDORG(x1, y1);
    r.x0 = x0;
    r.x1 = x1;
    r.y0 = y0;
    r.y1 = y1;
    WM_ITERATE_START(&r); {
  #endif
  LCD_FillRect(x0, y0, x1, y1);
  #if (GUI_WINSUPPORT)
    } WM_ITERATE_END();
  #endif
  GUI_SetDrawMode(PrevDraw);
  GUI_UNLOCK();
}

/*************************** End of file ****************************/
