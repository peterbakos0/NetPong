#include <cmath>
#include "../Models/Config.hpp"
#include "../Models/Score.hpp"
#include "../Models/Judgement.hpp"
#include "../GameObjects/OBall.hpp"
#include "Judge.hpp"

using namespace std;

Judge::Judge(Score* score, OBall* oBall)
{
	this->score = score;
	this->oBall = oBall;
}

Judgement Judge::MakeJudgement()
{
	Judgement judgement;

	judgement.didPlayerWin = false;
	judgement.score = *score;
	judgement.gameState = PLAYING;

	int ballRight = oBall->position.x + oBall->size.width;

	if(oBall->position.x <= 0)
	{
		if(config.IS_HOST)
		{
			judgement.score.enemyScore++;
		}
		else
		{
			judgement.score.playerScore++;
		}
	}
	else if(ballRight >= config.WINDOW_WIDTH)
	{
		if(config.IS_HOST)
		{
			judgement.score.playerScore++;
		}
		else
		{
			judgement.score.enemyScore++;
		}
	}
	else
	{
		return judgement;
	}

	int scoreDifference = abs(judgement.score.playerScore - judgement.score.enemyScore);

	if(scoreDifference >= config.MINIMUM_SCORE_DIFFERENCE)
	{
		judgement.didPlayerWin = (judgement.score.playerScore >= config.MINIMUM_WIN_SCORE);

		if(judgement.didPlayerWin || judgement.score.enemyScore >= config.MINIMUM_WIN_SCORE)
		{
			judgement.gameState = GAME_OVER;
			return judgement;
		}
	}

	judgement.gameState = SCORED;

	return judgement;
}
