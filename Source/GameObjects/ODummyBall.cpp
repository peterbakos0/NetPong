#include "OBall.hpp"
#include "ODummyBall.hpp"

ODummyBall::ODummyBall(int* ballX, int* ballY) : OBall()
{
	this->ballX = ballX;
	this->ballY = ballY;
}

void ODummyBall::Start()
{

}

void ODummyBall::Update()
{
	position.x = *ballX;
	position.y = *ballY;
}
