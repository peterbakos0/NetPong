#ifndef IPOSITIONHELPER_HPP
#define IPOSITIONHELPER_HPP

class IPositionHelper
{
public:
	virtual void Center() = 0;
	virtual void Right() = 0;
	virtual void Middle() = 0;
	virtual void LeftToCenter() = 0;
	virtual void RightToCenter() = 0;
	virtual void TopToMiddle() = 0;
	virtual void BottomToMiddle() = 0;
};

#endif
