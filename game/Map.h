#pragma once
#include "GameHandler.h"
#include "SDL.h"


class Map
{
private:
	std::shared_ptr<SDL_Renderer> renderer;

	SDL_Rect src, dest;
	std::shared_ptr<SDL_Texture> dirt;
	std::shared_ptr<SDL_Texture> grass;
	std::shared_ptr<SDL_Texture> water;

	int map[20][25];

	void drawMapTile(int type, SDL_Renderer* renderer);
public:
	Map(std::shared_ptr<SDL_Renderer> renderer);
	~Map();

	void loadMap(int arr[20][25]);
	void drawMap();
};

