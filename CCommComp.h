/*
 * CCommComp.h
 *
 *  Created on: Dec 12, 2017
 *      Author: Jiawen Li
 */

#ifndef CCOMMCOMP_H_
#define CCOMMCOMP_H_
#include<pthread.h>
#include"IRunnable.h"
#include"CServer.h"
#include "SContent.h"
#include "Global.h"
#include "CServer.h"
#include "CContainer.h"

extern CContainer myContainer;

class CCommComp: public IRunnable {
public:
	CCommComp();
	~CCommComp();
	void run();
	void init();
private:
	CServer myServer;
	SContent myContent;

};

#endif /* CCOMMCOMP_H_ */
