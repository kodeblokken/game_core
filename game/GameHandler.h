#pragma once
#include "SDL.h"
#include "GameWindowConfig.h"
#include <iostream>
#include <string>
#include <memory>
#include "SDL_image.h"
#include "TextureManager.h"

#include "ECS.h"
#include "Components.h"

using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;

class GameHandler
{
private:
	unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> sdlWindow{ nullptr, SDL_DestroyWindow };
	shared_ptr<SDL_Renderer> sdlRenderer = nullptr;
	unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> sdlPlayerTex{nullptr, SDL_DestroyTexture};

	GameWindowConfig &gameWindow;
	int counter = 0;
	bool isRunning;

public:
	GameHandler(GameWindowConfig &window);
	~GameHandler();

	void init();
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
};

