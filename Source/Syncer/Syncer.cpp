#include <string>
#include <vector>
#include "../Utils/SplitText.hpp"
#include "../Models/Config.hpp"
#include "../GameObjects/OPlayerPaddle.hpp"
#include "../GameObjects/OBall.hpp"
#include "../IO/Communicator/Communicator.hpp"
#include "Syncer.hpp"

using namespace std;

Syncer::Syncer(int* enemyPaddleY, int* ballX, int* ballY, OPlayerPaddle* oPlayerPaddle, OBall* oBall, Communicator* communicator)
{
	seperator = ',';

	this->enemyPaddleY = enemyPaddleY;
	this->ballX = ballX;
	this->ballY = ballY;
	this->oPlayerPaddle = oPlayerPaddle;
	this->oBall = oBall;
	this->communicator = communicator;
}

void Syncer::Sync()
{
	Give();
	Get();
}

void Syncer::Give()
{
	string message = to_string(oPlayerPaddle->position.y);

	if(config.IS_HOST)
	{
		string ballXText = to_string(oBall->position.x);
		string ballYText = to_string(oBall->position.y);

		message += seperator + ballXText + seperator + ballYText;
	}

	communicator->Send(message);
}

void Syncer::Get()
{
	string message = communicator->Receive();

	if(message.length() <= 0)
	{
		return;
	}

	if(config.IS_HOST)
	{
		*enemyPaddleY = stoi(message);
	}
	else
	{
		vector<string> messageParts = SplitText(message, seperator);

		*enemyPaddleY = stoi(messageParts[0]);
		*ballX = stoi(messageParts[1]);
		*ballY = stoi(messageParts[2]);
	}
}
