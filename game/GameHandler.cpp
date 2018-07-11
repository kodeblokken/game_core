#pragma once
#include "GameHandler.h"
#include "GameObject.h"
#include <vector>
#include "Map.h"

std::shared_ptr<GameObject> player = nullptr;
std::vector<shared_ptr<GameObject>> playerVec = {};
std::unique_ptr<Map> gameMap;

GameHandler::GameHandler(GameWindowConfig & window):
	gameWindow(window),
	isRunning(false)
{
}

GameHandler::~GameHandler()
{
}

void GameHandler::init()
{
	int flags = 0;
	if (gameWindow.isFullscreen() == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsytems initialized..." << std::endl;
		sdlWindow.reset(SDL_CreateWindow(gameWindow.getTitle().c_str(), gameWindow.getPosition().x, gameWindow.getPosition().y, gameWindow.getWidth(), gameWindow.getHeight(), flags));

		if (sdlWindow) {
			std::cout << "Window created" << std::endl;
		}

		sdlRenderer.reset(SDL_CreateRenderer(sdlWindow.get(), -1, 0), SDL_DestroyRenderer);

		if (sdlRenderer) {
			SDL_SetRenderDrawColor(sdlRenderer.get(), 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else {
		std::cout << "Could not initialize game" << std::endl;
		isRunning = false;
	}


	for (int i = 64; i < 400; i += 50) {
		std::shared_ptr<GameObject> prt( new GameObject("assets/player.bmp", sdlRenderer, i, i));
		playerVec.push_back(prt);
	}
	gameMap = std::make_unique<Map>(sdlRenderer);
}

void GameHandler::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void GameHandler::update()
{
	counter++;
	for(std::shared_ptr<GameObject> var : playerVec)
	{
		var->update();
	}
}

void GameHandler::render()
{
	SDL_RenderClear(sdlRenderer.get());
	gameMap->drawMap();
	for (std::shared_ptr<GameObject> var : playerVec)
	{
		var->render();
	}
	SDL_RenderPresent(sdlRenderer.get());
}

void GameHandler::clean()
{
	SDL_Quit();
	std::cout << "Game cleaned up" << std::endl;
}

bool GameHandler::running()
{
	return isRunning;
}
