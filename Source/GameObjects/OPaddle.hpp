#ifndef OPADDLE_HPP
#define OPADDLE_HPP

#include "ImageGameObject.hpp"

class OPaddle : public ImageGameObject
{
public:
	OPaddle();
protected:
	int speedY;
};

#endif
