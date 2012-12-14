/*
 * lsm303dlhc.h
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */

#ifndef LSM303DLHC_H_
#define LSM303DLHC_H_

#include "stm32f3_discovery_lsm303dlhc.h"

#define LSM_Acc_Sensitivity_2g     (float)     1.0f            /*!< accelerometer sensitivity with 2 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_4g     (float)     0.5f            /*!< accelerometer sensitivity with 4 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_8g     (float)     0.25f           /*!< accelerometer sensitivity with 8 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_16g    (float)     0.0834f         /*!< accelerometer sensitivity with 12 g full scale [LSB/mg] */


float accelerometerData();

void Acc_ReadData(float* pfData);
uint32_t LSM303DLHC_TIMEOUT_UserCallback(void);

#endif /* LSM303DLHC_H_ */
