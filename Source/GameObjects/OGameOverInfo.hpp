#ifndef OGAMEOVERINFO_HPP
#define OGAMEOVERINFO_HPP

#include "../Models/Score.hpp"
#include "OInfo.hpp"

class OGameOverInfo : public OInfo
{
public:
	OGameOverInfo(Score* score);

	void Start() override;
	void Update() override;
private:
	Score* score;
};

#endif
