/*
 * CContainer.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef CCONTAINER_H_
#define CCONTAINER_H_
#include "SContent.h"
#include "CBinarySemaphore.h"

class CContainer {
public:
	bool getContent(bool waitForever, SContent& content);
	void signalReader();
	bool writeADCValue(const UInt16 adcValue);
	bool writeTorqueValue(const float torque);
	bool writeSensor1Data(const SMPU6050Data& sensorData);
	bool writeSensor2Data(const SMPU6050Data& sensorData);
	bool writeStateData(const SStateVectorData& sensorData);
	bool readADCValue(UInt16 aV1);
public:
	CContainer();
private:
	SContent mContent;
	CBinarySemaphore mReadSem;
};

#endif /* CCONTAINER_H_ */
