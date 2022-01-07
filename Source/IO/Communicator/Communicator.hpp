#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <string>

class Communicator
{
public:
	bool isConnected;

	virtual void Connect() = 0;
	virtual void Send(std::string message) = 0;
	virtual std::string Receive() = 0;
};

#endif
