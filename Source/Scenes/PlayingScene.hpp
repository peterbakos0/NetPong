#ifndef PLAYINGSCENE_HPP
#define PLAYINGSCENE_HPP

#include "../Models/Score.hpp"
#include "../Models/GameState.hpp"
#include "../Models/Action.hpp"
#include "../Judge/Judge.hpp"
#include "../Syncer/Syncer.hpp"
#include "../IO/Communicator/Communicator.hpp"
#include "Scene.hpp"

class PlayingScene : public Scene
{
public:
	PlayingScene(bool* didPlayerWin, Score* score, GameState* gameState, Action* action, Communicator* communicator);

	void Start() override;
	void Update() override;
private:
	int enemyPaddleY;
	int ballX;
	int ballY;
	bool* didPlayerWin;
	Score* score;
	GameState* gameState;
	Judge* judge;
	Syncer* syncer;
};

#endif
