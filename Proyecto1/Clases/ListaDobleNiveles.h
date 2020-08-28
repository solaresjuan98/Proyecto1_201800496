#include <iostream>
#include <string.h>
#include "NodoNivel.h"
#pragma once
using namespace std;

class ListaDobleNiveles
{
public:
    NodoNivel *cabeza;

    ListaDobleNiveles()
    {
        cabeza = NULL;
    };

    ListaDobleNiveles(NodoNivel *n)
    {
        cabeza = n;
    }

    // 1. Validar si el nodo existe
    NodoNivel *validarSiNodoExiste(int k)
    {
        NodoNivel *temp = NULL;
        NodoNivel *ptr = cabeza;
        bool encontrado = false;

        while (ptr != NULL)
        {
            if (ptr->id == k)
            {
                temp = ptr;
                encontrado = true;
            }

            ptr = ptr->siguiente;
        }

        if (!encontrado)
        {
            //cout << " el nodo no existe \n"
            //     << endl;
            //agregarNivel(ptr);
        }

        return temp;
    }

    // Agregar el nivel a la lista
    void agregarNuevoNivel(NodoNivel *n)
    {

        if (cabeza == NULL)
        {
            cabeza = n;
            std::cout << " Nivel agregado como nodo cabeza" << endl;
        }
        else
        {
            NodoNivel *ptr = cabeza;

            while (ptr->siguiente != NULL)
            {
                ptr = ptr->siguiente;
            }

            ptr->siguiente = n;
            n->anterior = ptr;
            cout << " Nivel agregado. " << endl;
        }
    }

    void imprimirLista()
    {
        if (cabeza == NULL)
        {
            std::cout << " lista vacia." << endl;
        }
        else
        {
            std::cout << " Valores de lista : " << endl;
            NodoNivel *temp = cabeza;

            while (temp != NULL)
            {
                cout << " Nivel " << temp->id << endl;
                temp = temp->siguiente;
            }
        }
    }
    //~ListaDobleNiveles();
};
/*
ListaDobleNiveles::ListaDobleNiveles()
{
}

ListaDobleNiveles::~ListaDobleNiveles()
{
}
*/