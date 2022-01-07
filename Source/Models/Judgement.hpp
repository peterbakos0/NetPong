#ifndef JUDGEMENT_HPP
#define JUDGEMENT_HPP

#include "Score.hpp"
#include "GameState.hpp"

struct Judgement
{
	bool didPlayerWin;
	struct Score score;
	GameState gameState;
};

#endif
