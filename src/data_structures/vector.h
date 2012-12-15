/*
 * vector.h
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct {
	float x;
	float y;
	float z;
} vector;

vector vectorCreate(float x, float y, float z);

vector vectorAdd(vector v1, vector v2);
vector vectorAddScalar(vector v1, float f);
vector vectorSubstract(vector v1, vector v2);
vector vectorSubstractScalar(vector v1, float f);
vector vectorMultiply(vector v1, vector v2);
vector vectorMultiplyScalar(vector v1, float f);
vector vectorDivide(vector v1, vector v2);
vector vectorDivideScalar(vector v1, float f);


#endif /* VECTOR_H_ */
