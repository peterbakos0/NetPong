#ifndef OINFO_HPP
#define OINFO_HPP

#include "TextGameObject.hpp"

class OInfo : public TextGameObject
{
public:
	OInfo();
protected:
	void AdjustPosition();
};

#endif
