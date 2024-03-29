/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Timer.h
**     Project     : ProcessorExpert
**     Processor   : MCF51JM32VLD
**     Component   : TimerInt
**     Version     : Component 02.159, Driver 01.22, CPU db: 3.00.062
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2012-11-27, 17:07, # CodeGen: 14
**     Abstract    :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings    :
**         Timer name                  : RTC (8-bit)
**         Compare name                : RTCmod
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 32768 Hz
**           Initial period/frequency
**             Xtal ticks              : 1
**             microseconds            : 31
**             seconds (real)          : 0.000030517578
**             Hz                      : 32768
**             kHz                     : 33
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : RTCCNT    [0xFFFF806D]
**              Mode                   : RTCSC     [0xFFFF806C]
**              Run                    : RTCSC     [0xFFFF806C]
**              Prescaler              : RTCSC     [0xFFFF806C]
**
**         Compare registers
**              Compare                : RTCMOD    [0xFFFF806E]
**
**         Flip-flop registers
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Timer
#define __Timer

/* MODULE Timer. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

__interrupt void Timer_Interrupt(void);
/*
** ===================================================================
**     Method      :  Timer_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the component event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Timer_Init(void);
/*
** ===================================================================
**     Method      :  Timer_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END Timer. */

#endif /* ifndef __Timer */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
