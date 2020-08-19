
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoObjeto
{
public:
    int x;
    int y;
    string nombreObjeto;
    NodoObjeto *arriba;
    NodoObjeto *abajo;
    NodoObjeto *izquierda;
    NodoObjeto *derecha;

    NodoObjeto()
    {
        x = 0;
        y = 0;
        arriba = NULL;
        abajo = NULL;
        izquierda = NULL;
        derecha = NULL;
    }

    NodoObjeto(int _x, int _y, string nombre)
    {
        x = _x;
        y = _y;
        nombreObjeto = nombre;
    }

    ~NodoObjeto()
    {
    }
};

/*
NodoObjeto::NodoObjeto()
{
}

NodoObjeto::~NodoObjeto()
{
}
*/