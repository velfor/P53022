#pragma once
#include "settings.h"

class Obj {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Obj(sf::Vector2f pos) {
		texture.loadFromFile("car.png");
		sprite.setTexture(texture);
		sprite.setPosition(pos);
	}
	void update() {
		sprite.move(0.f, 2.f);
	}
	sf::Sprite getSprite() { return sprite; }
};