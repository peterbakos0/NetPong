#include "../GameObjects/TextGameObject.hpp"
#include "TextSizeHelper.hpp"

TextSizeHelper::TextSizeHelper(TextGameObject* textGameObject)
{
	this->textGameObject = textGameObject;
}

void TextSizeHelper::AutoSize()
{
	textGameObject->size.width = textGameObject->text.length() * textGameObject->fontSize / 2;
	textGameObject->size.height = textGameObject->fontSize;
}
