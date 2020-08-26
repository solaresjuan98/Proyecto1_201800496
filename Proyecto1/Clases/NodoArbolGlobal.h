#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoArbolGlobal
{

public:
    int id;
    string nombre;
    char letra;
    string color;
    //puntos
    int x;
    int y;
    NodoArbolGlobal *izq;
    NodoArbolGlobal *der;
    NodoArbolGlobal *padre;
    NodoArbolGlobal()
    {
        id = 0;
        nombre = "";
        letra = ' ';
        color = "";
        x = 0;
        y = 0;
        izq = NULL;
        der = NULL;
        padre = NULL;
    }

    NodoArbolGlobal(int n, string _nombre, char _letra, string _color, int _x, int _y)
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

    ~NodoArbolGlobal();
};
