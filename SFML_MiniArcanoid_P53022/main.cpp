#include <SFML/Graphics.hpp>
#include "settings.h"
#include "ball.h"
#include "bat.h"

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
		//отрисовка объектов и обновление окна
		window.clear();
		ballDraw(window, ball);
		batDraw(window, bat);
		window.display();
	}

	return 0;
}