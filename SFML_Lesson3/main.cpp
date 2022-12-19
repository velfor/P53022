#include <SFML/Graphics.hpp>
#include "settings.h"
#include "functions.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);

	//Создание объектов
	RectangleShape leftBat, rightBat;
	batInit(leftBat, LEFT_BAT_COLOR, LEFT_BAT_START_POS);
	batInit(rightBat, RIGHT_BAT_COLOR, RIGHT_BAT_START_POS);

	CircleShape ball;
	ballInit(ball);
	float ballSpeedX = 2.f;
	float ballSpeedY = 3.f;

	Font font;
	font.loadFromFile("DS-DIGIB.ttf");
	int leftScore = 0;
	int rightScore = 0;
	Text leftText;
	textInit(leftText, font, leftScore, LEFT_TEXT_POS);
	Text rightText;
	textInit(rightText, font, rightScore, RIGHT_TEXT_POS);

	while (window.isOpen())
	{
		//1 обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		// Обновление игровых объектов
		//MЯЧ
		ball.move(ballSpeedX, ballSpeedY);
		//мяч отскакивает от левой границы экрана
		if (ball.getPosition().x <= 0) 
		{
			ballSpeedX = -ballSpeedX;
			rightScore++;
		}
		//мяч отскакивает от правой границы экрана
		if	(ball.getPosition().x + 2 * BALL_RADIUS >= WINDOW_WIDTH)
		{
			ballSpeedX = -ballSpeedX;
			leftScore++;
			leftText.setString(std::to_string(leftScore));
		}
		if (ball.getPosition().y <= 0 ||
			ball.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
		{
			ballSpeedY = -ballSpeedY;
			rightScore++;
			rightText.setString(std::to_string(rightScore));
		}
		//ЛЕВАЯ РАКЕТКА
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBat.move(0.f, -BAT_DY);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBat.move(0.f, BAT_DY);
		}
		//не даем левой ракетке выйти за верхний край экрана
		if (leftBat.getPosition().y < 0) {
			leftBat.setPosition(BAT_OFFSET, 0.f);
		}
		//не даем левой ракетке выйти за нижний край экрана
		if (leftBat.getPosition().y > WINDOW_HEIGHT - BAT_SIZE.y) {
			leftBat.setPosition(BAT_OFFSET, WINDOW_HEIGHT - BAT_SIZE.y);
		}
		//ПРАВАЯ РАКЕТКА
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightBat.move(0.f, -BAT_DY);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightBat.move(0.f, BAT_DY);
		}
		//не даем правой ракетке выйти за верхний край экрана
		if (rightBat.getPosition().y < 0) {
			rightBat.setPosition(WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, 0.f);
		}
		//не даем правой ракетке выйти за нижний  край экрана
		if (rightBat.getPosition().y < 0) {
			rightBat.setPosition(WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, 
				WINDOW_HEIGHT - BAT_SIZE.y);
		}
		//ОТСКОК МЯЧА ОТ РАКЕТОК
		Vector2f leftTop{ ball.getPosition().x, ball.getPosition().y };
		Vector2f midLeft{ ball.getPosition().x, ball.getPosition().y + BALL_RADIUS };
		Vector2f leftBottom{ ball.getPosition().x, ball.getPosition().y +
			2 * BALL_RADIUS };
		Vector2f midTop{ ball.getPosition().x + BALL_RADIUS,  ball.getPosition().y };
		Vector2f midBottom{ ball.getPosition().x + BALL_RADIUS,  ball.getPosition().y +
			2 * BALL_RADIUS };
		Vector2f rightTop{ ball.getPosition().x + 2 * BALL_RADIUS, 
			ball.getPosition().y };
		Vector2f midRight{ ball.getPosition().x + 2 * BALL_RADIUS, 
			ball.getPosition().y + BALL_RADIUS };
		Vector2f rightBottom{ ball.getPosition().x + 2 * BALL_RADIUS, 
			ball.getPosition().y + 2 * BALL_RADIUS };
		//ЛЕВАЯ РАКЕТКА
		//от правого края левой ракетки
		if (pointInRect(leftBat, midLeft) && pointInRect(leftBat, leftTop) ||
			pointInRect(leftBat, midLeft) && pointInRect(leftBat, leftBottom))
		{
			ballSpeedX = -ballSpeedX;
		}
		//от верхнего края левой ракетки
		if (pointInRect(leftBat, midBottom) && pointInRect(leftBat, leftBottom) ||
			pointInRect(leftBat, midBottom) && pointInRect(leftBat, rightBottom))
		{
			ballSpeedY = -ballSpeedY;
		}
		//от нижнего края левого ракетки
		if (pointInRect(leftBat, midTop) && pointInRect(leftBat, leftTop) ||
			pointInRect(leftBat, midTop) && pointInRect(leftBat, rightTop))
		{
			ballSpeedY = -ballSpeedY;
		}
		//в ракетку попал только левый нижний угол
		//в ракетку попал только левый верхний угол
		if ((pointInRect(leftBat, leftTop) || pointInRect(leftBat, leftBottom)) && 
			!pointInRect(leftBat, midLeft))
		{
			ballSpeedY = -ballSpeedY;
		}
		//ПРАВАЯ РАКЕТКА
		//от левого края ПРАВОЙ ракетки
		if (pointInRect(rightBat, midRight) && pointInRect(rightBat, rightTop) ||
			pointInRect(rightBat, midRight) && pointInRect(rightBat, rightBottom))
		{
			ballSpeedX = -ballSpeedX;
		}
		//от верхнего края правой ракетки
		if (pointInRect(rightBat, midBottom) && pointInRect(rightBat, leftBottom) ||
			pointInRect(rightBat, midBottom) && pointInRect(rightBat, rightBottom))
		{
			ballSpeedY = -ballSpeedY;
		}
		//от нижнего края правой ракетки
		if (pointInRect(rightBat, midTop) && pointInRect(rightBat, leftTop) ||
			pointInRect(rightBat, midTop) && pointInRect(rightBat, rightTop))
		{
			ballSpeedY = -ballSpeedY;
		}
		//в ракетку попал только правый нижний угол
		//в ракетку попал только правый верхний угол
		if ((pointInRect(rightBat, rightTop) || pointInRect(rightBat, rightBottom)) &&
			!pointInRect(rightBat, midRight))
		{
			ballSpeedY = -ballSpeedY;
		}
		//3 отрисовка объектов и обновление окна
		window.clear();
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftText);
		window.draw(rightText);
		window.display();
	}
	return 0;
}