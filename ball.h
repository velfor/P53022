#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct Ball {
	sf::CircleShape shape;
	float speedX;
	float speedY;
	int score;
};
void ballInit(Ball& ball) {
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	ball.speedX = 2.f;
	ball.speedY = 3.f;
	ball.score = 0;
}
void ballUpdate(Ball& ball) {
	ball.shape.move(ball.speedX, ball.speedY);
	//м€ч отскакивает от левой границы экрана
	if (ball.shape.getPosition().x <= 0)
		ball.speedX = -ball.speedX;
	//м€ч отскакивает от правой границы экрана
	if (ball.shape.getPosition().x + 2 * BALL_RADIUS >= WINDOW_WIDTH)
		ball.speedX = -ball.speedX;
	//м€ч отскакивает от нижней и верхней границы экрана
	if (ball.shape.getPosition().y <= 0 ||
		ball.shape.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
		ball.speedY = -ball.speedY;
}
void ballDraw(sf::RenderWindow& window, const Ball& ball) {
	window.draw(ball.shape);
}