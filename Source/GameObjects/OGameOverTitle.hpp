#ifndef OGAMEOVERTITLE_HPP
#define OGAMEOVERTITLE_HPP

#include "OTitle.hpp"

class OGameOverTitle : public OTitle
{
public:
	OGameOverTitle(bool* didPlayerWin);

	void Start() override;
private:
	bool* didPlayerWin;
};

#endif
