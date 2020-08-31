#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoArbol
{

public:
    int id;
    string nombre;
    string letra;
    string color;
    //puntos
    int x;
    int y;
    NodoArbol *izq;
    NodoArbol *der;
    NodoArbol *padre;
    NodoArbol()
    {
        id = 0;
        nombre = "";
        letra = "";
        color = "";
        x = 0;
        y = 0;
        izq = NULL;
        der = NULL;
        padre = NULL;
    }

    NodoArbol(int n, string _nombre, string _letra, string _color, int _x, int _y)
    {
        id = n;
        nombre = _nombre;
        letra = _letra;
        color = _color;
        x = _x;
        y = _y;
        izq = NULL;
        der = NULL;
    }

    ~NodoArbol();
};
