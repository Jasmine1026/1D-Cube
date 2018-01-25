/*
 * FWMemory.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef FWMEMORY_H_
#define FWMEMORY_H_
#include <cstdlib>

constexpr size_t cMakeAlignmentSize(size_t size) {
	return ((size + sizeof(int) - 1) / sizeof(int)) * sizeof(int);
}

#endif /* FWMEMORY_H_ */
