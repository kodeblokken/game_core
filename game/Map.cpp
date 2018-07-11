#pragma once
#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = {
{0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0},
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 1,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 2,2, 2,1, 1,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 2,2, 2,1, 1,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,2, 2,0, 1,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 1,1, 1,0, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,2, 2,2, 2,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
{ 0,0,0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0 },
};


void Map::drawMapTile(int type, SDL_Renderer * renderer)
{
	switch (type) {
	case 0:
		TextureManager::Draw(water.get(), src, dest, renderer);
		break;
	case 1:
		TextureManager::Draw(dirt.get(), src, dest, renderer);
		break;
	case 2:
		TextureManager::Draw(grass.get(), src, dest, renderer);
	default:
		break;
	}
}

Map::Map(std::shared_ptr<SDL_Renderer> renderer)
{
	this->renderer = renderer;
	dirt.reset(TextureManager::LoadTexture("assets/dirt.png", renderer.get()), SDL_DestroyTexture);
	grass.reset(TextureManager::LoadTexture("assets/grass.png", renderer.get()), SDL_DestroyTexture);
	water.reset(TextureManager::LoadTexture("assets/water.png", renderer.get()), SDL_DestroyTexture);

	loadMap(lvl1);

	src.x = src.y = 0;
	src.w = src.h = 100;
	dest.h = dest.w = 32;
}


Map::~Map()
{
}

void Map::loadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 20; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::drawMap()
{
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 20; column++) {
			dest.x = column * 32;
			dest.y = row * 32;
			drawMapTile(map[row][column], renderer.get());
		}
	}
}
