#include <iostream>
#include <string.h>
#include "NodoMatriz.h"
#pragma once
using namespace std;

class Cabecera : public NodoMatriz
{
private:
    string nombre;
    int fila, columna;

public:
    Cabecera(int fila);
    //Cabecera(int columna);
    void setFila(int f);
    void setColumna(int c);
    int getFila();
    int getColumna();
    ~Cabecera();
};

Cabecera::Cabecera(int fila)
{
    this->fila = fila;
}

/*Cabecera::Cabecera(int columna)
{

    this->columna = columna;
}*/

void Cabecera::setFila(int f)
{
    this->fila = f;
}

void Cabecera::setColumna(int c)
{
    this->columna = c;
}

int Cabecera::getFila()
{
    return this->fila;
}

int Cabecera::getColumna()
{
    return this->columna;
}

Cabecera::~Cabecera()
{
}
