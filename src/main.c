/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO(R)
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. Distribution of this file (unmodified or modified) is not
**  permitted. Atollic AB permit registered Atollic TrueSTUDIO(R) users the
**  rights to distribute the assembled, compiled & linked contents of this
**  file as part of an application binary file, provided that it is built
**  using the Atollic TrueSTUDIO(R) toolchain.
**
*****************************************************************************
*/

/* Includes */
#include "stm32f30x.h"

/* Private typedef */

/* Private define  */

/* Private macro */

/* Private variables */

/* Private function prototypes */

/* Private functions */

/* Global variables */
uint32_t timerFlag=0;

/**
**===========================================================================
**
**  Abstract: SysTick interrupt handler
**
**===========================================================================
*/
void SysTick_Handler(void)
{
  timerFlag = 1;
}


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  uint32_t ii;

  /* TODO - Add your application code here */
  
  /* Example use SysTick timer and read System core clock */
  SysTick_Config(72000);  /* 1 ms if clock frequency 72 MHz */

  SystemCoreClockUpdate();
  ii = SystemCoreClock;   /* This is a way to read the System core clock */
  
  /* Example update ii when timerFlag has been set by SysTick interrupt */
  ii = 0;
  while (1)
  {
    if (1==timerFlag)
    {
      timerFlag = 0;
      ii++;
    }
  }
  
  /* Program will never run to this line */
  return 0;
}
