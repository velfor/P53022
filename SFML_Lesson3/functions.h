#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "ball.h"

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

void ballInit(Ball& ball){
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	ball.speedX = 2.f;
	ball.speedY = 3.f;
}

void textInit(sf::Text& text, sf::Font& font, int score, sf::Vector2f textPos) {
	text.setString(std::to_string(score));
	text.setFont(font);
	text.setCharacterSize(FONT_SIZE);
	text.setPosition(textPos);
}