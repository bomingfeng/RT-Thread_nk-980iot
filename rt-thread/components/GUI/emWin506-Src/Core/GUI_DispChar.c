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
File        : GUI_DispChar.c
Purpose     : Implementation of optional routines
---------------------------END-OF-HEADER------------------------------
*/

#include "GUI_Private.h"

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       CL_DispChar
*/
#if (GUI_WINSUPPORT)
static void CL_DispChar(U16 c) {
  GUI_RECT r;
  WM_ADDORG(GUI_Context.DispPosX, GUI_Context.DispPosY);
  r.x1 = (r.x0 = GUI_Context.DispPosX) + GUI_GetCharDistX(c) + GUI__GetOverlap(c) - 1;
  r.y1 = (r.y0 = GUI_Context.DispPosY) + GUI_GetFontSizeY()  - 1;
  WM_ITERATE_START(&r) {
    GL_DispChar(c);
  } WM_ITERATE_END();
  if (c != '\n') {
    GUI_Context.DispPosX = r.x1 + 1;
  }
  WM_SUBORG(GUI_Context.DispPosX, GUI_Context.DispPosY);
}
#endif

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_DispChar
*/
void GUI_DispChar(U16 c) {
  GUI_LOCK();
  #if (GUI_WINSUPPORT)
    CL_DispChar(c);
  #else
    GL_DispChar(c);
  #endif
  GUI_UNLOCK();
}

/*********************************************************************
*
*       GUI_DispCharAt
*/
void GUI_DispCharAt(U16 c, I16P x, I16P y) {
  GUI_LOCK();
  GUI_Context.DispPosX = x;
  GUI_Context.DispPosY = y;
  #if (GUI_WINSUPPORT)
    CL_DispChar(c);
  #else
    GL_DispChar(c);
  #endif
  GUI_UNLOCK();
}

/*************************** End of file ****************************/
