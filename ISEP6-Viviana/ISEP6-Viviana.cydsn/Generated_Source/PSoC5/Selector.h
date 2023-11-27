/*******************************************************************************
* File Name: Selector.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Selector_H) /* Pins Selector_H */
#define CY_PINS_Selector_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Selector_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Selector__PORT == 15 && ((Selector__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Selector_Write(uint8 value);
void    Selector_SetDriveMode(uint8 mode);
uint8   Selector_ReadDataReg(void);
uint8   Selector_Read(void);
void    Selector_SetInterruptMode(uint16 position, uint16 mode);
uint8   Selector_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Selector_SetDriveMode() function.
     *  @{
     */
        #define Selector_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Selector_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Selector_DM_RES_UP          PIN_DM_RES_UP
        #define Selector_DM_RES_DWN         PIN_DM_RES_DWN
        #define Selector_DM_OD_LO           PIN_DM_OD_LO
        #define Selector_DM_OD_HI           PIN_DM_OD_HI
        #define Selector_DM_STRONG          PIN_DM_STRONG
        #define Selector_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Selector_MASK               Selector__MASK
#define Selector_SHIFT              Selector__SHIFT
#define Selector_WIDTH              1u

/* Interrupt constants */
#if defined(Selector__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Selector_SetInterruptMode() function.
     *  @{
     */
        #define Selector_INTR_NONE      (uint16)(0x0000u)
        #define Selector_INTR_RISING    (uint16)(0x0001u)
        #define Selector_INTR_FALLING   (uint16)(0x0002u)
        #define Selector_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Selector_INTR_MASK      (0x01u) 
#endif /* (Selector__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Selector_PS                     (* (reg8 *) Selector__PS)
/* Data Register */
#define Selector_DR                     (* (reg8 *) Selector__DR)
/* Port Number */
#define Selector_PRT_NUM                (* (reg8 *) Selector__PRT) 
/* Connect to Analog Globals */                                                  
#define Selector_AG                     (* (reg8 *) Selector__AG)                       
/* Analog MUX bux enable */
#define Selector_AMUX                   (* (reg8 *) Selector__AMUX) 
/* Bidirectional Enable */                                                        
#define Selector_BIE                    (* (reg8 *) Selector__BIE)
/* Bit-mask for Aliased Register Access */
#define Selector_BIT_MASK               (* (reg8 *) Selector__BIT_MASK)
/* Bypass Enable */
#define Selector_BYP                    (* (reg8 *) Selector__BYP)
/* Port wide control signals */                                                   
#define Selector_CTL                    (* (reg8 *) Selector__CTL)
/* Drive Modes */
#define Selector_DM0                    (* (reg8 *) Selector__DM0) 
#define Selector_DM1                    (* (reg8 *) Selector__DM1)
#define Selector_DM2                    (* (reg8 *) Selector__DM2) 
/* Input Buffer Disable Override */
#define Selector_INP_DIS                (* (reg8 *) Selector__INP_DIS)
/* LCD Common or Segment Drive */
#define Selector_LCD_COM_SEG            (* (reg8 *) Selector__LCD_COM_SEG)
/* Enable Segment LCD */
#define Selector_LCD_EN                 (* (reg8 *) Selector__LCD_EN)
/* Slew Rate Control */
#define Selector_SLW                    (* (reg8 *) Selector__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Selector_PRTDSI__CAPS_SEL       (* (reg8 *) Selector__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Selector_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Selector__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Selector_PRTDSI__OE_SEL0        (* (reg8 *) Selector__PRTDSI__OE_SEL0) 
#define Selector_PRTDSI__OE_SEL1        (* (reg8 *) Selector__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Selector_PRTDSI__OUT_SEL0       (* (reg8 *) Selector__PRTDSI__OUT_SEL0) 
#define Selector_PRTDSI__OUT_SEL1       (* (reg8 *) Selector__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Selector_PRTDSI__SYNC_OUT       (* (reg8 *) Selector__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Selector__SIO_CFG)
    #define Selector_SIO_HYST_EN        (* (reg8 *) Selector__SIO_HYST_EN)
    #define Selector_SIO_REG_HIFREQ     (* (reg8 *) Selector__SIO_REG_HIFREQ)
    #define Selector_SIO_CFG            (* (reg8 *) Selector__SIO_CFG)
    #define Selector_SIO_DIFF           (* (reg8 *) Selector__SIO_DIFF)
#endif /* (Selector__SIO_CFG) */

/* Interrupt Registers */
#if defined(Selector__INTSTAT)
    #define Selector_INTSTAT            (* (reg8 *) Selector__INTSTAT)
    #define Selector_SNAP               (* (reg8 *) Selector__SNAP)
    
	#define Selector_0_INTTYPE_REG 		(* (reg8 *) Selector__0__INTTYPE)
#endif /* (Selector__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Selector_H */


/* [] END OF FILE */
