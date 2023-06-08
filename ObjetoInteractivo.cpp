#include "ObjetoInteractivo.h"

ObjetoInteractivo::ObjetoInteractivo()
{
    _position = { 0.f, 0.f };
}

void ObjetoInteractivo::setTexture(const sf::Texture& texture)
{
    _texture = texture;
    _sprite.setTexture(_texture);
}

void ObjetoInteractivo::setPosition(const sf::Vector2f& position)
{
    _sprite.setPosition(position);
}

sf::Vector2f ObjetoInteractivo::getPosition() const
{
    return _sprite.getPosition();
}

void ObjetoInteractivo::setVelocity(const sf::Vector2f& velocity)
{
    _velocity = velocity;
}

void ObjetoInteractivo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}