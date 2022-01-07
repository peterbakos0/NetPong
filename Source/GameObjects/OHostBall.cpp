#include "../Utils/GetNumberSign.hpp"
#include "../Utils/ClampNumber.hpp"
#include "../Utils/GenerateRandomNumber.hpp"
#include "../Models/Config.hpp"
#include "OPaddle.hpp"
#include "OBall.hpp"
#include "OHostBall.hpp"

OHostBall::OHostBall(OPaddle** oPaddles) : OBall()
{
	this->oPaddles = oPaddles;
}

void OHostBall::Start()
{
	positionHelper->Center();
	positionHelper->Middle();

	speed.x = config.BALL_INITIAL_SPEED_X;
	speed.y = GenerateRandomNumber(config.MINIMUM_BALL_INITIAL_SPEED_Y, config.MAXIMUM_BALL_INITIAL_SPEED_Y);

	int isSpeedXNegative = GenerateRandomNumber(0, 1);
	int isSpeedYNegative = GenerateRandomNumber(0, 1);

	if(isSpeedXNegative)
	{
		speed.x *= -1;
	}

	if(isSpeedYNegative)
	{
		speed.y *= -1;
	}
}

void OHostBall::Update()
{
	int right = position.x + size.width;
	int bottom = position.y + size.height;

	for(int i = 0; i < 2; i++)
	{
		OPaddle* oPaddle = oPaddles[i];

		int paddleRight = oPaddle->position.x + oPaddle->size.width;
		int paddleBottom = oPaddle->position.y + oPaddle->size.height;

		int leftPaddleBounceBorder = paddleRight + speed.x;
		int rightPaddleBounceBorder = oPaddle->position.x + speed.x;

		if(((position.x <= paddleRight && position.x >= leftPaddleBounceBorder) || (right >= oPaddle->position.x && right <= rightPaddleBounceBorder)) && position.y <= paddleBottom && bottom >= oPaddle->position.y)
		{
			speed.x *= -1;

			speed.x += config.BALL_SPEED_X_BOUNCE_INCREMENT * GetNumberSign(speed.x);

			speed.x = ClampNumber(speed.x, -config.MAXIMUM_BALL_SPEED_X, config.MAXIMUM_BALL_SPEED_X);

			speed.y = ((position.y + (size.height / 2)) - (oPaddle->position.y + (oPaddle->size.height / 2))) * config.BALL_SPEED_Y_BOUNCE_FACTOR;
		}
	}

	if(position.y <= 0 || bottom >= config.WINDOW_HEIGHT)
	{
		speed.y *= -1;
	}

	position.x += speed.x;
	position.y += speed.y;

	position.y = ClampNumber(position.y, 0, config.WINDOW_HEIGHT - size.height);
}
