#include "../Models/GameState.hpp"
#include "OInfo.hpp"
#include "OMenuInfo.hpp"

OMenuInfo::OMenuInfo(GameState* gameState) : OInfo()
{
	this->gameState = gameState;
}

void OMenuInfo::Start()
{

}

void OMenuInfo::Update()
{
	if(*gameState == CONNECTING)
	{
		text = "Connecting";
	}
	else
	{
		text = "Press CONFIRM to play";
	}

	AdjustPosition();
}
