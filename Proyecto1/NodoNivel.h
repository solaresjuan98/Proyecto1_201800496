
#include <iostream>
#include "ArbolBinario.h"

#pragma once
using namespace std;

class NodoNivel
{
private:
    //Apuntar a nodo de objetos
    ArbolBinario *arbol = new ArbolBinario();

public:
    int id; // ID nivel
    NodoNivel *siguiente;
    //Matriz

    void setArbol(ArbolBinario *abb);
    ArbolBinario *getArbol();
    void verArbolObjetos(NodoArbol *arbol); // imprime en in order
    

    NodoNivel(int n)
    {
        id = n;
        siguiente = NULL;
    }
    ~NodoNivel();
    //mostrarMatriz
    //mostrarABB
};

void NodoNivel::setArbol(ArbolBinario *abb)
{
    this->arbol = abb;
}

ArbolBinario *NodoNivel::getArbol()
{
    return this->arbol;// aqui muere
}

void NodoNivel::verArbolObjetos(NodoArbol *arbol)
{
    this->arbol->inOrden(arbol);
}

/*
NodoNivel::NodoNivel()
{
}

NodoNivel::~NodoNivel()
{
}
*/