/*
 * lsm303dlhc.c
 *
 *  Created on: Dec 14, 2012
 *      Author: Michal Banasiak
 */


#include "lsm303dlhc.h"

void accelerometerSetup() {
	LSM303DLHCAcc_InitTypeDef LSM303DLHCAcc_InitStructure;
	LSM303DLHCAcc_FilterConfigTypeDef LSM303DLHCFilter_InitStructure;

	 /* Fill the accelerometer structure */
	LSM303DLHCAcc_InitStructure.Power_Mode = LSM303DLHC_NORMAL_MODE;
	LSM303DLHCAcc_InitStructure.AccOutput_DataRate = LSM303DLHC_ODR_50_HZ;
	LSM303DLHCAcc_InitStructure.Axes_Enable= LSM303DLHC_AXES_ENABLE;
	LSM303DLHCAcc_InitStructure.AccFull_Scale = LSM303DLHC_FULLSCALE_2G;
	LSM303DLHCAcc_InitStructure.BlockData_Update = LSM303DLHC_BlockUpdate_Continous;
	LSM303DLHCAcc_InitStructure.Endianness=LSM303DLHC_BLE_LSB;
	LSM303DLHCAcc_InitStructure.High_Resolution=LSM303DLHC_HR_ENABLE;
	/* Configure the accelerometer main parameters */
	LSM303DLHC_AccInit(&LSM303DLHCAcc_InitStructure);

	/* Fill the accelerometer LPF structure */
	LSM303DLHCFilter_InitStructure.HighPassFilter_Mode_Selection =LSM303DLHC_HPM_NORMAL_MODE;
	LSM303DLHCFilter_InitStructure.HighPassFilter_CutOff_Frequency = LSM303DLHC_HPFCF_16;
	LSM303DLHCFilter_InitStructure.HighPassFilter_AOI1 = LSM303DLHC_HPF_AOI1_DISABLE;
	LSM303DLHCFilter_InitStructure.HighPassFilter_AOI2 = LSM303DLHC_HPF_AOI2_DISABLE;

	/* Configure the accelerometer LPF main parameters */
	LSM303DLHC_AccFilterConfig(&LSM303DLHCFilter_InitStructure);
}

void magnetometerSetup() {
	LSM303DLHCMag_InitTypeDef initStructure;

	initStructure.MagFull_Scale = LSM303DLHC_FS_2_5_GA;
	initStructure.MagOutput_DataRate = LSM303DLHC_ODR_220_HZ;
	initStructure.Temperature_Sensor = LSM303DLHC_TEMPSENSOR_DISABLE;
	initStructure.Working_Mode = LSM303DLHC_CONTINUOS_CONVERSION;

	LSM303DLHC_MagInit(&initStructure);

}

void lsm303dlhcSetup() {
	accelerometerSetup();
	magnetometerSetup();
}

vector acceleration() {
	float tab[3];

	Acc_ReadData(tab);

	return vectorCreate(tab[0], tab[1], tab[2]);
}

float angleInDegreesFromXZ() {
	return angleInDegreesFromXZWithOffsetInDegrees(0);
}

float angleInDegreesFromYZ() {
	return angleInDegreesFromYZWithOffsetInDegrees(0);
}

float angleInDegreesFromXZWithOffsetInDegrees(float offset) {
	float tab[3];

	Acc_ReadData(tab);

	float x = tab[0];
	float y = tab[1];
	float z = tab[2];

	return atan2(-x,sqrt(y*y+z*z))*PI_180 + offset;
}

float angleInDegreesFromYZWithOffsetInDegrees(float offset) {
	float tab[3];

	Acc_ReadData(tab);

	float x = tab[0];
	float y = tab[1];
	float z = tab[2];

	return atan2(y,sqrt(x*x+z*z))*PI_180 + offset;
}

void Acc_ReadData(float* pfData)
{
  int16_t pnRawData[3];
  uint8_t ctrlx[2];
  float LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_2g;
  uint8_t buffer[6], cDivider;
  uint8_t i = 0;

  /* Read the register content */
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG4_A, ctrlx,2);
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_OUT_X_L_A, buffer, 6);


  if(ctrlx[1]&0x40)
    cDivider=64;
  else
    cDivider=16;

  /* check in the control register4 the data alignment*/
  if(!(ctrlx[0] & 0x40) || (ctrlx[1] & 0x40)) /* Little Endian Mode or FIFO mode */
  {
    for(i=0; i<3; i++)
    {
      pnRawData[i]=((int16_t)((uint16_t)buffer[2*i+1] << 8) + buffer[2*i])/cDivider;
    }
  }
  else /* Big Endian Mode */
  {
    for(i=0; i<3; i++)
      pnRawData[i]=((int16_t)((uint16_t)buffer[2*i] << 8) + buffer[2*i+1])/cDivider;
  }
  /* Read the register content */
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG4_A, ctrlx,2);


  if(ctrlx[1]&0x40)
  {
    /* FIFO mode */
    LSM_Acc_Sensitivity = 0.25;
  }
  else
  {
    /* normal mode */
    /* switch the sensitivity value set in the CRTL4*/
    switch(ctrlx[0] & 0x30)
    {
    case LSM303DLHC_FULLSCALE_2G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_2g;
      break;
    case LSM303DLHC_FULLSCALE_4G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_4g;
      break;
    case LSM303DLHC_FULLSCALE_8G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_8g;
      break;
    case LSM303DLHC_FULLSCALE_16G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_16g;
      break;
    }
  }

  /* Obtain the mg value for the three axis */
  for(i=0; i<3; i++)
  {
    pfData[i]=(float)pnRawData[i]/LSM_Acc_Sensitivity;
  }
}

uint32_t LSM303DLHC_TIMEOUT_UserCallback(void) {
	return 0;
}

void Mag_ReadData(float* pfData) {
	  int16_t pnRawData[3];
	  uint8_t ctrlx[2];
	  float LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_2g;
	  uint8_t buffer[6], cDivider;
	  uint8_t i = 0;

	  /* Read the register content */

	  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_OUT_X_H_M, buffer, 6);

	  for(i=0; i<3; i++)
	        pnRawData[i]=((int16_t)((uint16_t)buffer[2*i] << 8) + buffer[2*i+1]);

	  for(i=0; i<3; i++)
	  {
	    pfData[i]=(float)pnRawData[i];
	  }


}
