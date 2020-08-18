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


public:
    NodoMatriz();
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
};

NodoMatriz::NodoMatriz()
{
    this->arriba = NULL;
    this->abajo = NULL;
    this->izquierda = NULL;
    this->derecha = NULL;
}

NodoMatriz *NodoMatriz::getArriba()
{
    return this->arriba;
}

NodoMatriz *NodoMatriz::getAbajo()
{
    return this->abajo;
}

NodoMatriz *NodoMatriz::getIzquierda()
{
    return this->izquierda;
}

NodoMatriz *NodoMatriz::getDerecha()
{
    return this->derecha;
}

/*
int NodoMatriz::getX()
{
    return this->x;
}

int NodoMatriz::getY()
{
    return this->y;
}
*/
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
