/*
 * kalman_filter.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_

#include "data_structures/vector.h"

#define PI_180 (57.2957795)

void kalmanFilterInit();
void kalmanFilterReset();

vector kalmanFilter(vector gyroscope, vector accelerometer);

void kalmanFilterSetQAngle(float qAngle);
void kalmanFilterSetQBias(float qBias);
void kalmanFilterSetRMeasure(float rMeasure);
void kalmanFilterSetDt(float dt);
float kalmanFilterGetQAngle();
float kalmanFilterGetQBias();
float kalmanFilterGetRMeasure();
float kalmanFilterGetDt();

#endif /* KALMAN_FILTER_H_ */
