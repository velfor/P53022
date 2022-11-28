#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);

	/*CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	//перемещаем круг в цетр экрана
	shape.move(800 / 2 - 200 / 2, 600 / 2 - 200 / 2);
	float dx = 1.f;*/

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
		/*shape.move(dx, 0);
		if (shape.getPosition().x + 200 >= 800 ||
			shape.getPosition().x <= 0)
		{
			dx = -dx;
		}*/
		//отрисовка объектов и обновление окна
		window.clear();
		/*window.draw(shape);*/
		window.display();
	}

	return 0;
}