#pragma once
#include "GameHandler.h"
#include <iostream>
#include <string>
#include <memory>

class GameObject
{
private:
	int xPos;
	int yPos;
	std::shared_ptr<SDL_Texture> objTexture = nullptr;
	std::shared_ptr<SDL_Renderer> renderer = nullptr;
	SDL_Rect srcRect, destRect;

public:
	GameObject(std::string texturePath, std::shared_ptr<SDL_Renderer> sdlRenderer, int x, int y);
	~GameObject();

	void update();
	void render();
};

