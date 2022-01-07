#ifndef OTITLE_HPP
#define OTITLE_HPP

#include "TextGameObject.hpp"

class OTitle : public TextGameObject
{
public:
	OTitle();

	void Update() override;
protected:
	void AdjustPosition();
};

#endif
