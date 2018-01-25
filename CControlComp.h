/*
 * CControlComp.h
 *
 *  Created on: Dec 12, 2017
 *      Author: Jiawen Li
 */

#ifndef CCONTROLCOMP_H_
#define CCONTROLCOMP_H_
#include "Global.h"
#include <pthread.h>
#include "IRunnable.h"
#include <unistd.h>
#include <sys/time.h>
#include "CContainer.h"
#include "CBBBHardware.h"

extern CContainer myContainer;

class CControlComp: public IRunnable {

public:
	void run();
	void init();
	void fetch();
	void calibrate();
	void calculate();
	void regler();
	void motor();
	void filter();
	~CControlComp();
	CControlComp();
private:
	CBBBHardware myHardware;
	UInt16 myadcValue;
	SMPU6050Data mySensorData1;
	SMPU6050Data mySensorData2;

};

#endif /* CCONTROLCOMP_H_ */
