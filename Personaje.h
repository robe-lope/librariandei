#pragma once
#include <SFML/Graphics.hpp>
#include "Caracter.h"
class Personaje : public Caracter
{
private:
	sf::Texture _texturaQ;
public:
	Personaje();
	void update();
	
    //SETTERS & GETTERS
    sf::Sprite& getSprite();
    
};
