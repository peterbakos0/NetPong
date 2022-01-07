#include <string>
#include "TextGameObject.hpp"
#include "OScore.hpp"

using namespace std;

OScore::OScore(bool isOnLeftSide, int* scoreNumber) : TextGameObject()
{
	opacity = 0.2;
	fontSize = 100;
	position.y = -10;

	this->isOnLeftSide = isOnLeftSide;
	this->scoreNumber = scoreNumber;
}

void OScore::Start()
{

}

void OScore::Update()
{
	text = to_string(*scoreNumber);
	textSizeHelper->AutoSize();

	if(isOnLeftSide)
	{
		positionHelper->RightToCenter();
		position.x -= 30;
	}
	else
	{
		positionHelper->LeftToCenter();
		position.x += 30;
	}
}
