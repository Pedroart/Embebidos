/*******************************************************************************
* File Name: Clk_100Hz.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clk_100Hz_H)
#define CY_CLOCK_Clk_100Hz_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clk_100Hz_Start(void) ;
void Clk_100Hz_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clk_100Hz_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clk_100Hz_StandbyPower(uint8 state) ;
void Clk_100Hz_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clk_100Hz_GetDividerRegister(void) ;
void Clk_100Hz_SetModeRegister(uint8 modeBitMask) ;
void Clk_100Hz_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clk_100Hz_GetModeRegister(void) ;
void Clk_100Hz_SetSourceRegister(uint8 clkSource) ;
uint8 Clk_100Hz_GetSourceRegister(void) ;
#if defined(Clk_100Hz__CFG3)
void Clk_100Hz_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clk_100Hz_GetPhaseRegister(void) ;
#endif /* defined(Clk_100Hz__CFG3) */

#define Clk_100Hz_Enable()                       Clk_100Hz_Start()
#define Clk_100Hz_Disable()                      Clk_100Hz_Stop()
#define Clk_100Hz_SetDivider(clkDivider)         Clk_100Hz_SetDividerRegister(clkDivider, 1u)
#define Clk_100Hz_SetDividerValue(clkDivider)    Clk_100Hz_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clk_100Hz_SetMode(clkMode)               Clk_100Hz_SetModeRegister(clkMode)
#define Clk_100Hz_SetSource(clkSource)           Clk_100Hz_SetSourceRegister(clkSource)
#if defined(Clk_100Hz__CFG3)
#define Clk_100Hz_SetPhase(clkPhase)             Clk_100Hz_SetPhaseRegister(clkPhase)
#define Clk_100Hz_SetPhaseValue(clkPhase)        Clk_100Hz_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clk_100Hz__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clk_100Hz_CLKEN              (* (reg8 *) Clk_100Hz__PM_ACT_CFG)
#define Clk_100Hz_CLKEN_PTR          ((reg8 *) Clk_100Hz__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clk_100Hz_CLKSTBY            (* (reg8 *) Clk_100Hz__PM_STBY_CFG)
#define Clk_100Hz_CLKSTBY_PTR        ((reg8 *) Clk_100Hz__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clk_100Hz_DIV_LSB            (* (reg8 *) Clk_100Hz__CFG0)
#define Clk_100Hz_DIV_LSB_PTR        ((reg8 *) Clk_100Hz__CFG0)
#define Clk_100Hz_DIV_PTR            ((reg16 *) Clk_100Hz__CFG0)

/* Clock MSB divider configuration register. */
#define Clk_100Hz_DIV_MSB            (* (reg8 *) Clk_100Hz__CFG1)
#define Clk_100Hz_DIV_MSB_PTR        ((reg8 *) Clk_100Hz__CFG1)

/* Mode and source configuration register */
#define Clk_100Hz_MOD_SRC            (* (reg8 *) Clk_100Hz__CFG2)
#define Clk_100Hz_MOD_SRC_PTR        ((reg8 *) Clk_100Hz__CFG2)

#if defined(Clk_100Hz__CFG3)
/* Analog clock phase configuration register */
#define Clk_100Hz_PHASE              (* (reg8 *) Clk_100Hz__CFG3)
#define Clk_100Hz_PHASE_PTR          ((reg8 *) Clk_100Hz__CFG3)
#endif /* defined(Clk_100Hz__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clk_100Hz_CLKEN_MASK         Clk_100Hz__PM_ACT_MSK
#define Clk_100Hz_CLKSTBY_MASK       Clk_100Hz__PM_STBY_MSK

/* CFG2 field masks */
#define Clk_100Hz_SRC_SEL_MSK        Clk_100Hz__CFG2_SRC_SEL_MASK
#define Clk_100Hz_MODE_MASK          (~(Clk_100Hz_SRC_SEL_MSK))

#if defined(Clk_100Hz__CFG3)
/* CFG3 phase mask */
#define Clk_100Hz_PHASE_MASK         Clk_100Hz__CFG3_PHASE_DLY_MASK
#endif /* defined(Clk_100Hz__CFG3) */

#endif /* CY_CLOCK_Clk_100Hz_H */


/* [] END OF FILE */
