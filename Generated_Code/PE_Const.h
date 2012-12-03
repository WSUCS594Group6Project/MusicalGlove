/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_Const.h
**     Project     : ProcessorExpert
**     Processor   : MCF51JM32VLD
**     Component   : PE_Const
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2012-11-20, 15:47, # CodeGen: 0
**     Abstract    :
**         This component "PE_Const" contains internal definitions
**         of the constants.
**     Settings    :
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __PE_Const_H
#define __PE_Const_H

/* Constants for detecting running mode */
#define HIGH_SPEED        0x00         /* High speed */
#define LOW_SPEED         0x01         /* Low speed */
#define SLOW_SPEED        0x02         /* Slow speed */

/* Reset cause constants */
#define RSTSRC_POR        0x80         /* Power-on reset        */
#define RSTSRC_PIN        0x40         /* External reset bit    */
#define RSTSRC_COP        0x20         /* COP reset             */
#define RSTSRC_ILOP       0x10         /* Illegal opcode reset  */
#define RSTSRC_ILAD       0x08         /* Illegal address reset */
#define RSTSRC_MODRST     0x04         /* Normal Monitor Mode Entry Reset*/
#define RSTSRC_MENRST     0x04         /* Forced Monitor Mode Entry Reset*/
#define RSTSRC_LVI        0x02         /* Low voltage inhibit reset */

#endif /* _PE_Const_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
