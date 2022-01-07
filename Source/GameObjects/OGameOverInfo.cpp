#include <string>
#include "../Models/Score.hpp"
#include "OInfo.hpp"
#include "OGameOverInfo.hpp"

using namespace std;

OGameOverInfo::OGameOverInfo(Score* score) : OInfo()
{
	this->score = score;
}

void OGameOverInfo::Start()
{
	string playerScoreText = to_string(score->playerScore);
	string enemyScoreText = to_string(score->enemyScore);

	text = "Score is " + playerScoreText + " to " + enemyScoreText;

	AdjustPosition();
}

void OGameOverInfo::Update()
{

}
