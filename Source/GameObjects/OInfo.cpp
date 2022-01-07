#include "TextGameObject.hpp"
#include "OInfo.hpp"

OInfo::OInfo() : TextGameObject()
{
	opacity = 1;
	fontSize = 20;

	textSizeHelper->AutoSize();

	positionHelper->TopToMiddle();
	position.y += 10;
}

void OInfo::AdjustPosition()
{
	textSizeHelper->AutoSize();
	positionHelper->Center();
}
