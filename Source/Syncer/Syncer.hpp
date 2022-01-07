#ifndef SYNCER_HPP
#define SYNCER_HPP

#include "../GameObjects/OPlayerPaddle.hpp"
#include "../GameObjects/OBall.hpp"
#include "../IO/Communicator/Communicator.hpp"

class Syncer
{
public:
	Syncer(int* enemyPaddleY, int* ballX, int* ballY, OPlayerPaddle* oPlayerPaddle, OBall* oBall, Communicator* communicator);

	void Sync();
private:
	char seperator;
	int* enemyPaddleY;
	int* ballX;
	int* ballY;
	OPlayerPaddle* oPlayerPaddle;
	OBall* oBall;
	Communicator* communicator;

	void Give();
	void Get();
};

#endif
