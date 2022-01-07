#ifndef OHOSTBALL_HPP
#define OHOSTBALL_HPP

#include "../Models/Speed.hpp"
#include "OPaddle.hpp"
#include "OBall.hpp"

class OHostBall : public OBall
{
public:
	OHostBall(OPaddle** oPaddles);

	void Start() override;
	void Update() override;
private:
	Speed speed;
	OPaddle** oPaddles;
};

#endif
