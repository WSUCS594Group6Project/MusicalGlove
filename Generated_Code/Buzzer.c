/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Buzzer.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JM32VLD
**     Component   : PWM
**     Version     : Component 02.233, Driver 01.28, CPU db: 3.00.062
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2012-11-27, 16:33, # CodeGen: 7
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       42            |  PTC2_IRO
**             ----------------------------------------------------
**
**         Timer name                  : CMT_PWM [16-bit]
**         Counter                     : CMTCMD1   [0xFFFF986E]
**         Mode register               : CMTCMD3   [0xFFFF9870]
**         Run register                : CMTCMD2   [0xFFFF986F]
**         Prescaler                   : CMTCMD4   [0xFFFF9871]
**         Compare register            : CMTCMD1   [0xFFFF986E]
**         Flip-flop register          : CMTCMD2   [0xFFFF986F]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTC
**         Bit number (in port)        : 2
**         Bit mask of the port        : 0x0004
**         Port data register          : PTCD      [0xFFFF8004]
**         Port control register       : PTCDD     [0xFFFF8005]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 524288 Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : 16         0
**             microseconds            : 488        0
**             seconds (real)          : 0.00048828125 0.0
**
**     Contents    :
**         SetRatio16 - byte Buzzer_SetRatio16(word Ratio);
**         SetDutyUS  - byte Buzzer_SetDutyUS(word Time);
**         SetDutyMS  - byte Buzzer_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


/* MODULE Buzzer. */

#include "PE_Error.h"
#include "Buzzer.h"


static word ActualRatio;               /* Ratio of L-level to H-level */
static word CmpDHigh;                  /* Duty - compare register value for high speed CPU mode */
static word CmpPHigh;                  /* Period - modulo register value for high speed CPU mode */

/* Internal method prototypes */

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetReg method for duty 
**         value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void);

/* End of Internal methods declarations */

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetReg method for duty 
**         value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void)
{
  if (ActualRatio == 0xFFFFU) {        /* Duty = 100%? */
    CMTCMD12 = 0xFFU;
    CMTCMD34 = 0x00U;
  } else {
    CmpDHigh = (word)(((0x0100UL + 0x01UL) * (dword)ActualRatio) >> 0x10U); /* Calculate new value of compare register according to the given ratio */
    CmpPHigh = (word)(0x0100U - CmpDHigh);
    if (CmpDHigh) {
      --CmpDHigh;
    }
    CMTCMD12 = CmpPHigh;               /* Store appropriate values to the compare and modulo registers according to the selected high speed CPU mode */
    CMTCMD34 = CmpDHigh;
  }
}

/*
** ===================================================================
**     Method      :  Buzzer_SetRatio16 (component PWM)
**
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte Buzzer_SetRatio16(word Ratio)
{
  ActualRatio = Ratio;                 /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Buzzer_SetDutyUS (component PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to 488 us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte Buzzer_SetDutyUS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */
  if (Time > 0x01E8U) {                /* Is the given value out of range? */
    return ERR_RANGE;                  /* If yes then error */
  }
  PE_Timer_LngMul((dword)Time, 0x8637BD06UL, &rtval); /* Multiply given value and High speed CPU mode coefficient */
  if (PE_Timer_LngHi3(rtval[0], rtval[1], &ActualRatio)) { /* Is the result greater or equal than 65536 ? */
    ActualRatio = 0xFFFFU;             /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Buzzer_SetDutyMS (component PWM)
**
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**         Note: The period is too short. The method will return
**               just the error code in high speed mode.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte Buzzer_SetDutyMS(word Time)
{
    #pragma unused (Time)
  /* Period is too short. The method SetDutyMS will return an error code only in High speed mode. */
  return ERR_MATH;                     /* Calculation error */
}

/*
** ===================================================================
**     Method      :  Buzzer_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Buzzer_Init(void)
{
  /* CMTOC: IROL=0,CMTPOL=1,IROPEN=1,??=0,??=0,??=0,??=0,??=0 */
  setReg8(CMTOC, 0x60U);               /* Set output polarity to low */ 
  ActualRatio = 0x00U;                 /* Store initial value of the ratio */
  /* CMTMSC: EOCF=0,CMTDIV1=0,CMTDIV0=0,EXSPC=0,BASE=1,FSK=0,EOCIE=0,MCGEN=0 */
  setReg8(CMTMSC, 0x08U);              /* Set modulator status and control register */ 
  SetRatio();                          /* Calculate and set up new values of the compare according to the selected speed CPU mode */
  /* CMTMSC: MCGEN=1 */
  setReg8Bits(CMTMSC, 0x01U);          /* Enable device */ 
}

/* END Buzzer. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
