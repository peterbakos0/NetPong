#include "../Models/Config.hpp"
#include "ImageGameObject.hpp"
#include "OBall.hpp"

OBall::OBall() : ImageGameObject()
{
	opacity = 1;

	size.width = config.BALL_DIAMETER;
	size.height = config.BALL_DIAMETER;

	imageFilePath = "Assets/Ball.png";
}
