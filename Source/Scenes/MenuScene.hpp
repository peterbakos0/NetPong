#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "../Models/GameState.hpp"
#include "../Models/Action.hpp"
#include "Scene.hpp"

class MenuScene : public Scene
{
public:
	MenuScene(GameState* gameState, Action* action);

	void Start() override;
	void Update() override;
private:
	GameState* gameState;
	Action* action;
};

#endif
