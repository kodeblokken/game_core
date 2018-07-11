#pragma once
#include "GameHandler.h"
#include <memory>
#include "SDL.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(std::string fileName, SDL_Renderer* sdlRenderer);
	static void Draw(SDL_Texture* tex, SDL_Rect source, SDL_Rect dest, SDL_Renderer* sdlRenderer);
};

