#ifndef OENEMYPADDLE_HPP
#define OENEMYPADDLE_HPP

#include "OPaddle.hpp"

class OEnemyPaddle : public OPaddle
{
public:
	OEnemyPaddle(int* enemyPaddleY);

	void Start() override;
	void Update() override;
private:
	int* enemyPaddleY;
};

#endif
