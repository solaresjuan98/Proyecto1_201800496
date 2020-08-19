#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoMatriz
{
private:
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *izquierda;
    NodoMatriz *derecha;
    int x, y;
    string nombreObj;

public:
    NodoMatriz();
    NodoMatriz(int x, int y, string nombre);
    ~NodoMatriz();
    
    void setArriba(NodoMatriz *n);
    void setAbajo(NodoMatriz *n);
    void setIzquierda(NodoMatriz *n);
    void setDerecha(NodoMatriz *n);
    NodoMatriz *getArriba();
    NodoMatriz *getAbajo();
    NodoMatriz *getIzquierda();
    NodoMatriz *getDerecha();
    int getX();
    int getY();
    string getNombreObj();

};


NodoMatriz::NodoMatriz()
{
    this->arriba = NULL;
    this->abajo = NULL;
    this->izquierda = NULL;
    this->derecha = NULL;
}

NodoMatriz::NodoMatriz(int x, int y, string nombre)
{
    this->x = x;
    this->y = y;
    this->nombreObj = nombre;
}

NodoMatriz *NodoMatriz::getArriba()
{
    return this->arriba;
}

NodoMatriz *NodoMatriz::getAbajo()
{
    return this->abajo;//Aquí truena
}

NodoMatriz *NodoMatriz::getIzquierda()
{
    return this->izquierda;
}

NodoMatriz *NodoMatriz::getDerecha()
{
    return this->derecha;
}


int NodoMatriz::getX()
{
    return this->x;
}

int NodoMatriz::getY()
{
    return this->y;
}

string NodoMatriz::getNombreObj()
{
    return this->nombreObj;
}

void NodoMatriz::setArriba(NodoMatriz *n)
{
    this->arriba = n;
}

void NodoMatriz::setAbajo(NodoMatriz *n)
{
    this->abajo = n;
}

void NodoMatriz::setIzquierda(NodoMatriz *n)
{
    this->izquierda = n;
}

void NodoMatriz::setDerecha(NodoMatriz *n)
{
    this->derecha = n;
}

NodoMatriz::~NodoMatriz()
{
}
