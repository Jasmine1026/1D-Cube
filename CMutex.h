/*
 * CMutex.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef CMUTEX_H_
#define CMUTEX_H_
#include "Global.h"
#include <pthread.h>

class CMutex {
public:
	bool take(bool waitForever);
	void give();
public:
	CMutex(bool isFull = true, bool isProcessShared = false);
	CMutex(const CMutex&) = delete;
	CMutex& operator=(const CMutex&) = delete;
	~CMutex();
private:
	pthread_mutex_t mMutex;
};

#endif /* CMUTEX_H_ */
