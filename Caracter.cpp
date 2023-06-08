#include "Caracter.h"
Caracter::Caracter()
    : _velocity(0.f, 0.f)
{

}

void Caracter::update()
{
    //agregar algo que se aplique a todos los personajes y enemigos

}

void Caracter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Caracter::setTexture(const std::string& filename, const sf::IntRect& textureRect)
{
    sf::Texture texture;
    if (texture.loadFromFile(filename))
    {
        _sprite.setTexture(texture);
        _sprite.setTextureRect(textureRect);
    }
    else
    {
        // ERROR
    }
}

void Caracter::setVelocity(const sf::Vector2f& velocity)
{
    _velocity = velocity;
}