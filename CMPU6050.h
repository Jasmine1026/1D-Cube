/*
 * CMPU6050.h
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#ifndef CMPU6050_H_
#define CMPU6050_H_

#include "SMPU6050Data.h"

class CMPU6050 {
public:
	bool fetchValues(SMPU6050Data& data);
public:
	CMPU6050(UInt8 deviceNr);
private:
	int echo(const char* file, const char* string);
	int read_int32(int fd, Int32& value);
private:
	int mAccelXFd;
	int mAccelYFd;
	int mAccelZFd;
	int mAnglVelXFd;
	int mAnglVelYFd;
	int mAnglVelZFd;
};

#endif /* HARDWARE_CMPU6050_H_ */
