#include <iostream>
#include "NodoNivel.h"
#pragma once
using namespace std;

class ListaNiveles
{
public:
    NodoNivel *cabeza;

    ListaNiveles()
    {
        cabeza = NULL;
    };

    ListaNiveles(NodoNivel *n)
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
            cout << " el nodo no existe \n"
                 << endl;
            //agregarNivel(ptr);
        }

        return temp;
    }

    NodoNivel *retornarABB(int k)
    {
        NodoNivel *temp = NULL;
        NodoNivel *ptr = cabeza;

        bool encontrado = false;

        while (ptr != NULL)
        {
            if (ptr->id == k)
            {
                //ptr->verArbolObjetos(ptr->getArbol()->raiz);
                temp = ptr;
                temp->verArbolObjetos(ptr->getArbol()->raiz);
                encontrado = true;
            }

            ptr = ptr->siguiente;
        }

        if (!encontrado)
        {
            cout << " el nodo no existe \n"
                 << endl;
            //agregarNivel(ptr);
        }

        return temp;
    }


    // Agregar el nivel a la lista
    void agregarNuevoNivel(NodoNivel *n)
    {
        if (validarSiNodoExiste(n->id) != NULL)
        {
        }
        else
        {
            if (cabeza == NULL)
            {
                cabeza = n;
                std::cout << " Nivel agregado como nodo cabeza" << endl;
                std::cout << n->id << endl;
            }
            else
            {
                NodoNivel *ptr = cabeza;

                while (ptr->siguiente != NULL)
                {
                    ptr = ptr->siguiente;
                }

                ptr->siguiente = n;
                cout << " Nivel agregado. " << endl;
                std::cout << n->id << endl;
            }
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
                cout.flush();
                cout << "    >> Nivel " << temp->id << endl;
                temp = temp->siguiente;
            }
        }
    }

    void crearArbol(int nivel)
    {
        NodoNivel *temp = NULL;
        NodoNivel *ptr = cabeza;
        bool encontrado = false;

        while (ptr != NULL)
        {
            if (ptr->id == nivel)
            {
                temp = ptr;
                temp->setArbol(new ArbolBinario());
                cout << " Arbol creado" << endl;
                cout << temp->getArbol() << endl;
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
    }

    void agregar_nodo_abb(int nivel, int id_objeto, string nombre)
    {
        NodoNivel *temp = NULL;
        NodoNivel *ptr = cabeza;
        bool encontrado = false;
        NodoArbol *nuevo_nodo = new NodoArbol(id_objeto, nombre);
        while (ptr != NULL)
        {
            // encuentra el nivel
            if (ptr->id == nivel)
            {
                temp = ptr;
                //temp->setArbol(new ArbolBinario());
                //cout << " Arbol creado" << endl;
                
                temp->getArbol()->insertarNodo(nuevo_nodo);
                encontrado = true;
            }

            ptr = ptr->siguiente;
        }

        if (!encontrado)
        {
            cout << " Nivel no existente" << endl;
        }
    }
};
/*
ListaNiveles::ListaNiveles()
{
}

ListaNiveles::~ListaNiveles()
{
}
*/