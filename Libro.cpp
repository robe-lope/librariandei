#include "Libro.h"

Libro::Libro(const std::string& filename, int puntaje)
{
    _velocity = { 0.f, 2.f };
    sf::Texture texture;
    if (texture.loadFromFile(filename, sf::IntRect(11,3,142,146)))
    {
        setTexture(texture);
        _puntaje = puntaje;
    }
    else
    {
        // ERROR
    }
}
void Libro::interactuar()
{
    sf::Vector2f posicionInicial(250.f, 0.f);
    setPosition(posicionInicial);
    sf::Vector2f ground(0.f, 500.f);
    if (posicionInicial.y < ground.y) {
        _position += _velocity;
        setPosition(_position);
        //sf::sleep(sf::milliseconds(10));
    }
    
}

int Libro::getPuntaje() const
{
    return _puntaje;
}

void Libro::update() {
    const float gravity = 0.2f;
    _velocity = { 0,3 };
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity.y = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 4;
    }
    */
    _sprite.move(_velocity);

    /*if (_velocity.x < 0) {
        _sprite.setTexture(_textura);
        _sprite.setScale(1, 1);
    }
    else if (_velocity.x > 0) {
        _sprite.setTexture(_textura);
        _sprite.setScale(-1, 1);
    }
    else if (_velocity.x == 0) {
        _sprite.setTexture(_texturaQ);

    }*/

    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }

    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - _sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height < 540) {
        _sprite.setPosition(_sprite.getPosition().x, 540 - _sprite.getOrigin().y);
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 540) {
        _sprite.setPosition(_sprite.getPosition().x, 540 - _sprite.getOrigin().y);
    }
}