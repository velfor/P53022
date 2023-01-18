#include <SFML/Graphics.hpp>
#include "settings.h"
#include "ball.h"
#include "bat.h"
#include "textobj.h"
#include "brick.h"

using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		WINDOW_TITLE, 
		Style::Titlebar | Style::Close
	);
	window.setFramerateLimit(60);

	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	TextObj scoreText;
	textInit(scoreText, ball.score);
	Brick brick;
	brickInit(brick, Color::Yellow, Vector2f{50.f,50.f});
	

	while (window.isOpen())
	{
		//1 обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//обновление игровых объектов (функции update)
		ballUpdate(ball);
		batUpdate(bat);
		textUpdate(scoreText, ball.score);

		brickUpdate(brick);
		//отрисовка объектов и обновление окна
		window.clear();
		ballDraw(window, ball);
		batDraw(window, bat);
		textDraw(window, scoreText);

		brickDraw(window, brick);
		window.display();
	}

	return 0;
}