/*
 * CCommComp.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: Jiawen Li
 */

#include "CCommComp.h"
#include "SContent.h"
#include "CServer.h"
#include "CContainer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

extern CContainer myContainer;
SContent myContent;
CServer myServer;

CCommComp::CCommComp() {

}

CCommComp::~CCommComp() {

}

void CCommComp::run() {

	while (true) {

		myContainer.getContent(true, myContent);
//		myServer.transmitMessage(myContent);

	}

	cout << "Sensor1 ";
	cout << " X-Acc " << myContent.mSensor1Data.mX__dd;
	cout << " Y-Acc " << myContent.mSensor1Data.mY__dd;
	cout << " Z-Avel " << myContent.mSensor1Data.mPhi__d;
	cout << " mPadding " << myContent.mSensor1Data.mPadding << endl;

}

void CCommComp::init()
{
	myServer.init();
	myServer.waitForClient();
}

