/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Fingers.c
**     Project     : ProcessorExpert
**     Processor   : MCF51JM32VLD
**     Component   : BitsIO
**     Version     : Component 02.102, Driver 03.14, CPU db: 3.00.062
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2012-11-20, 16:13, # CodeGen: 2
**     Abstract    :
**         This component "BitsIO" implements a multi-bit input/output.
**         It uses selected pins of one 1-bit to 8-bit port.
**         Note: This component is set to work in Input direction only.
**     Settings    :
**         Port name                   : PTB
**
**         Bit mask of the port        : 0x0007
**         Number of bits/pins         : 3
**         Single bit numbers          : 0 to 2
**         Values range                : 0 to 7
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : up
**
**         Port data register          : PTBD      [0xFFFF8002]
**         Port control register       : PTBDD     [0xFFFF8003]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    23   |   PTB0_MISO2_ADP0
**                    1      |    24   |   PTB1_MOSI2_ADP1
**                    2      |    25   |   PTB2_SPSCK2_ADP2
**             ----------------------------------------------------
**
**         Optimization for            : speed
**     Contents    :
**         GetDir - bool Fingers_GetDir(void);
**         GetVal - byte Fingers_GetVal(void);
**         GetBit - bool Fingers_GetBit(byte Bit);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Fingers. */

#include "Fingers.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  Fingers_GetMsk (component BitsIO)
**
**     Description :
**         The method returns a bit mask which corresponds to the 
**         required bit position.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static const byte Fingers_Table[3U] = { /* Table of mask constants */
   0x01U, 0x02U, 0x04U
};

static byte Fingers_GetMsk (byte PinIndex)
{
  return (byte)((PinIndex<3U) ? Fingers_Table[PinIndex] : 0U); /* Check range and return appropriate bit mask */
}

/*
** ===================================================================
**     Method      :  Fingers_GetVal (component BitsIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pins and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Input direction only.
**     Parameters  : None
**     Returns     :
**         ---        - Input value (0 to 7)
** ===================================================================
*/
byte Fingers_GetVal(void)
{
  return (byte)(getReg8(PTBD) & 0x07U); /* Return port data */
}

/*
** ===================================================================
**     Method      :  Fingers_GetBit (component BitsIO)
**
**     Description :
**         This method returns the specified bit of the input value.
**           a) direction = Input  : reads the input value from pins
**                                   and returns the specified bit
**           b) direction = Output : returns the specified bit
**                                   of the last written value
**         Note: This component is set to work in Input direction only.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to read (0 to 2)
**     Returns     :
**         ---        - Value of the specified bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/
bool Fingers_GetBit(byte Bit)
{
  byte const Mask = Fingers_GetMsk(Bit); /* Temporary variable - bit mask to test */
  return (bool)(((getReg8(PTBD) & Mask) == Mask)? 1U: 0U); /* Test if specified bit of port register is set */
}

/*
** ===================================================================
**     Method      :  Fingers_GetDir (component BitsIO)
**
**     Description :
**         This method returns direction of the component.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the component (always FALSE, Input only)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
/*
bool Fingers_GetDir(void)

**  This method is implemented as a macro. See Fingers.h file.  **
*/


/* END Fingers. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
