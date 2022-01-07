#ifndef SDLVIDEO_HPP
#define SDLVIDEO_HPP

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../../GameObjects/GameObject.hpp"
#include "Video.hpp"

class SDLVideo : public Video
{
public:
	SDLVideo();

	void Start() override;
	void Show(GameObject* gameObject) override;
	void Clear() override;
	void Render() override;
private:
	std::map<std::string, SDL_Surface*> imageSurfaces;
	SDL_Renderer* renderer;
	TTF_Font* font;
};

#endif
