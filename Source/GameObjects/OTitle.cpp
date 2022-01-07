#include "TextGameObject.hpp"
#include "OTitle.hpp"

OTitle::OTitle() : TextGameObject()
{
	opacity = 1;
}

void OTitle::Update()
{

}

void OTitle::AdjustPosition()
{
	textSizeHelper->AutoSize();

	positionHelper->Center();
	positionHelper->BottomToMiddle();

	position.y += 20;
}
