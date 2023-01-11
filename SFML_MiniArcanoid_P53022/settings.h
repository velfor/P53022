#pragma once
#include <string>
#include "SFML/Graphics.hpp"

// ŒÕ—“¿Õ“€
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 600.f };
const std::string WINDOW_TITLE{ "SFML Mini Arcanoid P53022" };
const unsigned int FPS{ 60 };

const sf::Vector2f BAT_SIZE{ 100.f, 25.f };
const float BAT_OFFSET{ 10.f };
const sf::Color BAT_COLOR{ 178, 38, 38 };
const sf::Vector2f BAT_START_POS{ 
	(WINDOW_WIDTH - BAT_SIZE.x)/2,
	WINDOW_HEIGHT - BAT_OFFSET - BAT_SIZE.y
};
const float BAT_SPEEDX = 5.f;

const float BALL_RADIUS = 15.f;
const sf::Color BALL_COLOR{ 250, 208, 0 };
const sf::Vector2f BALL_START_POS{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,
		(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2 };

const unsigned int FONT_SIZE = 64;
const sf::Vector2f LEFT_TEXT_POS{ 200.f, 10.f };
const sf::Vector2f RIGHT_TEXT_POS{ 550.f, 10.f };