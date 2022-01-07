#ifndef POSITIONHELPER_HPP
#define POSITIONHELPER_HPP

#include "../GameObjects/GameObject.hpp"
#include "IPositionHelper.hpp"

class PositionHelper : public IPositionHelper
{
public:
	PositionHelper(GameObject* gameObject);

	void Center() override;
	void Right() override;
	void Middle() override;
	void LeftToCenter() override;
	void RightToCenter() override;
	void TopToMiddle() override;
	void BottomToMiddle() override;
private:
	GameObject* gameObject;
};

#endif
