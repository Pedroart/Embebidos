/*******************************************************************************
* File Name: irq_EOFF_4.h
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
#if !defined(CY_ISR_irq_EOFF_4_H)
#define CY_ISR_irq_EOFF_4_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void irq_EOFF_4_Start(void);
void irq_EOFF_4_StartEx(cyisraddress address);
void irq_EOFF_4_Stop(void);

CY_ISR_PROTO(irq_EOFF_4_Interrupt);

void irq_EOFF_4_SetVector(cyisraddress address);
cyisraddress irq_EOFF_4_GetVector(void);

void irq_EOFF_4_SetPriority(uint8 priority);
uint8 irq_EOFF_4_GetPriority(void);

void irq_EOFF_4_Enable(void);
uint8 irq_EOFF_4_GetState(void);
void irq_EOFF_4_Disable(void);

void irq_EOFF_4_SetPending(void);
void irq_EOFF_4_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the irq_EOFF_4 ISR. */
#define irq_EOFF_4_INTC_VECTOR            ((reg32 *) irq_EOFF_4__INTC_VECT)

/* Address of the irq_EOFF_4 ISR priority. */
#define irq_EOFF_4_INTC_PRIOR             ((reg8 *) irq_EOFF_4__INTC_PRIOR_REG)

/* Priority of the irq_EOFF_4 interrupt. */
#define irq_EOFF_4_INTC_PRIOR_NUMBER      irq_EOFF_4__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable irq_EOFF_4 interrupt. */
#define irq_EOFF_4_INTC_SET_EN            ((reg32 *) irq_EOFF_4__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the irq_EOFF_4 interrupt. */
#define irq_EOFF_4_INTC_CLR_EN            ((reg32 *) irq_EOFF_4__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the irq_EOFF_4 interrupt state to pending. */
#define irq_EOFF_4_INTC_SET_PD            ((reg32 *) irq_EOFF_4__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the irq_EOFF_4 interrupt. */
#define irq_EOFF_4_INTC_CLR_PD            ((reg32 *) irq_EOFF_4__INTC_CLR_PD_REG)


#endif /* CY_ISR_irq_EOFF_4_H */


/* [] END OF FILE */
