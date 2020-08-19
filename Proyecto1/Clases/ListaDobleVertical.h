#include <iostream>
#include <string.h>
#include "NodoObjeto.h"
#pragma once
using namespace std;

class ListaDobleVertical
{
public:
    NodoObjeto *cabeza;

    ListaDobleVertical()
    {
        cabeza = NULL;
    };

    ListaDobleVertical(NodoObjeto *n)
    {
        cabeza = n;
    }

    // 1. Validar si el nodo existe
    NodoObjeto *validarSiNodoExiste(int x, int y)
    {
        NodoObjeto *temp = NULL;
        NodoObjeto *ptr = cabeza;
        bool encontrado = false;

        while (ptr != NULL)
        {
            if (ptr->x == x && ptr->y == y)
            {
                temp = ptr;
                encontrado = true;
            }

            ptr = ptr->abajo;
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
    void agregarNuevoObjeto(NodoObjeto *n)
    {

        if (cabeza == NULL)
        {
            cabeza = n;
            //std::cout << " Nivel agregado como nodo cabeza" << endl;
        }
        else
        {
            NodoObjeto *ptr = cabeza;

            while (ptr->abajo != NULL)
            {
                ptr = ptr->abajo;
            }

            ptr->abajo = n;
            n->arriba = ptr;
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
            NodoObjeto *temp = cabeza;

            while (temp != NULL)
            {
                cout << "[ " << temp->x << " " << temp->y << " ] " << temp->nombreObjeto << endl;
                temp = temp->abajo;
            }

        }
    }
};
/*
ListaDobleVertical::ListaDobleVertical()
{
}

ListaDobleVertical::~ListaDobleVertical()
{
}
*/