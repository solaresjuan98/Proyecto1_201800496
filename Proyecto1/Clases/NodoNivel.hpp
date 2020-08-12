
#include <iostream>
#pragma once
using namespace std;

class NodoNivel
{
public:
    int id; // ID nivel
    NodoNivel *siguiente;
    NodoNivel *anterior;
    //Matriz
    //ABB
    NodoNivel()
    {
        id = 0;
        siguiente = NULL;
        anterior = NULL ;
    };

    NodoNivel(int n)
    {
        id = n;
    }
    //~NodoNivel();
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