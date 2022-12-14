#include <SFML/Graphics.hpp>
#include "settings.h"

using namespace sf;
bool pointInRect(RectangleShape bat, Vector2f point) {
	return	bat.getPosition().x <= point.x &&
		point.x <= bat.getPosition().x + BAT_SIZE.x &&
		bat.getPosition().y <= point.y &&
		point.y <= bat.getPosition().y + BAT_SIZE.y;
}

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);

	//�������� ��������
	RectangleShape leftBat, rightBat;
	leftBat.setSize(BAT_SIZE);
	leftBat.setFillColor(LEFT_BAT_COLOR);
	leftBat.setPosition(BAT_OFFSET, (WINDOW_HEIGHT - BAT_SIZE.y) / 2);
	rightBat.setSize(BAT_SIZE);
	rightBat.setFillColor(RIGHT_BAT_COLOR);
	rightBat.setPosition(WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, (WINDOW_HEIGHT - BAT_SIZE.y) / 2);

	CircleShape ball(BALL_RADIUS);
	ball.setFillColor(BALL_COLOR);
	ball.setPosition((WINDOW_WIDTH - 2 * BALL_RADIUS) / 2, 
		(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2);

	float ballSpeedX = 2.f;
	float ballSpeedY = 3.f;

	//����
	//�����
	Font font;
	font.loadFromFile("DS-DIGIB.ttf");
	//���������� ��� �����
	int leftScore = 0;
	int rightScore = 0;
	//������ ��� ����������� �� ������
	//����� ��� ������ �����
	Text leftText;
	leftText.setString(std::to_string(leftScore));
	leftText.setFont(font);
	leftText.setCharacterSize(FONT_SIZE);
	leftText.setPosition(LEFT_TEXT_POS);

	//����� ��� ������� �����
	Text rightText;
	leftText.setString(std::to_string(leftScore));
	leftText.setFont(font);
	leftText.setCharacterSize(FONT_SIZE);
	leftText.setPosition(LEFT_TEXT_POS);
	while (window.isOpen())
	{
		//1 ��������� �������
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		// ���������� ������� ��������
		//M��
		ball.move(ballSpeedX, ballSpeedY);
		//��� ����������� �� ����� ������� ������
		if (ball.getPosition().x <= 0) 
		{
			ballSpeedX = -ballSpeedX;
			rightScore++;
		}
		//��� ����������� �� ������ ������� ������
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
		//����� �������
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBat.move(0.f, -BAT_DY);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBat.move(0.f, BAT_DY);
		}
		//�� ���� ����� ������� ����� �� ������� ���� ������
		if (leftBat.getPosition().y < 0) {
			leftBat.setPosition(BAT_OFFSET, 0.f);
		}
		//�� ���� ����� ������� ����� �� ������ ���� ������
		if (leftBat.getPosition().y > WINDOW_HEIGHT - BAT_SIZE.y) {
			leftBat.setPosition(BAT_OFFSET, WINDOW_HEIGHT - BAT_SIZE.y);
		}
		//������ �������
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightBat.move(0.f, -BAT_DY);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightBat.move(0.f, BAT_DY);
		}
		//�� ���� ������ ������� ����� �� ������� ���� ������
		if (rightBat.getPosition().y < 0) {
			rightBat.setPosition(WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, 0.f);
		}
		//�� ���� ������ ������� ����� �� ������  ���� ������
		if (rightBat.getPosition().y < 0) {
			rightBat.setPosition(WINDOW_WIDTH - BAT_OFFSET - BAT_SIZE.x, 
				WINDOW_HEIGHT - BAT_SIZE.y);
		}
		//������ ���� �� �������
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
		//����� �������
		//�� ������� ���� ����� �������
		if (pointInRect(leftBat, midLeft) && pointInRect(leftBat, leftTop) ||
			pointInRect(leftBat, midLeft) && pointInRect(leftBat, leftBottom))
		{
			ballSpeedX = -ballSpeedX;
		}
		//�� �������� ���� ����� �������
		if (pointInRect(leftBat, midBottom) && pointInRect(leftBat, leftBottom) ||
			pointInRect(leftBat, midBottom) && pointInRect(leftBat, rightBottom))
		{
			ballSpeedY = -ballSpeedY;
		}
		//�� ������� ���� ������ �������
		if (pointInRect(leftBat, midTop) && pointInRect(leftBat, leftTop) ||
			pointInRect(leftBat, midTop) && pointInRect(leftBat, rightTop))
		{
			ballSpeedY = -ballSpeedY;
		}
		//� ������� ����� ������ ����� ������ ����
		//� ������� ����� ������ ����� ������� ����
		if (pointInRect(leftBat, leftTop) || pointInRect(leftBat, leftBottom)) 
		{
			ballSpeedY = -ballSpeedY;
		}
		//������ �������
		//�� ������ ���� ������ �������
		if (pointInRect(rightBat, midRight) && pointInRect(rightBat, rightTop) ||
			pointInRect(rightBat, midRight) && pointInRect(rightBat, rightBottom))
		{
			ballSpeedX = -ballSpeedX;
		}
		//�� �������� ���� ������ �������
		if (pointInRect(rightBat, midBottom) && pointInRect(rightBat, leftBottom) ||
			pointInRect(rightBat, midBottom) && pointInRect(rightBat, rightBottom))
		{
			ballSpeedY = -ballSpeedY;
		}
		//�� ������� ���� ������ �������
		if (pointInRect(rightBat, midTop) && pointInRect(rightBat, leftTop) ||
			pointInRect(rightBat, midTop) && pointInRect(rightBat, rightTop))
		{
			ballSpeedY = -ballSpeedY;
		}
		//� ������� ����� ������ ������ ������ ����
		//� ������� ����� ������ ������ ������� ����
		if (pointInRect(rightBat, rightTop) || pointInRect(rightBat, rightBottom))
		{
			ballSpeedY = -ballSpeedY;
		}
		//3 ��������� �������� � ���������� ����
		window.clear();
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftText);
		//window.draw(rightText);
		window.display();
	}

	return 0;
}