#ifndef TEXTSIZEHELPER_HPP
#define TEXTSIZEHELPER_HPP

#include "../GameObjects/TextGameObject.hpp"
#include "ITextSizeHelper.hpp"

class TextSizeHelper : public ITextSizeHelper
{
public:
	TextSizeHelper(TextGameObject* textGameObject);

	void AutoSize() override;
private:
	TextGameObject* textGameObject;
};

#endif
