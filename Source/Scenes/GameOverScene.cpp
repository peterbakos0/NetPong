#include "../Models/Score.hpp"
#include "../GameObjects/OGameOverTitle.hpp"
#include "../GameObjects/OGameOverInfo.hpp"
#include "GameOverScene.hpp"

GameOverScene::GameOverScene(bool* didPlayerWin, Score* score)
{
	OGameOverTitle* oGameOverTitle = new OGameOverTitle(didPlayerWin);
	OGameOverInfo* oGameOverInfo = new OGameOverInfo(score);

	gameObjects.push_back(oGameOverTitle);
	gameObjects.push_back(oGameOverInfo);
}

void GameOverScene::Start()
{
	StartGameObjects();
}

void GameOverScene::Update()
{

}
