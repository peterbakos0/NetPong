#include "../Utils/ClampNumber.hpp"
#include "../Models/Config.hpp"
#include "../Models/Action.hpp"
#include "OPaddle.hpp"
#include "OPlayerPaddle.hpp"

OPlayerPaddle::OPlayerPaddle(Action* action) : OPaddle()
{
	if(config.IS_HOST)
	{
		position.x = config.PADDLE_GAP;
	}
	else
	{
		positionHelper->Right();
		position.x -= size.width;
	}

	this->action = action;
}

void OPlayerPaddle::Start()
{
	positionHelper->Middle();
}

void OPlayerPaddle::Update()
{
	switch(*action)
	{
	case MOVE_UP:
		position.y -= speedY;
		break;
	case MOVE_DOWN:
		position.y += speedY;
		break;
	default:
		break;
	}

	position.y = ClampNumber(position.y, 0, config.WINDOW_HEIGHT - size.height);
}
