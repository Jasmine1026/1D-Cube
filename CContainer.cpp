/*
 * CContainer.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: Jiawen Li
 */

#include "CContainer.h"

CContainer::CContainer() :
		mReadSem(false, false) {

}
bool CContainer::getContent(bool waitForever, SContent& content) {
	if (mReadSem.take(waitForever)) {
		content = mContent;
		return true;
	}
	return false;
}
void CContainer::signalReader() {
	mReadSem.give();
}
bool CContainer::writeADCValue(const UInt16 adcValue) {
	mContent.mADCValue = adcValue;
	return true;
}
bool CContainer::writeTorqueValue(const float torque) {
	mContent.mMotorTorque = torque;
	return true;
}
bool CContainer::writeSensor1Data(const SMPU6050Data& sensorData) {
	mContent.mSensor1Data = sensorData;
	return true;
}
bool CContainer::writeSensor2Data(const SMPU6050Data& sensorData) {
	mContent.mSensor2Data = sensorData;
	return true;
}
bool CContainer::writeStateData(const SStateVectorData& stateValue) {
	mContent.mStateData = stateValue;
	return true;
}
bool CContainer::readADCValue(UInt16 aV1) {
	aV1 = mContent.mADCValue;
	return true;
}

