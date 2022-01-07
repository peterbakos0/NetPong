#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../../Models/Config.hpp"
#include "../../GameObjects/GameObject.hpp"
#include "../../GameObjects/ImageGameObject.hpp"
#include "../../GameObjects/TextGameObject.hpp"
#include "SDLVideo.hpp"

SDLVideo::SDLVideo()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	font = TTF_OpenFont("Assets/Font.ttf", 32);
}

void SDLVideo::Start()
{
	SDL_Window* window = SDL_CreateWindow(
		"Pong",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		config.WINDOW_WIDTH,
		config.WINDOW_HEIGHT,
		0
	);

	renderer = SDL_CreateRenderer(window, -1, 0);

	Clear();
}

void SDLVideo::Show(GameObject* gameObject)
{
	SDL_Surface* surface;

	switch(gameObject->type)
	{
	case IMAGE:
	{
		ImageGameObject* imageGameObject = (ImageGameObject*) gameObject;

		if(imageSurfaces.find(imageGameObject->imageFilePath) == imageSurfaces.end())
		{
			surface = IMG_Load(imageGameObject->imageFilePath.c_str());
			imageSurfaces[imageGameObject->imageFilePath] = surface;
		}
		else
		{
			surface = imageSurfaces[imageGameObject->imageFilePath];
		}

		break;
	}
	case TEXT:
	{
		TextGameObject* textGameObject = (TextGameObject*) gameObject;
		surface = TTF_RenderText_Solid(font, textGameObject->text.c_str(), {255, 255, 255});

		break;
	}
	default:
		break;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	int alpha = gameObject->opacity * 255;
	SDL_SetTextureAlphaMod(texture, alpha);

	SDL_Rect box;

	box.x = gameObject->position.x;
	box.y = gameObject->position.y;

	box.w = gameObject->size.width;
	box.h = gameObject->size.height;

	SDL_RenderCopy(renderer, texture, NULL, &box);

	if(gameObject->type == TEXT)
	{
		SDL_FreeSurface(surface);
	}

	SDL_DestroyTexture(texture);
}

void SDLVideo::Clear()
{
	SDL_RenderClear(renderer);
}

void SDLVideo::Render()
{
	SDL_RenderPresent(renderer);
}
