/*
 * main.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: vmuser
 */

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "CThread.h"
#include "CContainer.h"
#include "CCommComp.h"
#include "CControlComp.h"
#include "CBinarySemaphore.h"

using namespace std;

CContainer myContainer;

int i = 0;

int main() {
	CCommComp myCommComp;
	CControlComp myControlComp;

	CThread threadControl(&myControlComp, CThread::PRIORITY_NORM);
	CThread threadComm(&myCommComp, CThread::PRIORITY_NORM);

	threadControl.start();
	threadComm.start();

	threadControl.join();
	threadComm.join();

}

