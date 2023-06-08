#pragma once
#include "ObjetoInteractivo.h"
class Libro : public ObjetoInteractivo
{
private:
    int _puntaje = 50;

public:
    Libro(const std::string& filename, int puntaje);
    void update();
    void interactuar();
    int getPuntaje() const;
   
};

