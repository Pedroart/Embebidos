/*******************************************************************************
* File Name: e4.h  
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

#if !defined(CY_PINS_e4_H) /* Pins e4_H */
#define CY_PINS_e4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "e4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 e4__PORT == 15 && ((e4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    e4_Write(uint8 value);
void    e4_SetDriveMode(uint8 mode);
uint8   e4_ReadDataReg(void);
uint8   e4_Read(void);
void    e4_SetInterruptMode(uint16 position, uint16 mode);
uint8   e4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the e4_SetDriveMode() function.
     *  @{
     */
        #define e4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define e4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define e4_DM_RES_UP          PIN_DM_RES_UP
        #define e4_DM_RES_DWN         PIN_DM_RES_DWN
        #define e4_DM_OD_LO           PIN_DM_OD_LO
        #define e4_DM_OD_HI           PIN_DM_OD_HI
        #define e4_DM_STRONG          PIN_DM_STRONG
        #define e4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define e4_MASK               e4__MASK
#define e4_SHIFT              e4__SHIFT
#define e4_WIDTH              1u

/* Interrupt constants */
#if defined(e4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in e4_SetInterruptMode() function.
     *  @{
     */
        #define e4_INTR_NONE      (uint16)(0x0000u)
        #define e4_INTR_RISING    (uint16)(0x0001u)
        #define e4_INTR_FALLING   (uint16)(0x0002u)
        #define e4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define e4_INTR_MASK      (0x01u) 
#endif /* (e4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define e4_PS                     (* (reg8 *) e4__PS)
/* Data Register */
#define e4_DR                     (* (reg8 *) e4__DR)
/* Port Number */
#define e4_PRT_NUM                (* (reg8 *) e4__PRT) 
/* Connect to Analog Globals */                                                  
#define e4_AG                     (* (reg8 *) e4__AG)                       
/* Analog MUX bux enable */
#define e4_AMUX                   (* (reg8 *) e4__AMUX) 
/* Bidirectional Enable */                                                        
#define e4_BIE                    (* (reg8 *) e4__BIE)
/* Bit-mask for Aliased Register Access */
#define e4_BIT_MASK               (* (reg8 *) e4__BIT_MASK)
/* Bypass Enable */
#define e4_BYP                    (* (reg8 *) e4__BYP)
/* Port wide control signals */                                                   
#define e4_CTL                    (* (reg8 *) e4__CTL)
/* Drive Modes */
#define e4_DM0                    (* (reg8 *) e4__DM0) 
#define e4_DM1                    (* (reg8 *) e4__DM1)
#define e4_DM2                    (* (reg8 *) e4__DM2) 
/* Input Buffer Disable Override */
#define e4_INP_DIS                (* (reg8 *) e4__INP_DIS)
/* LCD Common or Segment Drive */
#define e4_LCD_COM_SEG            (* (reg8 *) e4__LCD_COM_SEG)
/* Enable Segment LCD */
#define e4_LCD_EN                 (* (reg8 *) e4__LCD_EN)
/* Slew Rate Control */
#define e4_SLW                    (* (reg8 *) e4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define e4_PRTDSI__CAPS_SEL       (* (reg8 *) e4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define e4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) e4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define e4_PRTDSI__OE_SEL0        (* (reg8 *) e4__PRTDSI__OE_SEL0) 
#define e4_PRTDSI__OE_SEL1        (* (reg8 *) e4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define e4_PRTDSI__OUT_SEL0       (* (reg8 *) e4__PRTDSI__OUT_SEL0) 
#define e4_PRTDSI__OUT_SEL1       (* (reg8 *) e4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define e4_PRTDSI__SYNC_OUT       (* (reg8 *) e4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(e4__SIO_CFG)
    #define e4_SIO_HYST_EN        (* (reg8 *) e4__SIO_HYST_EN)
    #define e4_SIO_REG_HIFREQ     (* (reg8 *) e4__SIO_REG_HIFREQ)
    #define e4_SIO_CFG            (* (reg8 *) e4__SIO_CFG)
    #define e4_SIO_DIFF           (* (reg8 *) e4__SIO_DIFF)
#endif /* (e4__SIO_CFG) */

/* Interrupt Registers */
#if defined(e4__INTSTAT)
    #define e4_INTSTAT            (* (reg8 *) e4__INTSTAT)
    #define e4_SNAP               (* (reg8 *) e4__SNAP)
    
	#define e4_0_INTTYPE_REG 		(* (reg8 *) e4__0__INTTYPE)
#endif /* (e4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_e4_H */


/* [] END OF FILE */
