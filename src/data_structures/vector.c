/*
 * vector.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#include "vector.h"

inline vector vectorCreate(float x, float y, float z) {
	vector result;

	result.x = x;
	result.y = y;
	result.z = z;

	return result;
}

vector vectorAdd(vector v1, vector v2) {
	return vectorCreate(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

vector vectorAddScalar(vector v1, float f) {
	return vectorCreate(v1.x+f, v1.y+f, v1.z+f);
}

vector vectorSubstract(vector v1, vector v2) {
	return vectorCreate(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}

vector vectorSubstractScalar(vector v1, float f) {
	return vectorCreate(v1.x-f, v1.y-f, v1.z-f);
}

vector vectorMultiply(vector v1, vector v2) {
	return vectorCreate(v1.x*v2.x, v1.y*v2.y, v1.z*v2.z);
}

vector vectorMultiplyScalar(vector v1, float f) {
	return vectorCreate(v1.x*f, v1.y*f, v1.z*f);
}

vector vectorDivide(vector v1, vector v2) {
	return vectorCreate(v1.x/v2.x, v1.y/v2.y, v1.z/v2.z);
}

vector vectorDivideScalar(vector v1, float f) {
	return vectorCreate(v1.x/f, v1.y/f, v1.z/f);
}
