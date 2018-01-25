/*
 * SContent.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef SCONTENT_H_
#define SCONTENT_H_
#include "SMPU6050Data.h"
#include "SStateVectorData.h"
#include "Global.h"

struct SContent {
	SMPU6050Data mSensor1Data;
	SMPU6050Data mSensor2Data;
	SStateVectorData mStateData;
	float mMotorTorque;
	UInt16 mADCValue;
	UInt16 mPadding;
};

#endif /* SCONTENT_H_ */
