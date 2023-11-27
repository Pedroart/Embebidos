/*******************************************************************************
* File Name: t4.h  
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

#if !defined(CY_PINS_t4_H) /* Pins t4_H */
#define CY_PINS_t4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "t4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 t4__PORT == 15 && ((t4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    t4_Write(uint8 value);
void    t4_SetDriveMode(uint8 mode);
uint8   t4_ReadDataReg(void);
uint8   t4_Read(void);
void    t4_SetInterruptMode(uint16 position, uint16 mode);
uint8   t4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the t4_SetDriveMode() function.
     *  @{
     */
        #define t4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define t4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define t4_DM_RES_UP          PIN_DM_RES_UP
        #define t4_DM_RES_DWN         PIN_DM_RES_DWN
        #define t4_DM_OD_LO           PIN_DM_OD_LO
        #define t4_DM_OD_HI           PIN_DM_OD_HI
        #define t4_DM_STRONG          PIN_DM_STRONG
        #define t4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define t4_MASK               t4__MASK
#define t4_SHIFT              t4__SHIFT
#define t4_WIDTH              1u

/* Interrupt constants */
#if defined(t4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in t4_SetInterruptMode() function.
     *  @{
     */
        #define t4_INTR_NONE      (uint16)(0x0000u)
        #define t4_INTR_RISING    (uint16)(0x0001u)
        #define t4_INTR_FALLING   (uint16)(0x0002u)
        #define t4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define t4_INTR_MASK      (0x01u) 
#endif /* (t4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define t4_PS                     (* (reg8 *) t4__PS)
/* Data Register */
#define t4_DR                     (* (reg8 *) t4__DR)
/* Port Number */
#define t4_PRT_NUM                (* (reg8 *) t4__PRT) 
/* Connect to Analog Globals */                                                  
#define t4_AG                     (* (reg8 *) t4__AG)                       
/* Analog MUX bux enable */
#define t4_AMUX                   (* (reg8 *) t4__AMUX) 
/* Bidirectional Enable */                                                        
#define t4_BIE                    (* (reg8 *) t4__BIE)
/* Bit-mask for Aliased Register Access */
#define t4_BIT_MASK               (* (reg8 *) t4__BIT_MASK)
/* Bypass Enable */
#define t4_BYP                    (* (reg8 *) t4__BYP)
/* Port wide control signals */                                                   
#define t4_CTL                    (* (reg8 *) t4__CTL)
/* Drive Modes */
#define t4_DM0                    (* (reg8 *) t4__DM0) 
#define t4_DM1                    (* (reg8 *) t4__DM1)
#define t4_DM2                    (* (reg8 *) t4__DM2) 
/* Input Buffer Disable Override */
#define t4_INP_DIS                (* (reg8 *) t4__INP_DIS)
/* LCD Common or Segment Drive */
#define t4_LCD_COM_SEG            (* (reg8 *) t4__LCD_COM_SEG)
/* Enable Segment LCD */
#define t4_LCD_EN                 (* (reg8 *) t4__LCD_EN)
/* Slew Rate Control */
#define t4_SLW                    (* (reg8 *) t4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define t4_PRTDSI__CAPS_SEL       (* (reg8 *) t4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define t4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) t4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define t4_PRTDSI__OE_SEL0        (* (reg8 *) t4__PRTDSI__OE_SEL0) 
#define t4_PRTDSI__OE_SEL1        (* (reg8 *) t4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define t4_PRTDSI__OUT_SEL0       (* (reg8 *) t4__PRTDSI__OUT_SEL0) 
#define t4_PRTDSI__OUT_SEL1       (* (reg8 *) t4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define t4_PRTDSI__SYNC_OUT       (* (reg8 *) t4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(t4__SIO_CFG)
    #define t4_SIO_HYST_EN        (* (reg8 *) t4__SIO_HYST_EN)
    #define t4_SIO_REG_HIFREQ     (* (reg8 *) t4__SIO_REG_HIFREQ)
    #define t4_SIO_CFG            (* (reg8 *) t4__SIO_CFG)
    #define t4_SIO_DIFF           (* (reg8 *) t4__SIO_DIFF)
#endif /* (t4__SIO_CFG) */

/* Interrupt Registers */
#if defined(t4__INTSTAT)
    #define t4_INTSTAT            (* (reg8 *) t4__INTSTAT)
    #define t4_SNAP               (* (reg8 *) t4__SNAP)
    
	#define t4_0_INTTYPE_REG 		(* (reg8 *) t4__0__INTTYPE)
#endif /* (t4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_t4_H */


/* [] END OF FILE */
