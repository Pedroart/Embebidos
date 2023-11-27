/*******************************************************************************
* File Name: irq_P.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_irq_P_H)
#define CY_ISR_irq_P_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void irq_P_Start(void);
void irq_P_StartEx(cyisraddress address);
void irq_P_Stop(void);

CY_ISR_PROTO(irq_P_Interrupt);

void irq_P_SetVector(cyisraddress address);
cyisraddress irq_P_GetVector(void);

void irq_P_SetPriority(uint8 priority);
uint8 irq_P_GetPriority(void);

void irq_P_Enable(void);
uint8 irq_P_GetState(void);
void irq_P_Disable(void);

void irq_P_SetPending(void);
void irq_P_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the irq_P ISR. */
#define irq_P_INTC_VECTOR            ((reg32 *) irq_P__INTC_VECT)

/* Address of the irq_P ISR priority. */
#define irq_P_INTC_PRIOR             ((reg8 *) irq_P__INTC_PRIOR_REG)

/* Priority of the irq_P interrupt. */
#define irq_P_INTC_PRIOR_NUMBER      irq_P__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable irq_P interrupt. */
#define irq_P_INTC_SET_EN            ((reg32 *) irq_P__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the irq_P interrupt. */
#define irq_P_INTC_CLR_EN            ((reg32 *) irq_P__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the irq_P interrupt state to pending. */
#define irq_P_INTC_SET_PD            ((reg32 *) irq_P__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the irq_P interrupt. */
#define irq_P_INTC_CLR_PD            ((reg32 *) irq_P__INTC_CLR_PD_REG)


#endif /* CY_ISR_irq_P_H */


/* [] END OF FILE */
