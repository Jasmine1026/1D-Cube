/*
 * CBinarySemaphore.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef CBINARYSEMAPHORE_H_
#define CBINARYSEMAPHORE_H_
#include "Global.h"
#include <pthread.h>

class CBinarySemaphore {
public:
	bool take(bool waitForever);
	void give();
public:
	CBinarySemaphore(bool isFull, bool isProcessShared);
	~CBinarySemaphore();
private:
	pthread_mutex_t mMutex;
	pthread_cond_t mCondition;
	Int32 mCounter;
};

#endif /* CBINARYSEMAPHORE_H_ */
