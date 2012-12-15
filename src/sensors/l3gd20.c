/*
 * l3gd20.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */


#include "l3gd20.h"

void Gyro_ReadData(float* pfData) {
  int16_t pnRawData[3];
  uint8_t ctrlx[2];

  uint8_t buffer[6], cDivider;
  uint8_t i = 0;

  /* Read the register content */

  L3GD20_Read(buffer, L3GD20_OUT_X_H_ADDR, 6);



  {
    for(i=0; i<3; i++)
      pnRawData[i]=((int16_t)((uint16_t)buffer[2*i] << 8) + buffer[2*i+1]);
  }



  /* Obtain the mg value for the three axis */
  for(i=0; i<3; i++)
  {
    pfData[i]=(float)pnRawData[i]*0.00875;
  }
}

/**
  * @brief  Basic management of the timeout situation.
  * @param  None.
  * @retval None.
  */
uint32_t L3GD20_TIMEOUT_UserCallback(void)
{
  /* Block communication and all processes */
  while (1)
  {
  }
}
