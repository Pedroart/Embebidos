/*******************************************************************************
* File Name: t2.h  
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

#if !defined(CY_PINS_t2_H) /* Pins t2_H */
#define CY_PINS_t2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "t2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 t2__PORT == 15 && ((t2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    t2_Write(uint8 value);
void    t2_SetDriveMode(uint8 mode);
uint8   t2_ReadDataReg(void);
uint8   t2_Read(void);
void    t2_SetInterruptMode(uint16 position, uint16 mode);
uint8   t2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the t2_SetDriveMode() function.
     *  @{
     */
        #define t2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define t2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define t2_DM_RES_UP          PIN_DM_RES_UP
        #define t2_DM_RES_DWN         PIN_DM_RES_DWN
        #define t2_DM_OD_LO           PIN_DM_OD_LO
        #define t2_DM_OD_HI           PIN_DM_OD_HI
        #define t2_DM_STRONG          PIN_DM_STRONG
        #define t2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define t2_MASK               t2__MASK
#define t2_SHIFT              t2__SHIFT
#define t2_WIDTH              1u

/* Interrupt constants */
#if defined(t2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in t2_SetInterruptMode() function.
     *  @{
     */
        #define t2_INTR_NONE      (uint16)(0x0000u)
        #define t2_INTR_RISING    (uint16)(0x0001u)
        #define t2_INTR_FALLING   (uint16)(0x0002u)
        #define t2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define t2_INTR_MASK      (0x01u) 
#endif /* (t2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define t2_PS                     (* (reg8 *) t2__PS)
/* Data Register */
#define t2_DR                     (* (reg8 *) t2__DR)
/* Port Number */
#define t2_PRT_NUM                (* (reg8 *) t2__PRT) 
/* Connect to Analog Globals */                                                  
#define t2_AG                     (* (reg8 *) t2__AG)                       
/* Analog MUX bux enable */
#define t2_AMUX                   (* (reg8 *) t2__AMUX) 
/* Bidirectional Enable */                                                        
#define t2_BIE                    (* (reg8 *) t2__BIE)
/* Bit-mask for Aliased Register Access */
#define t2_BIT_MASK               (* (reg8 *) t2__BIT_MASK)
/* Bypass Enable */
#define t2_BYP                    (* (reg8 *) t2__BYP)
/* Port wide control signals */                                                   
#define t2_CTL                    (* (reg8 *) t2__CTL)
/* Drive Modes */
#define t2_DM0                    (* (reg8 *) t2__DM0) 
#define t2_DM1                    (* (reg8 *) t2__DM1)
#define t2_DM2                    (* (reg8 *) t2__DM2) 
/* Input Buffer Disable Override */
#define t2_INP_DIS                (* (reg8 *) t2__INP_DIS)
/* LCD Common or Segment Drive */
#define t2_LCD_COM_SEG            (* (reg8 *) t2__LCD_COM_SEG)
/* Enable Segment LCD */
#define t2_LCD_EN                 (* (reg8 *) t2__LCD_EN)
/* Slew Rate Control */
#define t2_SLW                    (* (reg8 *) t2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define t2_PRTDSI__CAPS_SEL       (* (reg8 *) t2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define t2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) t2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define t2_PRTDSI__OE_SEL0        (* (reg8 *) t2__PRTDSI__OE_SEL0) 
#define t2_PRTDSI__OE_SEL1        (* (reg8 *) t2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define t2_PRTDSI__OUT_SEL0       (* (reg8 *) t2__PRTDSI__OUT_SEL0) 
#define t2_PRTDSI__OUT_SEL1       (* (reg8 *) t2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define t2_PRTDSI__SYNC_OUT       (* (reg8 *) t2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(t2__SIO_CFG)
    #define t2_SIO_HYST_EN        (* (reg8 *) t2__SIO_HYST_EN)
    #define t2_SIO_REG_HIFREQ     (* (reg8 *) t2__SIO_REG_HIFREQ)
    #define t2_SIO_CFG            (* (reg8 *) t2__SIO_CFG)
    #define t2_SIO_DIFF           (* (reg8 *) t2__SIO_DIFF)
#endif /* (t2__SIO_CFG) */

/* Interrupt Registers */
#if defined(t2__INTSTAT)
    #define t2_INTSTAT            (* (reg8 *) t2__INTSTAT)
    #define t2_SNAP               (* (reg8 *) t2__SNAP)
    
	#define t2_0_INTTYPE_REG 		(* (reg8 *) t2__0__INTTYPE)
#endif /* (t2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_t2_H */


/* [] END OF FILE */
