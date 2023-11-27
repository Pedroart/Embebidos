/*******************************************************************************
* File Name: Timer_70m_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_70m.h"

static Timer_70m_backupStruct Timer_70m_backup;


/*******************************************************************************
* Function Name: Timer_70m_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_70m_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_70m_SaveConfig(void) 
{
    #if (!Timer_70m_UsingFixedFunction)
        Timer_70m_backup.TimerUdb = Timer_70m_ReadCounter();
        Timer_70m_backup.InterruptMaskValue = Timer_70m_STATUS_MASK;
        #if (Timer_70m_UsingHWCaptureCounter)
            Timer_70m_backup.TimerCaptureCounter = Timer_70m_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_70m_UDB_CONTROL_REG_REMOVED)
            Timer_70m_backup.TimerControlRegister = Timer_70m_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_70m_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_70m_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_70m_RestoreConfig(void) 
{   
    #if (!Timer_70m_UsingFixedFunction)

        Timer_70m_WriteCounter(Timer_70m_backup.TimerUdb);
        Timer_70m_STATUS_MASK =Timer_70m_backup.InterruptMaskValue;
        #if (Timer_70m_UsingHWCaptureCounter)
            Timer_70m_SetCaptureCount(Timer_70m_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_70m_UDB_CONTROL_REG_REMOVED)
            Timer_70m_WriteControlRegister(Timer_70m_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_70m_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_70m_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_70m_Sleep(void) 
{
    #if(!Timer_70m_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_70m_CTRL_ENABLE == (Timer_70m_CONTROL & Timer_70m_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_70m_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_70m_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_70m_Stop();
    Timer_70m_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_70m_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_70m_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_70m_Wakeup(void) 
{
    Timer_70m_RestoreConfig();
    #if(!Timer_70m_UDB_CONTROL_REG_REMOVED)
        if(Timer_70m_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_70m_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
