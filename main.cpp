#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "Caracter.h"
#include "Enemigo.h"
#include "Libro.h"

int main()
{
    //Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Librarian Deichu");
    window.setFramerateLimit(60);
    Personaje dei;
    Enemigo jabru;
    int puntajeLibro = 50;
    Libro libro("librosdef.png", puntajeLibro);


    sf::Sprite background;
    sf::Texture bg;
    bg.loadFromFile("background.gif");
    background.setTexture(bg);

  
    
    //Bucle principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Actualizar estados
        dei.update();
        libro.interactuar();
        jabru.update();
        window.clear();
        //Dibujar gilada
        window.draw(background);
        window.draw(dei);
        window.draw(libro);
        window.draw(jabru);

        //Mostrar gilada
        window.display();
    }

    return 0;
}