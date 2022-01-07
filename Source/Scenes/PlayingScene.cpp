#include "../Utils/Wait.hpp"
#include "../Models/Config.hpp"
#include "../Models/Score.hpp"
#include "../Models/GameState.hpp"
#include "../Models/Action.hpp"
#include "../Models/Judgement.hpp"
#include "../GameObjects/OPaddle.hpp"
#include "../GameObjects/OPlayerPaddle.hpp"
#include "../GameObjects/OEnemyPaddle.hpp"
#include "../GameObjects/OBall.hpp"
#include "../GameObjects/OHostBall.hpp"
#include "../GameObjects/ODummyBall.hpp"
#include "../GameObjects/OScore.hpp"
#include "../GameObjects/OLine.hpp"
#include "../Judge/Judge.hpp"
#include "../Syncer/Syncer.hpp"
#include "../IO/Communicator/Communicator.hpp"
#include "PlayingScene.hpp"

PlayingScene::PlayingScene(bool* didPlayerWin, Score* score, GameState* gameState, Action* action, Communicator* communicator)
{
	OPlayerPaddle* oPlayerPaddle = new OPlayerPaddle(action);
	OEnemyPaddle* oEnemyPaddle = new OEnemyPaddle(&enemyPaddleY);

	OBall* oBall;
	int* leftScoreNumber;
	int* rightScoreNumber;

	if(config.IS_HOST)
	{
		OPaddle** oPaddles = new OPaddle*[2];

		oPaddles[0] = oPlayerPaddle;
		oPaddles[1] = oEnemyPaddle;

		oBall = new OHostBall(oPaddles);

		leftScoreNumber = &score->playerScore;
		rightScoreNumber = &score->enemyScore;
	}
	else
	{
		oBall = new ODummyBall(&ballX, &ballY);

		leftScoreNumber = &score->enemyScore;
		rightScoreNumber = &score->playerScore;
	}

	OScore* leftOScore = new OScore(true, leftScoreNumber);
	OScore* rightOScore = new OScore(false, rightScoreNumber);

	OLine* oLine = new OLine();

	gameObjects.push_back(oLine);
	gameObjects.push_back(leftOScore);
	gameObjects.push_back(rightOScore);
	gameObjects.push_back(oPlayerPaddle);
	gameObjects.push_back(oEnemyPaddle);
	gameObjects.push_back(oBall);

	judge = new Judge(score, oBall);
	syncer = new Syncer(&enemyPaddleY, &ballX, &ballY, oPlayerPaddle, oBall, communicator);

	this->didPlayerWin = didPlayerWin;
	this->score = score;
	this->gameState = gameState;
}

void PlayingScene::Start()
{
	StartGameObjects();
	syncer->Sync();
}

void PlayingScene::Update()
{
	if(*gameState == SCORED)
	{
		StartGameObjects();

		if(config.IS_HOST)
		{
			Wait(config.SCORED_WAIT_TIME_MS);
		}

		*gameState = PLAYING;
	}

	UpdateGameObjects();

	Judgement judgement = judge->MakeJudgement();

	*didPlayerWin = judgement.didPlayerWin;
	*score = judgement.score;
	*gameState = judgement.gameState;

	if(config.IS_HOST || *gameState != GAME_OVER)
	{
		syncer->Sync();
	}
}
