#ifndef OGAMEOVERINFO_HPP
#define OGAMEOVERINFO_HPP

#include "../Models/Score.hpp"
#include "OInfo.hpp"

class OGameOverInfo : public OInfo
{
public:
	OGameOverInfo(struct Score* score);

	void Start() override;
	void Update() override;
private:
	struct Score* score;
};

#endif
