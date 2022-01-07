#ifndef OMENUINFO_HPP
#define OMENUINFO_HPP

#include "../Models/GameState.hpp"
#include "OInfo.hpp"

class OMenuInfo : public OInfo
{
public:
	OMenuInfo(GameState* gameState);

	void Start() override;
	void Update() override;
private:
	GameState* gameState;
};

#endif
