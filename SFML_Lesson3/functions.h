#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

void batInit(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batStartPosition) {
	bat.setSize(BAT_SIZE);
	bat.setFillColor(batColor);
	bat.setPosition(batStartPosition);
}

bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	return	bat.getPosition().x <= point.x &&
		point.x <= bat.getPosition().x + BAT_SIZE.x &&
		bat.getPosition().y <= point.y &&
		point.y <= bat.getPosition().y + BAT_SIZE.y;
}