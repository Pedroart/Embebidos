/*******************************************************************************
* File Name: irq_Activacion.h
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
#if !defined(CY_ISR_irq_Activacion_H)
#define CY_ISR_irq_Activacion_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void irq_Activacion_Start(void);
void irq_Activacion_StartEx(cyisraddress address);
void irq_Activacion_Stop(void);

CY_ISR_PROTO(irq_Activacion_Interrupt);

void irq_Activacion_SetVector(cyisraddress address);
cyisraddress irq_Activacion_GetVector(void);

void irq_Activacion_SetPriority(uint8 priority);
uint8 irq_Activacion_GetPriority(void);

void irq_Activacion_Enable(void);
uint8 irq_Activacion_GetState(void);
void irq_Activacion_Disable(void);

void irq_Activacion_SetPending(void);
void irq_Activacion_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the irq_Activacion ISR. */
#define irq_Activacion_INTC_VECTOR            ((reg32 *) irq_Activacion__INTC_VECT)

/* Address of the irq_Activacion ISR priority. */
#define irq_Activacion_INTC_PRIOR             ((reg8 *) irq_Activacion__INTC_PRIOR_REG)

/* Priority of the irq_Activacion interrupt. */
#define irq_Activacion_INTC_PRIOR_NUMBER      irq_Activacion__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable irq_Activacion interrupt. */
#define irq_Activacion_INTC_SET_EN            ((reg32 *) irq_Activacion__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the irq_Activacion interrupt. */
#define irq_Activacion_INTC_CLR_EN            ((reg32 *) irq_Activacion__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the irq_Activacion interrupt state to pending. */
#define irq_Activacion_INTC_SET_PD            ((reg32 *) irq_Activacion__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the irq_Activacion interrupt. */
#define irq_Activacion_INTC_CLR_PD            ((reg32 *) irq_Activacion__INTC_CLR_PD_REG)


#endif /* CY_ISR_irq_Activacion_H */


/* [] END OF FILE */
