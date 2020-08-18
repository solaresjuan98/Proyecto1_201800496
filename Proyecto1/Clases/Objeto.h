#include <iostream>
#include <string.h>
#include "NodoMatriz.h"
#pragma once

// Hereda de la clase NodoMatriz 
class Objeto : public NodoMatriz
{
private:
    //Coordenadas
    int x;
    int y;
    string nombreObj;

public:
    Objeto(int x, int y, string nombre);
    ~Objeto();
    void setX(int x);
    void setY(int y);
    void setNombreObj(string nombre);
    int getX();
    int getY();
    string getNombreObj();
};

Objeto::Objeto(int x, int y, string nombre)
{
    this->x = x;
    this->y = y;
    this->nombreObj = nombre;
}

Objeto::~Objeto()
{
}


int Objeto::getX()
{
    return this->x;
}

int Objeto::getY()
{
    return this->y;
}

string Objeto::getNombreObj()
{
    return this->nombreObj;
}