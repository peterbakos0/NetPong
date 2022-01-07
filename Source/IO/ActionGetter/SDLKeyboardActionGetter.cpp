#include <SDL2/SDL.h>
#include "../../Models/Config.hpp"
#include "../../Models/Action.hpp"
#include "SDLKeyboardActionGetter.hpp"

SDLKeyboardActionGetter::SDLKeyboardActionGetter()
{
	SDL_Init(SDL_INIT_EVENTS);
	keyStates = SDL_GetKeyboardState(NULL);
}

Action SDLKeyboardActionGetter::GetAction()
{
	Action action = IDLE;

	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			action = QUIT;
			break;
		}
	}

	if(action == IDLE)
	{
		if(keyStates[config.ACTION_CONFIRM_KEY_CODE])
		{
			action = CONFIRM;
		}
		else if(keyStates[config.ACTION_QUIT_KEY_CODE])
		{
			action = QUIT;
		}
		else if(keyStates[config.ACTION_MOVE_UP_KEY_CODE])
		{
			action = MOVE_UP;
		}
		else if(keyStates[config.ACTION_MOVE_DOWN_KEY_CODE])
		{
			action = MOVE_DOWN;
		}
	}

	return action;
}
