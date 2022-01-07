#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../Models/Score.hpp"
#include "../Models/GameState.hpp"
#include "../Models/Action.hpp"
#include "../Scenes/Scene.hpp"
#include "../Scenes/MenuScene.hpp"
#include "../Scenes/PlayingScene.hpp"
#include "../Scenes/GameOverScene.hpp"
#include "../IO/IOSet.hpp"

class Controller
{
public:
	Controller();

	void Start();
private:
	bool didPlayerWin;
	Score score;
	GameState gameState;
	Action action;
	Scene* currentScene;
	MenuScene* menuScene;
	PlayingScene* playingScene;
	GameOverScene* gameOverScene;
	IOSet* ioSet;

	void Update();
	void SetCurrentScene();
};

#endif
