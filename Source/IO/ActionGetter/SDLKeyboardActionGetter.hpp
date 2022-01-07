#ifndef SDLKEYBOARDACTIONGETTER_HPP
#define SDLKEYBOARDACTIONGETTER_HPP

#include "../../Models/Action.hpp"
#include "ActionGetter.hpp"

class SDLKeyboardActionGetter : public ActionGetter
{
public:
	SDLKeyboardActionGetter();

	Action GetAction() override;
private:
	const Uint8* keyStates;
};

#endif
