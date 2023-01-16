#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct TextObj {
	sf::Font font;
	sf::Text text;
};

void textInit(TextObj& textobj, int score) {
	textobj.font.loadFromFile("DS-DIGIB.ttf");
	textobj.text.setFont(textobj.font);
	textobj.text.setString(std::to_string(score));
	textobj.text.setCharacterSize(FONT_SIZE);
	textobj.text.setPosition(TEXT_POS);
}

void textUpdate(TextObj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}

void textDraw(sf::RenderWindow& window, 
	const TextObj& textobj) 
{
	window.draw(textobj.text);
}