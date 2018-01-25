/*
 * AComponentBase.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef ACOMPONENTBASE_H_
#define ACOMPONENTBASE_H_
#include "Config.h"
#include "IRunnable.h"

class CProxy;

class AComponentBase: public IRunnable {
public:
	virtual void run() = 0;
	virtual void init() = 0;
public:
	AComponentBase();
protected:
};

#endif /* ACOMPONENTBASE_H_ */
