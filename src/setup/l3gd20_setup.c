/*
 * l3gd20_setup.c
 *
 *  Created on: Dec 12, 2012
 *      Author: Bazu
 */

#include "l3gd20_setup.h"

void l3gd20_setup() {
	L3GD20_InitTypeDef initStructure;

	initStructure.Axes_Enable = L3GD20_AXES_ENABLE;
	initStructure.Band_Width = L3GD20_BANDWIDTH_1;
	initStructure.BlockData_Update = L3GD20_BlockDataUpdate_Continous;
	initStructure.Endianness = L3GD20_BLE_LSB;
	initStructure.Full_Scale = L3GD20_FULLSCALE_250;
	initStructure.Output_DataRate = L3GD20_OUTPUT_DATARATE_1;
	initStructure.Power_Mode = L3GD20_MODE_ACTIVE;

	L3GD20_Init(&initStructure);
}
