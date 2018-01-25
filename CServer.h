/*
 * CServer.h
 *
 *  Created on: Dec 14, 2017
 *      Author: vmuser
 */

#ifndef CSERVER_H_
#define CSERVER_H_

#include "Global.h"
#include "SContent.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class CServer {
public:
	void init();
	/**
	 * Blocks until a client connected.
	 */
	bool waitForClient();
	/**
	 * Method to transmit a message, blocks until the message was transmitted or the client disconnected.
	 * param[in] msg	Message to transmit
	 * return			True represents a successful transmission, false a broken connection.
	 */
	bool transmitMessage(SContent& content);
	/**
	 * Method to receive a message, blocks until the message was received or the client disconnected.
	 * param[out] msg	Received message
	 * return			True represents a successful read, false a broken connection.
	 */
	bool receiveMessage(SContent& content);
public:
	CServer();
	~CServer();
private:
#define sPort  ((Int32)40000)
	Int32 mSocketFD;
	Int32 mConnectedSocketFD;
	struct sockaddr_in mClientAddr;
	socklen_t mClientLen;
};

#endif /* SOCKET_CSERVER_H_ */
