/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JM32VLD
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2012-11-20, 15:47, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Timer.h"
#include "Buzzer.h"
#include "Fingers.h"
#include "SquareWave.h"
#include "WaveSwitcher.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

bool useSquare = TRUE;
int tcount = 0; //In case we need to poll something
int finger_val = 0;		//To store the value we get from finger input. hehe 
int sound_val = 0;		//The value of the sound we are outputing
int wave_pointer = 0;
int sine_array[8] = {
		32768	,
		55938	,
		65536	,
		55938	,
		32768	,
		9597	,
		0		,
		9597	};


void main(void)
{
/* Write your local variable definition here */

/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
PE_low_level_init();
/*** End of Processor Expert internal initialization.                    ***/

/* Write your code here */
for (;;){
	if(useSquare){
		finger_val = Fingers_GetVal(); // each cycle, find out which fingers are grounded
		switch(finger_val){ // and do...
			case 0: // Frequency is 4000
				if (tcount > 0){
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 1: 
				if (tcount > 1){
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 2:
				if (tcount > 2){
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 3:
				if (tcount > 3){
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 4: 
				if (tcount > 4){
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 5: 
				if (tcount > 5){
					SquareWave_NegVal();
					tcount = 0;
					}
				break; 
			case 6: 
				if (tcount > 6){
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 7: 
				SquareWave_ClrVal();
				break;
			}
		}
	else {
		finger_val = Fingers_GetVal(); // each cycle, find out which fingers are grounded
		switch(finger_val){ // and do...
			case 0: // Frequency is 4000
				if (tcount > 0){
					wave_pointer++;
					tcount = 0;
					}
				break;
			case 1: 
				if (tcount > 1){
					wave_pointer++;
					tcount = 0;
					}
				break;
			case 2:
				if (tcount > 2){
					wave_pointer++;
					tcount = 0;
					}
				break;
			case 3:
				if (tcount > 3){
					wave_pointer++;
					tcount = 0;
					}
				break;
			case 4: 
				if (tcount > 4){
					wave_pointer++;
					tcount = 0;
					}
				break;
			case 5: 
				if (tcount > 5){
					wave_pointer++;
					tcount = 0;
					}
				break; 
			case 6: 
				if (tcount > 6){
					wave_pointer++;
					tcount = 0;
					}
				break;
			case 7: 
				wave_pointer = 6;
				break;
			}
		if (wave_pointer>7) wave_pointer = 0;
		Buzzer_SetRatio16(sine_array[wave_pointer]);
		}
	}

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
