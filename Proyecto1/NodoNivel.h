
#include <iostream>
#include "ArbolBinario.h"
#pragma once
using namespace std;

class NodoNivel
{
public:
    int id; // ID nivel
    NodoNivel *siguiente;
    ArbolBinario *arbolObjetos;
    //Matriz
    //ABB de objetos
    /*
    NodoNivel()
    {
        id = 0;
        siguiente = NULL;
    };*/

    NodoNivel(int n)
    {
        id = n;
        siguiente = NULL;
    }
    ~NodoNivel();
    //mostrarMatriz
    //mostrarABB
};
/*
NodoNivel::NodoNivel()
{
}

NodoNivel::~NodoNivel()
{
}
*/