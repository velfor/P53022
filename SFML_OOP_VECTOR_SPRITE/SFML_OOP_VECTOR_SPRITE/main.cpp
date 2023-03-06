#include "settings.h"
#include <vector>
#include "obj.h"

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(60);

	std::vector<Obj*> v1;
	v1.reserve(19);

	for (int i = 0; i < 19; i++) {
		Obj* o = new Obj(Vector2f{ 100.f * i, 10.f });
		v1.push_back(o);
	}
	

	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed) window.close();
		
		for (int i = 0; i < v1.size(); i++) {
			v1.at(i)->update();
		}

		window.clear();
		for (int i = 0; i < v1.size(); i++) {
			window.draw(v1.at(i)->getSprite());
		}
		window.display();
	}

	return 0;
}