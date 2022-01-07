#include "../Models/Config.hpp"
#include "ImageGameObject.hpp"
#include "OPaddle.hpp"

OPaddle::OPaddle() : ImageGameObject()
{
	opacity = 1;

	size.width = config.PADDLE_WIDTH;
	size.height = config.PADDLE_HEIGHT;

	imageFilePath = "Assets/Paddle.png";
	speedY = config.PADDLE_SPEED;
}
