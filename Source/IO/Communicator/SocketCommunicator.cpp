#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "../../Models/Config.hpp"
#include "SocketCommunicator.hpp"

using namespace std;

SocketCommunicator::SocketCommunicator()
{
	isConnected = false;
}

void SocketCommunicator::Connect()
{
	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(config.PORT);

	int addressLength = sizeof(address);
	int sfd = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr* castedAddress = (sockaddr*) &address;

	if(config.IS_HOST)
	{
		address.sin_addr.s_addr = INADDR_ANY;
		socklen_t* castedAddressLength = (socklen_t*) &addressLength;

		bind(sfd, castedAddress, addressLength);
		listen(sfd, 3);
		sock = accept(sfd, castedAddress, castedAddressLength);
	}
	else
	{
		inet_pton(AF_INET, config.IP_ADDRESS.c_str(), &address.sin_addr);

		int connectSuccess = connect(sfd, castedAddress, addressLength);

		if(connectSuccess < 0)
		{
			return;
		}

		sock = sfd;
	}

	isConnected = true;
}

void SocketCommunicator::Send(string message)
{
	if(!isConnected)
	{
		return;
	}

	const char* msg = message.c_str();
	send(sock, msg, strlen(msg), 0);
}

string SocketCommunicator::Receive()
{
	string message;

	if(!isConnected)
	{
		return message;
	}

	char buffer[1024] = {0};
	int success = read(sock, buffer, 1024);

	if(success >= 0)
	{
		message = string(&buffer[0], 1024);
	}
	else
	{
		isConnected = false;
	}

	return message;
}
