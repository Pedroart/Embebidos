/*******************************************************************************
* File Name: Segmento.h  
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

#if !defined(CY_PINS_Segmento_H) /* Pins Segmento_H */
#define CY_PINS_Segmento_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Segmento_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Segmento__PORT == 15 && ((Segmento__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Segmento_Write(uint8 value);
void    Segmento_SetDriveMode(uint8 mode);
uint8   Segmento_ReadDataReg(void);
uint8   Segmento_Read(void);
void    Segmento_SetInterruptMode(uint16 position, uint16 mode);
uint8   Segmento_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Segmento_SetDriveMode() function.
     *  @{
     */
        #define Segmento_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Segmento_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Segmento_DM_RES_UP          PIN_DM_RES_UP
        #define Segmento_DM_RES_DWN         PIN_DM_RES_DWN
        #define Segmento_DM_OD_LO           PIN_DM_OD_LO
        #define Segmento_DM_OD_HI           PIN_DM_OD_HI
        #define Segmento_DM_STRONG          PIN_DM_STRONG
        #define Segmento_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Segmento_MASK               Segmento__MASK
#define Segmento_SHIFT              Segmento__SHIFT
#define Segmento_WIDTH              8u

/* Interrupt constants */
#if defined(Segmento__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Segmento_SetInterruptMode() function.
     *  @{
     */
        #define Segmento_INTR_NONE      (uint16)(0x0000u)
        #define Segmento_INTR_RISING    (uint16)(0x0001u)
        #define Segmento_INTR_FALLING   (uint16)(0x0002u)
        #define Segmento_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Segmento_INTR_MASK      (0x01u) 
#endif /* (Segmento__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Segmento_PS                     (* (reg8 *) Segmento__PS)
/* Data Register */
#define Segmento_DR                     (* (reg8 *) Segmento__DR)
/* Port Number */
#define Segmento_PRT_NUM                (* (reg8 *) Segmento__PRT) 
/* Connect to Analog Globals */                                                  
#define Segmento_AG                     (* (reg8 *) Segmento__AG)                       
/* Analog MUX bux enable */
#define Segmento_AMUX                   (* (reg8 *) Segmento__AMUX) 
/* Bidirectional Enable */                                                        
#define Segmento_BIE                    (* (reg8 *) Segmento__BIE)
/* Bit-mask for Aliased Register Access */
#define Segmento_BIT_MASK               (* (reg8 *) Segmento__BIT_MASK)
/* Bypass Enable */
#define Segmento_BYP                    (* (reg8 *) Segmento__BYP)
/* Port wide control signals */                                                   
#define Segmento_CTL                    (* (reg8 *) Segmento__CTL)
/* Drive Modes */
#define Segmento_DM0                    (* (reg8 *) Segmento__DM0) 
#define Segmento_DM1                    (* (reg8 *) Segmento__DM1)
#define Segmento_DM2                    (* (reg8 *) Segmento__DM2) 
/* Input Buffer Disable Override */
#define Segmento_INP_DIS                (* (reg8 *) Segmento__INP_DIS)
/* LCD Common or Segment Drive */
#define Segmento_LCD_COM_SEG            (* (reg8 *) Segmento__LCD_COM_SEG)
/* Enable Segment LCD */
#define Segmento_LCD_EN                 (* (reg8 *) Segmento__LCD_EN)
/* Slew Rate Control */
#define Segmento_SLW                    (* (reg8 *) Segmento__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Segmento_PRTDSI__CAPS_SEL       (* (reg8 *) Segmento__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Segmento_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Segmento__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Segmento_PRTDSI__OE_SEL0        (* (reg8 *) Segmento__PRTDSI__OE_SEL0) 
#define Segmento_PRTDSI__OE_SEL1        (* (reg8 *) Segmento__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Segmento_PRTDSI__OUT_SEL0       (* (reg8 *) Segmento__PRTDSI__OUT_SEL0) 
#define Segmento_PRTDSI__OUT_SEL1       (* (reg8 *) Segmento__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Segmento_PRTDSI__SYNC_OUT       (* (reg8 *) Segmento__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Segmento__SIO_CFG)
    #define Segmento_SIO_HYST_EN        (* (reg8 *) Segmento__SIO_HYST_EN)
    #define Segmento_SIO_REG_HIFREQ     (* (reg8 *) Segmento__SIO_REG_HIFREQ)
    #define Segmento_SIO_CFG            (* (reg8 *) Segmento__SIO_CFG)
    #define Segmento_SIO_DIFF           (* (reg8 *) Segmento__SIO_DIFF)
#endif /* (Segmento__SIO_CFG) */

/* Interrupt Registers */
#if defined(Segmento__INTSTAT)
    #define Segmento_INTSTAT            (* (reg8 *) Segmento__INTSTAT)
    #define Segmento_SNAP               (* (reg8 *) Segmento__SNAP)
    
	#define Segmento_0_INTTYPE_REG 		(* (reg8 *) Segmento__0__INTTYPE)
	#define Segmento_1_INTTYPE_REG 		(* (reg8 *) Segmento__1__INTTYPE)
	#define Segmento_2_INTTYPE_REG 		(* (reg8 *) Segmento__2__INTTYPE)
	#define Segmento_3_INTTYPE_REG 		(* (reg8 *) Segmento__3__INTTYPE)
	#define Segmento_4_INTTYPE_REG 		(* (reg8 *) Segmento__4__INTTYPE)
	#define Segmento_5_INTTYPE_REG 		(* (reg8 *) Segmento__5__INTTYPE)
	#define Segmento_6_INTTYPE_REG 		(* (reg8 *) Segmento__6__INTTYPE)
	#define Segmento_7_INTTYPE_REG 		(* (reg8 *) Segmento__7__INTTYPE)
#endif /* (Segmento__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Segmento_H */


/* [] END OF FILE */
