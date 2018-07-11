#pragma once
#include "GameObject.h"
#include <random>

GameObject::GameObject(std::string texturePath, std::shared_ptr<SDL_Renderer> sdlRenderer, int x, int y):
	xPos(x),
	yPos(y),
	renderer(sdlRenderer),
	objTexture(TextureManager::LoadTexture(texturePath, sdlRenderer.get()), SDL_DestroyTexture)
{

}

GameObject::~GameObject()
{
}

void GameObject::update()
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(-1, 1); // guaranteed unbiased

	xPos += uni(rng);
	yPos += uni(rng);
	srcRect.h = 100;
	srcRect.w = 100;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 64;
	destRect.w = 64;
	destRect.x = xPos;
	destRect.y = yPos;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer.get(), objTexture.get(), &srcRect, &destRect);
}
