#include "../Utils/Wait.hpp"
#include "../Models/Config.hpp"
#include "../Scenes/Scene.hpp"
#include "../Scenes/MenuScene.hpp"
#include "../Scenes/PlayingScene.hpp"
#include "../Scenes/GameOverScene.hpp"
#include "../IO/IOSet.hpp"
#include "Controller.hpp"

Controller::Controller()
{
	ioSet = new IOSet();
	ioSet->configSetter->SetConfig();

	didPlayerWin = false;

	score.playerScore = 0;
	score.enemyScore = 0;

	gameState = MENU;
	action = IDLE;

	menuScene = new MenuScene(&gameState, &action);
	playingScene = new PlayingScene(&didPlayerWin, &score, &gameState, &action, ioSet->communicator);
	gameOverScene = new GameOverScene(&didPlayerWin, &score);
}

void Controller::Start()
{
	ioSet->video->Start();

	int waitTimeMs = 1000 / config.FPS;

	while(gameState != QUITTING)
	{
		Update();
		Wait(waitTimeMs);
	}
}

void Controller::Update()
{
	action = ioSet->actionGetter->GetAction();

	switch(action)
	{
	case QUIT:
		gameState = QUITTING;
		return;
	default:
		break;
	}

	Scene* lastScene = currentScene;
	SetCurrentScene();

	if(currentScene != lastScene)
	{
		currentScene->Start();
	}

	currentScene->Update();

	ioSet->video->Clear();

	for(unsigned i = 0; i < currentScene->gameObjects.size(); i++)
	{
		GameObject* gameObject = currentScene->gameObjects[i];
		ioSet->video->Show(gameObject);
	}

	ioSet->video->Render();

	switch(gameState)
	{
	case CONNECTING:
		ioSet->communicator->Connect();

		if(ioSet->communicator->isConnected)
		{
			gameState = PLAYING;
		}
		else
		{
			gameState = MENU;
		}

		break;
	default:
		break;
	}
}

void Controller::SetCurrentScene()
{
	switch(gameState)
	{
	case MENU:
	case CONNECTING:
		currentScene = menuScene;
		break;
	case PLAYING:
	case SCORED:
		currentScene = playingScene;
		break;
	case GAME_OVER:
		currentScene = gameOverScene;
		break;
	default:
		break;
	}
}
