#pragma once
#include <string>

// ŒÕ—“¿Õ“€
const float WINDOW_WIDTH{ 800.f };
const float WINDOW_HEIGHT{ 600.f };
const std::string WINDOW_TITLE{ "SFML Lesson3" };
const unsigned int FPS{ 60 };

const sf::Vector2f BAT_SIZE{ 25.f, 100.f };
const float BAT_OFFSET{ 10.f };
const sf::Color LEFT_BAT_COLOR{ 178, 38, 38 };
const sf::Vector2f LEFT_BAT_START_POS{ BAT_OFFSET, (WINDOW_HEIGHT - BAT_SIZE.y) / 2 };
const sf::Color RIGHT_BAT_COLOR{ 255, 205, 50 };
const sf::Vector2f RIGHT_BAT_START_POS{ WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, (WINDOW_HEIGHT - BAT_SIZE.y) / 2 };
const float BAT_DY = 5.f;

const float BALL_RADIUS = 15.f;
const sf::Color BALL_COLOR{ 250, 208, 0 };
const sf::Vector2f BALL_START_POS{ (WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,
		(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2 };

const unsigned int FONT_SIZE = 64;
const sf::Vector2f LEFT_TEXT_POS{ 200.f, 10.f };
const sf::Vector2f RIGHT_TEXT_POS{ 550.f, 10.f };