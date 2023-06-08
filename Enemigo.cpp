#include "Enemigo.h"
#include "Personaje.h"

Enemigo::Enemigo() : Caracter()
{
    _velocity = { 3,3 };
    _textura.loadFromFile("brujarda0001.png", sf::IntRect(0, 0, 63, 115));
    _texturaQ.loadFromFile("brujarda0001.png", sf::IntRect(64, 0, 63, 115));
    _sprite.setTexture(_textura);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setPosition(10.f, 590.f);

}

void Enemigo::update() {
    const float gravity = 0.2f;
    _velocity = { 0,0 };
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y = -3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity.y = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 3;
    }
    
    _sprite.move(_velocity);

    if (_velocity.x < 0) {
        _sprite.setTexture(_textura);
        _sprite.setScale(-1, 1);
    }
    else if (_velocity.x > 0) {
        _sprite.setTexture(_textura);
        _sprite.setScale(1, 1);
    }
    else if (_velocity.x == 0) {
        _sprite.setTexture(_texturaQ);

    }

    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }

    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - _sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height < 600) {
        _sprite.setPosition(_sprite.getPosition().x, 540 - _sprite.getOrigin().y);
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 540 - _sprite.getOrigin().y);
    }
}



