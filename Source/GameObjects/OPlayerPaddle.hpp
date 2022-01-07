#ifndef OPLAYERPADDLE_HPP
#define OPLAYERPADDLE_HPP

#include "../Models/Action.hpp"
#include "OPaddle.hpp"

class OPlayerPaddle : public OPaddle
{
public:
	OPlayerPaddle(Action* action);

	void Start() override;
	void Update() override;
private:
	Action* action;
};

#endif
