#ifndef GAMEOVERSCENE_HPP
#define GAMEOVERSCENE_HPP

#include "../Models/Score.hpp"
#include "Scene.hpp"

class GameOverScene : public Scene
{
public:
	GameOverScene(bool* didPlayerWin, Score* score);

	void Start() override;
	void Update() override;
};

#endif
