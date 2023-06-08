#pragma once
#include <SFML/Graphics.hpp>
#include "Caracter.h"
class Enemigo : public Caracter
{
private:
	sf::Texture _texturaQ;
public:
	Enemigo();
	void update();

	//SETTERS & GETTERS
	sf::Sprite& getSprite();
	void setTexture(const sf::Texture& texture);
	void setVelocity(const sf::Vector2f& velocity);
};

