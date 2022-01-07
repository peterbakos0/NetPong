#ifndef SOCKETCOMMUNICATOR_HPP
#define SOCKETCOMMUNICATOR_HPP

#include <string>
#include "Communicator.hpp"

class SocketCommunicator : public Communicator
{
public:
	SocketCommunicator();

	void Connect() override;
	void Send(std::string message) override;
	std::string Receive() override;
private:
	int sock;
};

#endif
