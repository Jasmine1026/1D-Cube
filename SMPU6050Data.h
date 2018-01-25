/*
 * SMPU6050Data.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef SMPU6050DATA_H_
#define SMPU6050DATA_H_
#include "Global.h"

struct SMPU6050Data {
public:
	Int16 mX__dd;		//! Sensor  X-Acceleration []
	Int16 mY__dd;		//! Sensor  Y-Acceleration []
	Int16 mPhi__d;		//! Sensor  Z-Angular Velocity []
	Int16 mPadding;
};

#endif /* SMPU6050DATA_H_ */
