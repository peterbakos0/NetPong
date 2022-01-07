#include "../Models/Config.hpp"
#include "../GameObjects/GameObject.hpp"
#include "PositionHelper.hpp"

PositionHelper::PositionHelper(GameObject* gameObject)
{
	this->gameObject = gameObject;
}

void PositionHelper::Center()
{
	gameObject->position.x = (config.WINDOW_WIDTH - gameObject->size.width) / 2;
}

void PositionHelper::Right()
{
	gameObject->position.x = config.WINDOW_WIDTH - gameObject->size.width;
}

void PositionHelper::Middle()
{
	gameObject->position.y = (config.WINDOW_HEIGHT - gameObject->size.height) / 2;
}

void PositionHelper::LeftToCenter()
{
	gameObject->position.x = config.WINDOW_WIDTH / 2;
}

void PositionHelper::RightToCenter()
{
	gameObject->position.x = (config.WINDOW_WIDTH / 2) - gameObject->size.width;
}

void PositionHelper::TopToMiddle()
{
	gameObject->position.y = config.WINDOW_HEIGHT / 2;
}

void PositionHelper::BottomToMiddle()
{
	gameObject->position.y = (config.WINDOW_HEIGHT / 2) - gameObject->size.height;
}
