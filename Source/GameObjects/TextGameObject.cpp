#include "../Helpers/TextSizeHelper.hpp"
#include "GameObject.hpp"
#include "TextGameObject.hpp"

TextGameObject::TextGameObject() : GameObject()
{
	type = TEXT;
	textSizeHelper = new TextSizeHelper(this);
}
