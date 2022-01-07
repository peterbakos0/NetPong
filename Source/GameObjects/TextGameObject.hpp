#ifndef TEXTGAMEOBJECT_HPP
#define TEXTGAMEOBJECT_HPP

#include <string>
#include "../Helpers/ITextSizeHelper.hpp"
#include "GameObject.hpp"

class TextGameObject : public GameObject
{
public:
	TextGameObject();

	int fontSize;
	std::string text;
protected:
	ITextSizeHelper* textSizeHelper;
};

#endif
