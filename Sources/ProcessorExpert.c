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
int tcount = 0; 		//For the shared timer
int finger_val = 0;		//To store the value we get from finger input. hehe 
int wave_pointer = 0;	//The position in the sine_array
int sine_array[8] = {	//The array of values that form a sine wave.
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
	finger_val = Fingers_GetVal();			// each cycle, find out which fingers are grounded
	if(useSquare){ 							// Select which waveform to use, True uses Square
		switch(finger_val){ 				
			case 0: 						// Frequency is 8000Hz
				if (tcount > 0){			// At 1 timer interrupt
					SquareWave_NegVal();	// Negate the Speaker pin.
					tcount = 0;				// And reset timer.
					}
				break;
			case 1: 						// Frequency is 4000Hz
				if (tcount > 1){			//Same as 0, except it waits for 2 interrupts
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 2:							// Frequency is 1333Hz
				if (tcount > 2){			//Same as 0, except it waits for 3 interrupts
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 3:							// Frequency is 1000Hz
				if (tcount > 3){			//Same as 0, except it waits for 4 interrupts
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 4: 						// Frequency is 800Hz
				if (tcount > 4){			//Same as 0, except it waits for 5 interrupts
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 5: 						// Frequency is 666Hz
				if (tcount > 5){			//Same as 0, except it waits for 6 interrupts
					SquareWave_NegVal();
					tcount = 0;
					}
				break; 
			case 6:  						// Frequency is 871Hz
				if (tcount > 6){			//Same as 0, except it waits for 7 interrupts
					SquareWave_NegVal();
					tcount = 0;
					}
				break;
			case 7: 
				SquareWave_ClrVal();		//It just always clears the pin value
				break;
			}
		}
	else {									//useSquare is False, therefore use SineWave
		switch(finger_val){
			case 0: 						//Frequency is 4000
				if (tcount > 0){			//Waits for 1 Interrupt
					wave_pointer++;			//Increments the wave pointer
					tcount = 0;				//Resets timer
					}
				break;
			case 1: 
				if (tcount > 1){			//The following cases just wait for one more interrupt each.
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
				wave_pointer = 6;				//Sets the pointer to the value in the array that is 0.
				break;
			}
		if (wave_pointer>7) wave_pointer = 0;	//If the pointer is greater than 7, it resets to the first value
		Buzzer_SetRatio16(sine_array[wave_pointer]);	//And outputs the value to the PWM.
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
