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

    /*
    NodoArbol()
    {
        id = 0;
        nombre = "";
        izq = NULL;
        der = NULL;
        padre = NULL;
    }
    */

    NodoArbol(int n, string nombre_, string letra_, string color_, int x, int y)
    {
        id = n;
        nombre = nombre_;
        letra = letra_;
        color = color_;
        x = x;
        y = y;
        izq = NULL;
        der = NULL;
    }

    ~NodoArbol();
};
