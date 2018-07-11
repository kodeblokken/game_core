#pragma once
#include "ECS.h"

class PositionComponent : public Component {
private:
	int xPos;
	int yPos;
public:
	int getX() {
		return xPos;
	}
	int getY() {
		return yPos;
	}

	void  init() override {
		xPos = 0;
		yPos = 0;
	}

	void update() override {
		xPos++;
		yPos++;
	}

	void setPos(int x, int y) {
		xPos = x;
		yPos = y;
	}
};