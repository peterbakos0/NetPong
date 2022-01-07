#ifndef JUDGE_HPP
#define JUDGE_HPP

#include "../Models/Score.hpp"
#include "../Models/Judgement.hpp"
#include "../GameObjects/OBall.hpp"

class Judge
{
public:
	Judge(Score* score, OBall* oBall);

	Judgement MakeJudgement();
private:
	Score* score;
	OBall* oBall;
};

#endif
