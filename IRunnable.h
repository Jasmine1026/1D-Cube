/*
 * IRunnable.h
 *
 *  Created on: Dec 12, 2017
 *      Author: vmuser
 */

#ifndef IRUNNABLE_H_
#define IRUNNABLE_H_

class IRunnable {
public:
	virtual void run() = 0;	/// Pure virtual method to run the task in a thread
	virtual void init() = 0;	/// Pure virtual method to initialize the task
public:
	virtual ~IRunnable() {
	}
	;
};

#endif /* IRUNNABLE_H_ */
