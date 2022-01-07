#include "../Models/Config.hpp"
#include "ImageGameObject.hpp"
#include "OLine.hpp"

OLine::OLine() : ImageGameObject()
{
	opacity = 0.1;

	size.width = 8;
	size.height = config.WINDOW_HEIGHT;

	positionHelper->Center();
	position.y = 0;

	imageFilePath = "Assets/Line.png";
}

void OLine::Start()
{

}

void OLine::Update()
{

}
