/*
 * CBrake.h
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#ifndef CBRAKE_H_
#define CBRAKE_H_

class CBrake {
public:
	bool openBrake();
	bool closeBrake();
public:
	CBrake();
	~CBrake();
private:
	int sysfsEcho(const char* file, const char* string);
private:
	int mServoPWMFd;
};

#endif /* HARDWARE_CBRAKE_H_ */
