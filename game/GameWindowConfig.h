#pragma once
#include <iostream>
#include <string>


class GameWindowConfig
{
public:
	struct window_position {
		int x;
		int y;
	};

private:
	window_position pos = {0,0};
	int width = 400;
	int height = 400;
	std::string title = "Game";
	bool fullscreen = false;

public:
	GameWindowConfig();
	GameWindowConfig(std::string title, int xpos, int ypos, int width, int height, bool fullscreen = false);
	~GameWindowConfig();

	GameWindowConfig::window_position getPosition();
	int getHeight();
	int getWidth();
	bool isFullscreen();
	std::string getTitle();
};

