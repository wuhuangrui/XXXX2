/*
 *********************************************************************************************************
 *                                                uC/GUI
 *                        Universal graphic software for embedded applications
 *
 *                       (c) Copyright 2002, Micrium Inc., Weston, FL
 *                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
 *
 *              �C/GUI is protected by international copyright laws. Knowledge of the
 *              source code may not be used to write a similar product. This file may
 *              only be used in accordance with a license and should not be redistributed
 *              in any way. We appreciate your understanding and fairness.
 *
 ----------------------------------------------------------------------
 File        : GUI_X.C
 Purpose     : Config / System dependent externals for GUI
 ---------------------------END-OF-HEADER------------------------------
 */
//#include "sysarch.h"
//#include <pthread.h>
//#include "common.h"
#include "stdafx.h"

#include "GUI.H"
#include "GUI_X.h"


/*********************************************************************
 *
 *       Global data
 */
volatile int OS_TimeMS;

/*********************************************************************
 *
 *      Timing:
 *                 GUI_X_GetTime()
 *                 GUI_X_Delay(int)

 Some timing dependent routines of emWin require a GetTime
 and delay function. Default time unit (tick), normally is
 1 ms.
 */

int GUI_X_GetTime(void)
{
	return OS_TimeMS;
}

void GUI_X_Delay(int ms)
{
	//Sleep(ms);
}

/*********************************************************************
 *
 *       GUI_X_Init()
 *
 * Note:
 *     GUI_X_Init() is called from GUI_Init is a possibility to init
 *     some hardware which needs to be up and running before the GUI.
 *     If not required, leave this routine blank.
 */
//static pthread_mutex_t GUI_mtx;
//static C_OS_SEM GUI_mtx;
void GUI_X_Init(void)
{
	//pthread_mutex_init(&GUI_mtx, NULL);
	//GUI_mtx = C_OSSemCreate(1);
}

/*********************************************************************
 *
 *       GUI_X_ExecIdle
 *
 * Note:
 *  Called if WM is in idle state
 */

void GUI_X_ExecIdle(void)
{
}

/*********************************************************************
 *
 *      Logging: Publics referenced by upper layers
 *
 Note:
 These routines are needed only in higher debug levels.
 */

void GUI_X_Log(const char *s)
{
}

void GUI_X_Lock(void)
{
	//pthread_mutex_lock(&GUI_mtx);
	//C_OSSemPend(GUI_mtx);
}
void GUI_X_Unlock(void)
{
	//pthread_mutex_unlock(&GUI_mtx);
	//C_OSSemPost(GUI_mtx);
}
unsigned int GUI_X_GetTaskId(void)
{
	return 0x0;
}
void GUI_X_Warn(const char *s)
{
}
void GUI_X_ErrorOut(const char *s)
{
}

void GUI_X_InitOS(void)
{

}

