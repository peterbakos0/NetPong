#ifndef ODUMMYBALL_HPP
#define ODUMMYBALL_HPP

#include "OBall.hpp"

class ODummyBall : public OBall
{
public:
	ODummyBall(int* ballX, int* ballY);

	void Start() override;
	void Update() override;
private:
	int* ballX;
	int* ballY;
};

#endif
