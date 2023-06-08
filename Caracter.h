#pragma once
#include <SFML/Graphics.hpp>
class Caracter: public sf::Drawable{
protected:
    sf::Sprite _sprite;
    sf::Texture _textura;
    sf::Vector2f _velocity;

public:
    Caracter();
    virtual void update() = 0;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setTexture(const std::string& filename, const sf::IntRect& texture);
    void setVelocity(const sf::Vector2f& velocity);
};