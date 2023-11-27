/*******************************************************************************
* File Name: Segmento.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Segmento_ALIASES_H) /* Pins Segmento_ALIASES_H */
#define CY_PINS_Segmento_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Segmento_0			(Segmento__0__PC)
#define Segmento_0_INTR	((uint16)((uint16)0x0001u << Segmento__0__SHIFT))

#define Segmento_1			(Segmento__1__PC)
#define Segmento_1_INTR	((uint16)((uint16)0x0001u << Segmento__1__SHIFT))

#define Segmento_2			(Segmento__2__PC)
#define Segmento_2_INTR	((uint16)((uint16)0x0001u << Segmento__2__SHIFT))

#define Segmento_3			(Segmento__3__PC)
#define Segmento_3_INTR	((uint16)((uint16)0x0001u << Segmento__3__SHIFT))

#define Segmento_4			(Segmento__4__PC)
#define Segmento_4_INTR	((uint16)((uint16)0x0001u << Segmento__4__SHIFT))

#define Segmento_5			(Segmento__5__PC)
#define Segmento_5_INTR	((uint16)((uint16)0x0001u << Segmento__5__SHIFT))

#define Segmento_6			(Segmento__6__PC)
#define Segmento_6_INTR	((uint16)((uint16)0x0001u << Segmento__6__SHIFT))

#define Segmento_7			(Segmento__7__PC)
#define Segmento_7_INTR	((uint16)((uint16)0x0001u << Segmento__7__SHIFT))

#define Segmento_INTR_ALL	 ((uint16)(Segmento_0_INTR| Segmento_1_INTR| Segmento_2_INTR| Segmento_3_INTR| Segmento_4_INTR| Segmento_5_INTR| Segmento_6_INTR| Segmento_7_INTR))

#endif /* End Pins Segmento_ALIASES_H */


/* [] END OF FILE */
