#ifndef OSCORE_HPP
#define OSCORE_HPP

#include "TextGameObject.hpp"

class OScore : public TextGameObject
{
public:
	OScore(bool isOnLeftSide, int* scoreNumber);

	void Start() override;
	void Update() override;
private:
	bool isOnLeftSide;
	int* scoreNumber;
};

#endif
