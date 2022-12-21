#include <SFML/Graphics.hpp>
#include "settings.h"
#include "functions.h"
#include "ball.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);

	//Создание объектов
	RectangleShape leftBat, rightBat;
	batInit(leftBat, LEFT_BAT_COLOR, LEFT_BAT_START_POS);
	batInit(rightBat, RIGHT_BAT_COLOR, RIGHT_BAT_START_POS);

	/*CircleShape ball;
	ballInit(ball);
	float ball.speedX = 2.f;
	float ball.speedY = 3.f;*/
	Ball ball;
	ballInit(ball);

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
		ball.shape.move(ball.speedX, ball.speedY);
		//мяч отскакивает от левой границы экрана
		if (ball.shape.getPosition().x <= 0) 
		{
			ball.speedX = -ball.speedX;
			rightScore++;
			rightText.setString(std::to_string(rightScore));
		}
		//мяч отскакивает от правой границы экрана
		if	(ball.shape.getPosition().x + 2 * BALL_RADIUS >= WINDOW_WIDTH)
		{
			ball.speedX = -ball.speedX;
			leftScore++;
			leftText.setString(std::to_string(leftScore));
		}

		if (ball.shape.getPosition().y <= 0 ||
			ball.shape.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
		{
			ball.speedY = -ball.speedY;
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
		Vector2f leftTop{ ball.shape.getPosition().x, ball.shape.getPosition().y };
		Vector2f midLeft{ ball.shape.getPosition().x, ball.shape.getPosition().y + BALL_RADIUS };
		Vector2f leftBottom{ ball.shape.getPosition().x, ball.shape.getPosition().y +
			2 * BALL_RADIUS };
		Vector2f midTop{ ball.shape.getPosition().x + BALL_RADIUS,  ball.shape.getPosition().y };
		Vector2f midBottom{ ball.shape.getPosition().x + BALL_RADIUS,  ball.shape.getPosition().y +
			2 * BALL_RADIUS };
		Vector2f rightTop{ ball.shape.getPosition().x + 2 * BALL_RADIUS, 
			ball.shape.getPosition().y };
		Vector2f midRight{ ball.shape.getPosition().x + 2 * BALL_RADIUS, 
			ball.shape.getPosition().y + BALL_RADIUS };
		Vector2f rightBottom{ ball.shape.getPosition().x + 2 * BALL_RADIUS, 
			ball.shape.getPosition().y + 2 * BALL_RADIUS };
		//ЛЕВАЯ РАКЕТКА
		//от правого края левой ракетки
		if (pointInRect(leftBat, midLeft) && pointInRect(leftBat, leftTop) ||
			pointInRect(leftBat, midLeft) && pointInRect(leftBat, leftBottom))
		{
			ball.speedX = -ball.speedX;
			if (ball.speedX > 0) ball.speedX++;
			else ball.speedX--;
			if (ball.speedY > 0) ball.speedY++;
			else ball.speedY--;
		}
		//от верхнего края левой ракетки
		if (pointInRect(leftBat, midBottom) && pointInRect(leftBat, leftBottom) ||
			pointInRect(leftBat, midBottom) && pointInRect(leftBat, rightBottom))
		{
			ball.speedY = -ball.speedY;
		}
		//от нижнего края левого ракетки
		if (pointInRect(leftBat, midTop) && pointInRect(leftBat, leftTop) ||
			pointInRect(leftBat, midTop) && pointInRect(leftBat, rightTop))
		{
			ball.speedY = -ball.speedY;
		}
		//в ракетку попал только левый нижний угол
		//в ракетку попал только левый верхний угол
		if ((pointInRect(leftBat, leftTop) || pointInRect(leftBat, leftBottom)) && 
			!pointInRect(leftBat, midLeft))
		{
			ball.speedY = -ball.speedY;
		}
		//ПРАВАЯ РАКЕТКА
		//от левого края ПРАВОЙ ракетки
		if (pointInRect(rightBat, midRight) && pointInRect(rightBat, rightTop) ||
			pointInRect(rightBat, midRight) && pointInRect(rightBat, rightBottom))
		{
			ball.speedX = -ball.speedX;
			if (ball.speedX > 0) ball.speedX++;
			else ball.speedX--;
			if (ball.speedY > 0) ball.speedY++;
			else ball.speedY--;
		}
		//от верхнего края правой ракетки
		if (pointInRect(rightBat, midBottom) && pointInRect(rightBat, leftBottom) ||
			pointInRect(rightBat, midBottom) && pointInRect(rightBat, rightBottom))
		{
			ball.speedY = -ball.speedY;
		}
		//от нижнего края правой ракетки
		if (pointInRect(rightBat, midTop) && pointInRect(rightBat, leftTop) ||
			pointInRect(rightBat, midTop) && pointInRect(rightBat, rightTop))
		{
			ball.speedY = -ball.speedY;
		}
		//в ракетку попал только правый нижний угол
		//в ракетку попал только правый верхний угол
		if ((pointInRect(rightBat, rightTop) || pointInRect(rightBat, rightBottom)) &&
			!pointInRect(rightBat, midRight))
		{
			ball.speedY = -ball.speedY;
		}
		//3 отрисовка объектов и обновление окна
		window.clear();
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball.shape);
		window.draw(leftText);
		window.draw(rightText);
		window.display();
	}
	return 0;
}