#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct Bat
{
	sf::RectangleShape shape;
	float speedx;
};
void batInit(Bat& bat) {
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
}

void batControl(Bat& bat) {
	bat.speedx = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		bat.speedx = -BAT_SPEEDX;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		bat.speedx = BAT_SPEEDX;
	}
	bat.shape.move(bat.speedx, 0.f);
}
void batUpdate(Bat& bat) {
	batControl(bat);
	if (bat.shape.getPosition().x < 0) {
		bat.shape.setPosition(0.f, BAT_START_POS.y);
	}
	if (bat.shape.getPosition().x > WINDOW_WIDTH - BAT_SIZE.x) {
		bat.shape.setPosition(WINDOW_WIDTH - BAT_SIZE.x, BAT_START_POS.y);
	}
}
void batDraw(sf::RenderWindow& window, const Bat& bat) {
	window.draw(bat.shape);
}