/*******************************************************************************
* File Name: Modo.h  
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

#if !defined(CY_PINS_Modo_H) /* Pins Modo_H */
#define CY_PINS_Modo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Modo_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Modo__PORT == 15 && ((Modo__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Modo_Write(uint8 value);
void    Modo_SetDriveMode(uint8 mode);
uint8   Modo_ReadDataReg(void);
uint8   Modo_Read(void);
void    Modo_SetInterruptMode(uint16 position, uint16 mode);
uint8   Modo_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Modo_SetDriveMode() function.
     *  @{
     */
        #define Modo_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Modo_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Modo_DM_RES_UP          PIN_DM_RES_UP
        #define Modo_DM_RES_DWN         PIN_DM_RES_DWN
        #define Modo_DM_OD_LO           PIN_DM_OD_LO
        #define Modo_DM_OD_HI           PIN_DM_OD_HI
        #define Modo_DM_STRONG          PIN_DM_STRONG
        #define Modo_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Modo_MASK               Modo__MASK
#define Modo_SHIFT              Modo__SHIFT
#define Modo_WIDTH              1u

/* Interrupt constants */
#if defined(Modo__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Modo_SetInterruptMode() function.
     *  @{
     */
        #define Modo_INTR_NONE      (uint16)(0x0000u)
        #define Modo_INTR_RISING    (uint16)(0x0001u)
        #define Modo_INTR_FALLING   (uint16)(0x0002u)
        #define Modo_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Modo_INTR_MASK      (0x01u) 
#endif /* (Modo__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Modo_PS                     (* (reg8 *) Modo__PS)
/* Data Register */
#define Modo_DR                     (* (reg8 *) Modo__DR)
/* Port Number */
#define Modo_PRT_NUM                (* (reg8 *) Modo__PRT) 
/* Connect to Analog Globals */                                                  
#define Modo_AG                     (* (reg8 *) Modo__AG)                       
/* Analog MUX bux enable */
#define Modo_AMUX                   (* (reg8 *) Modo__AMUX) 
/* Bidirectional Enable */                                                        
#define Modo_BIE                    (* (reg8 *) Modo__BIE)
/* Bit-mask for Aliased Register Access */
#define Modo_BIT_MASK               (* (reg8 *) Modo__BIT_MASK)
/* Bypass Enable */
#define Modo_BYP                    (* (reg8 *) Modo__BYP)
/* Port wide control signals */                                                   
#define Modo_CTL                    (* (reg8 *) Modo__CTL)
/* Drive Modes */
#define Modo_DM0                    (* (reg8 *) Modo__DM0) 
#define Modo_DM1                    (* (reg8 *) Modo__DM1)
#define Modo_DM2                    (* (reg8 *) Modo__DM2) 
/* Input Buffer Disable Override */
#define Modo_INP_DIS                (* (reg8 *) Modo__INP_DIS)
/* LCD Common or Segment Drive */
#define Modo_LCD_COM_SEG            (* (reg8 *) Modo__LCD_COM_SEG)
/* Enable Segment LCD */
#define Modo_LCD_EN                 (* (reg8 *) Modo__LCD_EN)
/* Slew Rate Control */
#define Modo_SLW                    (* (reg8 *) Modo__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Modo_PRTDSI__CAPS_SEL       (* (reg8 *) Modo__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Modo_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Modo__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Modo_PRTDSI__OE_SEL0        (* (reg8 *) Modo__PRTDSI__OE_SEL0) 
#define Modo_PRTDSI__OE_SEL1        (* (reg8 *) Modo__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Modo_PRTDSI__OUT_SEL0       (* (reg8 *) Modo__PRTDSI__OUT_SEL0) 
#define Modo_PRTDSI__OUT_SEL1       (* (reg8 *) Modo__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Modo_PRTDSI__SYNC_OUT       (* (reg8 *) Modo__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Modo__SIO_CFG)
    #define Modo_SIO_HYST_EN        (* (reg8 *) Modo__SIO_HYST_EN)
    #define Modo_SIO_REG_HIFREQ     (* (reg8 *) Modo__SIO_REG_HIFREQ)
    #define Modo_SIO_CFG            (* (reg8 *) Modo__SIO_CFG)
    #define Modo_SIO_DIFF           (* (reg8 *) Modo__SIO_DIFF)
#endif /* (Modo__SIO_CFG) */

/* Interrupt Registers */
#if defined(Modo__INTSTAT)
    #define Modo_INTSTAT            (* (reg8 *) Modo__INTSTAT)
    #define Modo_SNAP               (* (reg8 *) Modo__SNAP)
    
	#define Modo_0_INTTYPE_REG 		(* (reg8 *) Modo__0__INTTYPE)
#endif /* (Modo__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Modo_H */


/* [] END OF FILE */
