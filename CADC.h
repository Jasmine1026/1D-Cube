/*
 * CADC.h
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#ifndef CADC_H_
#define CADC_H_

#include "Global.h"

class CADC {
public:
	bool fetchValue(UInt16& value);
public:
	CADC();
	~CADC();
private:
	int sysfsEcho(const char* file, const char* string);
private:
	int mADCFd;
};

#endif /* HARDWARE_CADC_H_ */
