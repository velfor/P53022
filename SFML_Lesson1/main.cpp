#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);

	/*CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	//���������� ���� � ���� ������
	shape.move(800 / 2 - 200 / 2, 600 / 2 - 200 / 2);
	float dx = 1.f;*/

	while (window.isOpen())
	{
		//1 ��������� �������
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//���������� ������� �������� (������� update)
		/*shape.move(dx, 0);
		if (shape.getPosition().x + 200 >= 800 ||
			shape.getPosition().x <= 0)
		{
			dx = -dx;
		}*/
		//��������� �������� � ���������� ����
		window.clear();
		/*window.draw(shape);*/
		window.display();
	}

	return 0;
}