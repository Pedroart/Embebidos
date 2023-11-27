/*******************************************************************************
* File Name: irq_T70m.h
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
#if !defined(CY_ISR_irq_T70m_H)
#define CY_ISR_irq_T70m_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void irq_T70m_Start(void);
void irq_T70m_StartEx(cyisraddress address);
void irq_T70m_Stop(void);

CY_ISR_PROTO(irq_T70m_Interrupt);

void irq_T70m_SetVector(cyisraddress address);
cyisraddress irq_T70m_GetVector(void);

void irq_T70m_SetPriority(uint8 priority);
uint8 irq_T70m_GetPriority(void);

void irq_T70m_Enable(void);
uint8 irq_T70m_GetState(void);
void irq_T70m_Disable(void);

void irq_T70m_SetPending(void);
void irq_T70m_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the irq_T70m ISR. */
#define irq_T70m_INTC_VECTOR            ((reg32 *) irq_T70m__INTC_VECT)

/* Address of the irq_T70m ISR priority. */
#define irq_T70m_INTC_PRIOR             ((reg8 *) irq_T70m__INTC_PRIOR_REG)

/* Priority of the irq_T70m interrupt. */
#define irq_T70m_INTC_PRIOR_NUMBER      irq_T70m__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable irq_T70m interrupt. */
#define irq_T70m_INTC_SET_EN            ((reg32 *) irq_T70m__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the irq_T70m interrupt. */
#define irq_T70m_INTC_CLR_EN            ((reg32 *) irq_T70m__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the irq_T70m interrupt state to pending. */
#define irq_T70m_INTC_SET_PD            ((reg32 *) irq_T70m__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the irq_T70m interrupt. */
#define irq_T70m_INTC_CLR_PD            ((reg32 *) irq_T70m__INTC_CLR_PD_REG)


#endif /* CY_ISR_irq_T70m_H */


/* [] END OF FILE */
