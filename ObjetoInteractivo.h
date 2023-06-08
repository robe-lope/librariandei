#pragma once
#include <SFML/Graphics.hpp>

class ObjetoInteractivo : public sf::Drawable
{
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    sf::Vector2f _position;


public:
    ObjetoInteractivo();
    virtual void interactuar() = 0;  // Función virtual pura para la interacción del objeto

    // Métodos comunes para todos los objetos interactivos
    void setTexture(const sf::Texture& texture);
    void setPosition(const sf::Vector2f& position);
    void setVelocity(const sf::Vector2f& velocity);
    sf::Vector2f getPosition() const;

    // Método para dibujar el objeto
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    //virtual bool colisionaConPersonaje(const sf::Sprite& personaje) const = 0;
};