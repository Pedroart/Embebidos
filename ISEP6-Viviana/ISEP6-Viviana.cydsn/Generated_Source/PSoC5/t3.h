/*******************************************************************************
* File Name: t3.h  
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

#if !defined(CY_PINS_t3_H) /* Pins t3_H */
#define CY_PINS_t3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "t3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 t3__PORT == 15 && ((t3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    t3_Write(uint8 value);
void    t3_SetDriveMode(uint8 mode);
uint8   t3_ReadDataReg(void);
uint8   t3_Read(void);
void    t3_SetInterruptMode(uint16 position, uint16 mode);
uint8   t3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the t3_SetDriveMode() function.
     *  @{
     */
        #define t3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define t3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define t3_DM_RES_UP          PIN_DM_RES_UP
        #define t3_DM_RES_DWN         PIN_DM_RES_DWN
        #define t3_DM_OD_LO           PIN_DM_OD_LO
        #define t3_DM_OD_HI           PIN_DM_OD_HI
        #define t3_DM_STRONG          PIN_DM_STRONG
        #define t3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define t3_MASK               t3__MASK
#define t3_SHIFT              t3__SHIFT
#define t3_WIDTH              1u

/* Interrupt constants */
#if defined(t3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in t3_SetInterruptMode() function.
     *  @{
     */
        #define t3_INTR_NONE      (uint16)(0x0000u)
        #define t3_INTR_RISING    (uint16)(0x0001u)
        #define t3_INTR_FALLING   (uint16)(0x0002u)
        #define t3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define t3_INTR_MASK      (0x01u) 
#endif /* (t3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define t3_PS                     (* (reg8 *) t3__PS)
/* Data Register */
#define t3_DR                     (* (reg8 *) t3__DR)
/* Port Number */
#define t3_PRT_NUM                (* (reg8 *) t3__PRT) 
/* Connect to Analog Globals */                                                  
#define t3_AG                     (* (reg8 *) t3__AG)                       
/* Analog MUX bux enable */
#define t3_AMUX                   (* (reg8 *) t3__AMUX) 
/* Bidirectional Enable */                                                        
#define t3_BIE                    (* (reg8 *) t3__BIE)
/* Bit-mask for Aliased Register Access */
#define t3_BIT_MASK               (* (reg8 *) t3__BIT_MASK)
/* Bypass Enable */
#define t3_BYP                    (* (reg8 *) t3__BYP)
/* Port wide control signals */                                                   
#define t3_CTL                    (* (reg8 *) t3__CTL)
/* Drive Modes */
#define t3_DM0                    (* (reg8 *) t3__DM0) 
#define t3_DM1                    (* (reg8 *) t3__DM1)
#define t3_DM2                    (* (reg8 *) t3__DM2) 
/* Input Buffer Disable Override */
#define t3_INP_DIS                (* (reg8 *) t3__INP_DIS)
/* LCD Common or Segment Drive */
#define t3_LCD_COM_SEG            (* (reg8 *) t3__LCD_COM_SEG)
/* Enable Segment LCD */
#define t3_LCD_EN                 (* (reg8 *) t3__LCD_EN)
/* Slew Rate Control */
#define t3_SLW                    (* (reg8 *) t3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define t3_PRTDSI__CAPS_SEL       (* (reg8 *) t3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define t3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) t3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define t3_PRTDSI__OE_SEL0        (* (reg8 *) t3__PRTDSI__OE_SEL0) 
#define t3_PRTDSI__OE_SEL1        (* (reg8 *) t3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define t3_PRTDSI__OUT_SEL0       (* (reg8 *) t3__PRTDSI__OUT_SEL0) 
#define t3_PRTDSI__OUT_SEL1       (* (reg8 *) t3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define t3_PRTDSI__SYNC_OUT       (* (reg8 *) t3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(t3__SIO_CFG)
    #define t3_SIO_HYST_EN        (* (reg8 *) t3__SIO_HYST_EN)
    #define t3_SIO_REG_HIFREQ     (* (reg8 *) t3__SIO_REG_HIFREQ)
    #define t3_SIO_CFG            (* (reg8 *) t3__SIO_CFG)
    #define t3_SIO_DIFF           (* (reg8 *) t3__SIO_DIFF)
#endif /* (t3__SIO_CFG) */

/* Interrupt Registers */
#if defined(t3__INTSTAT)
    #define t3_INTSTAT            (* (reg8 *) t3__INTSTAT)
    #define t3_SNAP               (* (reg8 *) t3__SNAP)
    
	#define t3_0_INTTYPE_REG 		(* (reg8 *) t3__0__INTTYPE)
#endif /* (t3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_t3_H */


/* [] END OF FILE */
