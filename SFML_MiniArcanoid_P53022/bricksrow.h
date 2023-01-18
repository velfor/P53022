#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "brick.h"

struct Brickrow {
	int size;
	Brick brickArr[10];
};

void brickRowInit(Brickrow& brickrow, int size, sf::Vector2f rowStartPos,
	float offsetX)
{
	brickrow.size = size;
	for (int i = 0; i < brickrow.size; i++) {
		sf::Color color{ 
			(sf::Uint8)(rand() % 256), 
			(sf::Uint8)(rand() % 256), 
			(sf::Uint8)(rand() % 256) 
		};
		sf::Vector2f position{ rowStartPos.x + i * BRICK_WIDTH, rowStartPos.y };
		brickInit(brickrow.brickArr[i], color, position);
	}
}

void brickRowUpdate(Brickrow& brickrow) {
	for (int i = 0; i < brickrow.size; i++) {
		brickUpdate(brickrow.brickArr[i]);
	}
}

void brickRowDraw(sf::RenderWindow& window, const Brickrow& brickrow) {
	for (int i = 0; i < brickrow.size; i++) {
		brickDraw(window, brickrow.brickArr[i]);
	}
}