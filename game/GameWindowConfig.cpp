#pragma once
#include "GameWindowConfig.h"



GameWindowConfig::GameWindowConfig()
{
}


GameWindowConfig::GameWindowConfig(std::string title, int xpos, int ypos, int width, int height, bool fullscreen):
	width(width),
	height(height),
	fullscreen(fullscreen),
	title(title)
{
	pos.x = xpos;
	pos.y = ypos;
}

GameWindowConfig::~GameWindowConfig()
{
}

GameWindowConfig::window_position GameWindowConfig::getPosition()
{
	return pos;
}

int GameWindowConfig::getHeight()
{
	return height;
}

int GameWindowConfig::getWidth()
{
	return width;
}

bool GameWindowConfig::isFullscreen()
{
	return fullscreen;
}

std::string GameWindowConfig::getTitle()
{
	return title;
}
