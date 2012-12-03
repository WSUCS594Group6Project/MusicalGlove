/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JM32VLD
**     Component   : Events
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2012-11-20, 15:47, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Timer_OnInterrupt (module Events)
**
**     Component   :  Timer [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

extern int tcount;
void Timer_OnInterrupt(void)
{
  /* Write your code here ... */
	tcount++;
}

/*
** ===================================================================
**     Event       :  WaveSwitcher_OnInterrupt (module Events)
**
**     Component   :  WaveSwitcher [KBI]
**     Description :
**         This event is called when the active signal edge/level
**         occurs. This event is enabled only if <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
extern bool useSquare;
void WaveSwitcher_OnInterrupt(void)
{
  /* Write your code here ... */
	if(useSquare){
		useSquare = FALSE;
		Buzzer_SetRatio16(0);
	}
	else {
		useSquare = TRUE;
		SquareWave_ClrVal();
	}
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
