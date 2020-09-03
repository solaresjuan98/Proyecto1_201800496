#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoArbol
{

public:
    int id;
    string nombre;
    //string letra;
    //string color;
    //puntos
    //int x;
    //int y;
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

    NodoArbol(int n, string _nombre)
    {
        id = n;
        nombre = _nombre;
        //letra = _letra;
        //color = _color;
        //x = _x;
        //y = _y;
        izq = NULL;
        der = NULL;
    }

    ~NodoArbol();
};
