/*******************************************************************************
* File Name: e3.h  
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

#if !defined(CY_PINS_e3_H) /* Pins e3_H */
#define CY_PINS_e3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "e3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 e3__PORT == 15 && ((e3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    e3_Write(uint8 value);
void    e3_SetDriveMode(uint8 mode);
uint8   e3_ReadDataReg(void);
uint8   e3_Read(void);
void    e3_SetInterruptMode(uint16 position, uint16 mode);
uint8   e3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the e3_SetDriveMode() function.
     *  @{
     */
        #define e3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define e3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define e3_DM_RES_UP          PIN_DM_RES_UP
        #define e3_DM_RES_DWN         PIN_DM_RES_DWN
        #define e3_DM_OD_LO           PIN_DM_OD_LO
        #define e3_DM_OD_HI           PIN_DM_OD_HI
        #define e3_DM_STRONG          PIN_DM_STRONG
        #define e3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define e3_MASK               e3__MASK
#define e3_SHIFT              e3__SHIFT
#define e3_WIDTH              1u

/* Interrupt constants */
#if defined(e3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in e3_SetInterruptMode() function.
     *  @{
     */
        #define e3_INTR_NONE      (uint16)(0x0000u)
        #define e3_INTR_RISING    (uint16)(0x0001u)
        #define e3_INTR_FALLING   (uint16)(0x0002u)
        #define e3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define e3_INTR_MASK      (0x01u) 
#endif /* (e3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define e3_PS                     (* (reg8 *) e3__PS)
/* Data Register */
#define e3_DR                     (* (reg8 *) e3__DR)
/* Port Number */
#define e3_PRT_NUM                (* (reg8 *) e3__PRT) 
/* Connect to Analog Globals */                                                  
#define e3_AG                     (* (reg8 *) e3__AG)                       
/* Analog MUX bux enable */
#define e3_AMUX                   (* (reg8 *) e3__AMUX) 
/* Bidirectional Enable */                                                        
#define e3_BIE                    (* (reg8 *) e3__BIE)
/* Bit-mask for Aliased Register Access */
#define e3_BIT_MASK               (* (reg8 *) e3__BIT_MASK)
/* Bypass Enable */
#define e3_BYP                    (* (reg8 *) e3__BYP)
/* Port wide control signals */                                                   
#define e3_CTL                    (* (reg8 *) e3__CTL)
/* Drive Modes */
#define e3_DM0                    (* (reg8 *) e3__DM0) 
#define e3_DM1                    (* (reg8 *) e3__DM1)
#define e3_DM2                    (* (reg8 *) e3__DM2) 
/* Input Buffer Disable Override */
#define e3_INP_DIS                (* (reg8 *) e3__INP_DIS)
/* LCD Common or Segment Drive */
#define e3_LCD_COM_SEG            (* (reg8 *) e3__LCD_COM_SEG)
/* Enable Segment LCD */
#define e3_LCD_EN                 (* (reg8 *) e3__LCD_EN)
/* Slew Rate Control */
#define e3_SLW                    (* (reg8 *) e3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define e3_PRTDSI__CAPS_SEL       (* (reg8 *) e3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define e3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) e3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define e3_PRTDSI__OE_SEL0        (* (reg8 *) e3__PRTDSI__OE_SEL0) 
#define e3_PRTDSI__OE_SEL1        (* (reg8 *) e3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define e3_PRTDSI__OUT_SEL0       (* (reg8 *) e3__PRTDSI__OUT_SEL0) 
#define e3_PRTDSI__OUT_SEL1       (* (reg8 *) e3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define e3_PRTDSI__SYNC_OUT       (* (reg8 *) e3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(e3__SIO_CFG)
    #define e3_SIO_HYST_EN        (* (reg8 *) e3__SIO_HYST_EN)
    #define e3_SIO_REG_HIFREQ     (* (reg8 *) e3__SIO_REG_HIFREQ)
    #define e3_SIO_CFG            (* (reg8 *) e3__SIO_CFG)
    #define e3_SIO_DIFF           (* (reg8 *) e3__SIO_DIFF)
#endif /* (e3__SIO_CFG) */

/* Interrupt Registers */
#if defined(e3__INTSTAT)
    #define e3_INTSTAT            (* (reg8 *) e3__INTSTAT)
    #define e3_SNAP               (* (reg8 *) e3__SNAP)
    
	#define e3_0_INTTYPE_REG 		(* (reg8 *) e3__0__INTTYPE)
#endif /* (e3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_e3_H */


/* [] END OF FILE */
