#pragma once
#include <SDL.h>
#include <stdio.h>
#include "GameWindowConfig.h"
#include "GameHandler.h"
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;


int main(int argc, char* args[]) {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	
	GameWindowConfig windowConfig("GameTitle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	unique_ptr<GameHandler> gameHandler = make_unique<GameHandler>(windowConfig);
	gameHandler->init();

	while (gameHandler->running()) {
		frameStart = SDL_GetTicks();

		gameHandler->handleEvents();
		gameHandler->update();
		gameHandler->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	gameHandler->clean();

	return 0;
}