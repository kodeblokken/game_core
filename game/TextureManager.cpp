#pragma once
#include "TextureManager.h"


SDL_Texture* TextureManager::LoadTexture(std::string fileName, SDL_Renderer * sdlRenderer)
{
	SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());
	SDL_Texture* tex{SDL_CreateTextureFromSurface(sdlRenderer, tmpSurface)};
	SDL_FreeSurface(tmpSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect source, SDL_Rect dest, SDL_Renderer* sdlRenderer)
{
	SDL_RenderCopy(sdlRenderer, tex, &source, &dest);
}

