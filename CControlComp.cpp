/*
 * CControlComp.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: vmuser
 */

#include <iostream>
#include "CControlComp.h"
#include <cstdlib>
#include <unistd.h>
#include "CContainer.h"
#include "CBBBHardware.h"
#include "SMPU6050Data.h"
#include "CMotor.h"
#include "Global.h"
#include "SStateVectorData.h"
#include "math.h"

using namespace std;

extern CContainer myContainer;

SMPU6050Data mySensor1Data;
SMPU6050Data mySensor2Data;
SStateVectorData myStateVectorData;
CBBBHardware myHardware;
UInt16 myadcValue;

float rs1 = 0.14;
float rs2 = 0.061;
float alpha_acc = rs1/rs2;

float kx1 = 0.000641;
float ox1 = 0.243;

float ny1 = -0.0000000308;
float ky1 = 0.000279;
float oy1 = -6.09;

float kx2 = 0.000599;
float ox2 = 0.0308;

float ny2 = 0.0000000144;
float ky2 = 0.000191;
float oy2 = -2.78;

float gyro1 = -11.36;
float gyro2 = -30.7;
float gyroM = 0.00106526;

float aux;

float x1dd;
float y1dd;
float x2dd;
float y2dd;

float phiA;

float phiC;
float phiCA;
float filter_c = 0.98;
float t_abstand = 0.02;

float TM = 0;

float psid;

float kpsi = -0.5081;
float opsi = 1033.99;

float F[3] = {1.4701, 0.1075, 0.0005};

bool firstRun = true;

float koeff2 = 0.0001;
float koeff3 = -0.0001;

CControlComp::CControlComp()
{

}

CControlComp::~CControlComp()
{

}

void CControlComp::init()
{
	myHardware.enableMotor();
}

void CControlComp::run()
{
	while(true)
	{
		fetch();
		calibrate();
		calculate();
		filter();
		regler();
		motor();

	}
	myContainer.writeADCValue(myadcValue);
	myContainer.writeSensor1Data(mySensor1Data);
	myContainer.writeSensor2Data(mySensor2Data);
	myContainer.writeStateData(myStateVectorData);
	myContainer.signalReader();
}

void CControlComp::fetch()
{
	myHardware.fetchValues(myadcValue, mySensor1Data, mySensor2Data);
}

void CControlComp::calibrate()
{
	x1dd = mySensor1Data.mX__dd*kx1+ox1;
	y1dd = mySensor1Data.mY__dd*mySensor1Data.mY__dd*ny1+ky1*mySensor1Data.mY__dd+oy1;
	x2dd = mySensor2Data.mX__dd*kx2+ox2;
	y2dd = mySensor2Data.mY__dd*mySensor2Data.mY__dd*ny2+ky2*mySensor2Data.mY__dd+oy2;
}

void CControlComp::calculate()
{

	aux = (x1dd - alpha_acc*x2dd)/(y1dd - alpha_acc*y2dd);
	myStateVectorData.mPhi_A = -atan(aux);
	myStateVectorData.mPhi_G = ((mySensor1Data.mPhi__d - gyro1) + (mySensor1Data.mPhi__d - gyro2))* gyroM / 2;
	myStateVectorData.mPsi__d = kpsi*myadcValue + opsi;


}

void CControlComp::filter()
{
	if (firstRun)
	{
		myStateVectorData.mPhi_C = 0;
		phiCA = 0;
		firstRun = false;
	}
	else
	{
		myStateVectorData.mPhi_C = filter_c * (phiCA + t_abstand * myStateVectorData.mPhi_G) + (1 - t_abstand) * myStateVectorData.mPhi_A;
		phiCA = myStateVectorData.mPhi_C;
	}

}

void CControlComp::regler()
{
	if(myStateVectorData.mPhi_C > -0.1745 && myStateVectorData.mPhi_C < 0.1745)
	{
		TM = F[0]*myStateVectorData.mPhi_C + F[1]*myStateVectorData.mPhi_G + F[2]*myStateVectorData.mPsi__d;

	}
	else
	{
		if(myStateVectorData.mPhi_C > 0.1745)
		{
			TM = koeff2;
		}
		if(myStateVectorData.mPhi_C < -0.1745)
		{
			TM = koeff3;
		}
	}
}

void CControlComp::motor()
{
	myHardware.setTorque(TM);
}



