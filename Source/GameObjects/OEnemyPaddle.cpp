#include "../Models/Config.hpp"
#include "OPaddle.hpp"
#include "OEnemyPaddle.hpp"

OEnemyPaddle::OEnemyPaddle(int* enemyPaddleY) : OPaddle()
{
	if(config.IS_HOST)
	{
		positionHelper->Right();
		position.x -= config.PADDLE_GAP;
	}
	else
	{
		position.x = config.PADDLE_GAP;
	}

	this->enemyPaddleY = enemyPaddleY;
}

void OEnemyPaddle::Start()
{

}

void OEnemyPaddle::Update()
{
	position.y = *enemyPaddleY;
}
