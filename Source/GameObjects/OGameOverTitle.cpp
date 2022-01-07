#include "OTitle.hpp"
#include "OGameOverTitle.hpp"

OGameOverTitle::OGameOverTitle(bool* didPlayerWin) : OTitle()
{
	fontSize = 80;
	this->didPlayerWin = didPlayerWin;
}

void OGameOverTitle::Start()
{
	if(*didPlayerWin)
	{
		text = "You won";
	}
	else
	{
		text = "You lost";
	}

	AdjustPosition();
}
