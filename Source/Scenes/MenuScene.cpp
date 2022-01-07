#include "../Models/GameState.hpp"
#include "../Models/Action.hpp"
#include "../GameObjects/OMenuTitle.hpp"
#include "../GameObjects/OMenuInfo.hpp"
#include "MenuScene.hpp"

MenuScene::MenuScene(GameState* gameState, Action* action)
{
	OMenuTitle* oMenuTitle = new OMenuTitle();
	OMenuInfo* oMenuInfo = new OMenuInfo(gameState);

	gameObjects.push_back(oMenuTitle);
	gameObjects.push_back(oMenuInfo);

	this->gameState = gameState;
	this->action = action;
}

void MenuScene::Start()
{

}

void MenuScene::Update()
{
	if(*action == CONFIRM)
	{
		*gameState = CONNECTING;
	}

	UpdateGameObjects();
}
