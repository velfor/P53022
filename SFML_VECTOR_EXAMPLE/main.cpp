#include <SFML/Graphics.hpp>
#include "mob.h"
#include <vector>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);

	std::vector<Mob*> v_mobs;
	v_mobs.reserve(5);
	for (int i = 0; i < 5; i++) {
		float x = i * 100.f;
		float y = 20.f;
		Mob* m1 = new Mob("car.png", Vector2f{ x, y });
		v_mobs.push_back(m1);
	}
	while (window.isOpen())
	{
		//1 обработка событий
		Event event;
		while (window.pollEvent(event)){
			if (event.type == Event::Closed)
				window.close();
		}
		for (int i = 0; i < 5; i++) {
			(*v_mobs.at(i)).update();
		}
		//отрисовка объектов и обновление окна
		window.clear();
		/*window.draw(shape);*/
		for (int i = 0; i < 5; i++) {
			window.draw((*v_mobs.at(i)).getSprite());
		}
		window.display();
	}

	return 0;
}