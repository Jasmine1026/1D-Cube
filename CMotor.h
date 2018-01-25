/*
 * CMotor.h
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#ifndef CMOTOR_H_
#define CMOTOR_H_

#include "Global.h"

class CMotor {
public:
	bool enableMotor();
	bool disableMotor();
	bool setTorque(float torque);
public:
	CMotor();
	~CMotor();
private:
	int initGPIOPin(UInt8 gpioNr);
	int initPWM();
	int sysfsEcho(const char* file, const char* string);
private:
	int mDirectionPinFd;
	int mEnablePinFd;
	int mTorquePWMFd;
};

#endif /* HARDWARE_CMOTOR_H_ */
