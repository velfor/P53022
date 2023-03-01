#include "SFML/Graphics.hpp"

class Mob {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Mob(std::string fileName, sf::Vector2f pos) {
		texture.loadFromFile(fileName);
		sprite.setTexture(texture);
		sprite.setPosition(pos);
	}
	void update() {
		sprite.move(0.f, 2.f);
	}
	sf::Sprite getSprite() { return sprite; }
};