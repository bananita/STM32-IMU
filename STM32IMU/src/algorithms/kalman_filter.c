/*
 * kalman_filter.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#include "kalman_filter.h"

float ___qAngle;
float ___qBias;
float ___rMeasure;
float ___dt;

float ___angle_x;
float ___rate_x;
float ___bias_x;
float ___P_x[2][2];
float ___K_x[2];
float ___y_x;
float ___S_x;

float ___angle_y;
float ___rate_y;
float ___bias_y;
float ___P_y[2][2];
float ___K_y[2];
float ___y_y;
float ___S_y;


void kalmanFilterInit() {
	kalmanFilterReset();
}

void kalmanFilterReset() {
    ___qAngle = 0.001;
    ___qBias = 0.003;
    ___rMeasure = 0.03;
    ___dt = 0.01;

    ___angle_x = 0.0f;
    ___rate_x = 0.0f;
    ___bias_x = 0.0f;
    ___P_x[0][0] = 0.0f;
    ___P_x[0][1] = 0.0f;
    ___P_x[1][0] = 0.0f;
    ___P_x[1][1] = 0.0f;
    ___K_x[0] = 0.0f;
    ___K_x[1] = 0.0f;
    ___y_x = 0.0f;
    ___S_x = 0.0f;

    ___angle_x = 0.0f;
    ___rate_x = 0.0f;
    ___bias_y = 0.0f;
    ___P_y[0][0] = 0.0f;
    ___P_y[0][1] = 0.0f;
    ___P_y[1][0] = 0.0f;
    ___P_y[1][1] = 0.0f;
    ___K_y[0] = 0.0f;
    ___K_y[1] = 0.0f;
    ___y_y = 0.0f;
    ___S_y = 0.0f;
}

vector kalmanFilter(vector gyroscope, vector accelerometer) {
	float accelerometerAngleX = atan2(-accelerometer.x,sqrt(accelerometer.y*accelerometer.y+accelerometer.z*accelerometer.z))*PI_180;
	float accelerometerAngleY = atan2(accelerometer.y,sqrt(accelerometer.x*accelerometer.x+accelerometer.z*accelerometer.z))*PI_180;

    ___rate_x = gyroscope.x - ___bias_x;
    ___angle_x += ___dt * ___rate_x;

    ___rate_y = gyroscope.y - ___bias_y;
    ___angle_y += ___dt * ___rate_y;

    ___P_x[0][0] += ___dt * (___dt*___P_x[1][1] - ___P_x[0][1] - ___P_x[1][0] + ___qAngle);
    ___P_x[0][1] -= ___dt * ___P_x[1][1];
    ___P_x[1][0] -= ___dt * ___P_x[1][1];
    ___P_x[1][1] += ___qBias * ___dt;

    ___P_y[0][0] += ___dt * (___dt*___P_y[1][1] - ___P_y[0][1] - ___P_y[1][0] + ___qAngle);
    ___P_y[0][1] -= ___dt * ___P_y[1][1];
    ___P_y[1][0] -= ___dt * ___P_y[1][1];
    ___P_y[1][1] += ___qBias * ___dt;


    ___S_x = ___P_x[0][0] + ___rMeasure;

    ___S_y = ___P_y[0][0] + ___rMeasure;


    ___K_x[0] = ___P_x[0][0] / ___S_x;
    ___K_x[1] = ___P_x[1][0] / ___S_x;

    ___K_y[0] = ___P_y[0][0] / ___S_y;
    ___K_y[1] = ___P_y[1][0] / ___S_y;


    ___y_x = accelerometerAngleX - ___angle_x;

    ___y_y = accelerometerAngleY - ___angle_y;


    ___angle_x += ___K_x[0] * ___y_x;
    ___bias_x += ___K_x[1] * ___y_x;

    ___angle_y += ___K_y[0] * ___y_y;
    ___bias_y += ___K_y[1] * ___y_y;


    ___P_x[0][0] -= ___K_x[0] * ___P_x[0][0];
    ___P_x[0][1] -= ___K_x[0] * ___P_x[0][1];
    ___P_x[1][0] -= ___K_x[1] * ___P_x[0][0];
    ___P_x[1][1] -= ___K_x[1] * ___P_x[0][1];

    ___P_y[0][0] -= ___K_y[0] * ___P_y[0][0];
    ___P_y[0][1] -= ___K_y[0] * ___P_y[0][1];
    ___P_y[1][0] -= ___K_y[1] * ___P_y[0][0];
    ___P_y[1][1] -= ___K_y[1] * ___P_y[0][1];



    return vectorCreate(___angle_x, ___angle_y, 0.0f);
}

void kalmanFilterSetQAngle(float qAngle) {
	___qAngle = qAngle;
}

void kalmanFilterSetQBias(float qBias) {
	___qBias = qBias;
}

void kalmanFilterSetRMeasure(float rMeasure) {
	___rMeasure = rMeasure;
}

void kalmanFilterSetDt(float dt) {
	___dt = dt;
}

float kalmanFilterGetQAngle() {
	return ___qAngle;
}

float kalmanFilterGetQBias() {
	return ___qBias;
}

float kalmanFilterGetRMeasure() {
	return ___rMeasure;
}

float kalmanFilterGetDt() {
	return ___dt;
}

