#include "OTitle.hpp"
#include "OMenuTitle.hpp"

OMenuTitle::OMenuTitle() : OTitle()
{
	fontSize = 100;
	text = "Pong";

	AdjustPosition();
}

void OMenuTitle::Start()
{

}
