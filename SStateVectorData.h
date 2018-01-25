/*
 * SStateVectorData.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef SSTATEVECTORDATA_H_
#define SSTATEVECTORDATA_H_
#include "Global.h"

struct SStateVectorData {
public:
	float mPhi_A;			//! Phi-Value from the acceleration-estimate [rad]
	float mPhi_G;			//! Phi-Value from the gyroscope-integration [rad]
	float mPhi_C;			//! Phi-Value from the complementaryfilter [rad]
	float mPhi__d;			//! Phi__d-Value from the gyroscopes [rad/sec]
	float mPsi__d;			//! Psi__d-Vallue from the ADC	[rad/sec]
};

#endif /* SSTATEVECTORDATA_H_ */
