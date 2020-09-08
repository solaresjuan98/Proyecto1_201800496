
#include <iostream>
#include "NodoArbol.h"
#define SPACE 10
#pragma once
using namespace std;

class ArbolBinario
{
public:
    NodoArbol *raiz;
    ArbolBinario();

    bool estaVacio()
    {
        if (raiz == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertarNodo(NodoArbol *nuevo_nodo)
    {
        if (raiz == NULL)
        {
            raiz = nuevo_nodo;
            //cout << " insertado al inicio :)" << endl;
        }
        else
        {
            NodoArbol *temp = raiz;

            while (temp != NULL)
            {
                if (nuevo_nodo->id == temp->id)
                {
                    //cout << " Nodo repetido, intenta de nuevo :'v" << endl;
                    return; // no se aceptan nodos repetidos
                }
                else if (nuevo_nodo->id < temp->id && temp->izq == NULL)
                {
                    // insertar nodo en hijo izquierdo
                    temp->izq = nuevo_nodo;
                    //cout << " Nodo insertado a la izq :)" << endl;
                    break;
                }
                else if (nuevo_nodo->id < temp->id)
                {
                    temp = temp->izq;
                }
                else if (nuevo_nodo->id > temp->id && temp->der == NULL)
                {
                    // insertar nodo en hijo derecho
                    temp->der = nuevo_nodo;
                    //cout << " id insertado a la der :)" << endl;
                    break;
                }
                else
                {
                    // pasar a nodo siguiente
                    temp = temp->der;
                }
            }
        }
    }

    void imprimirArbol(NodoArbol *raiz, int cont)
    {
        if (raiz == NULL)
        {
            //cout << " Arbol vacío :'v"<<endl;
            return;
        }
        else
        {
            imprimirArbol(raiz->der, cont + 1);
            for (int i = 0; i < cont; i++)
            {
                cout << "   ";
            }

            cout << "["<<raiz->id << " " <<raiz->nombre << "]"<<endl;
            imprimirArbol(raiz->izq, cont + 1);
        }
    }

    void preOrden(NodoArbol *arbol)
    {
        if (arbol == NULL)
        {
            return;
        }
        else
        {
            cout << arbol->id << " - ";
            preOrden(arbol->izq);
            preOrden(arbol->der);
        }
    }

    void inOrden(NodoArbol *arbol)
    {

        if (arbol == NULL)
        {
            return;
        }
        else
        {
            inOrden(arbol->izq);
            cout << arbol->id << endl;
            cout << arbol->nombre << endl;
            inOrden(arbol->der);
        }
    }

    void postOrden(NodoArbol *arbol)
    {
        if (arbol == NULL)
        {
            return;
        }
        else
        {
            postOrden(arbol->izq);
            postOrden(arbol->der);
            cout << arbol->id << " - ";
        }
    }

    void destruirNodo(NodoArbol *nodo)
    {
        nodo->izq = NULL;
        nodo->der = NULL;

        delete nodo;
    }

    void eliminar(NodoArbol *arbol, int n)
    {
        if (arbol == NULL)
        {
            return;
        }
        else if (n < arbol->id)
        {
            eliminar(arbol->izq, n);
        }
        else if (n > arbol->id)
        {
            eliminar(arbol->der, n);
        }
        else
        {
            EliminarNodo(arbol);
        }
    }

    // Determinar el nodo más izquierdo

    NodoArbol *minimo(NodoArbol *raiz)
    {
        if (raiz == NULL)
        {
            return NULL;
        }

        if (raiz->izq)
        {
            //cout << raiz->izq->id << endl;
            //cout << raiz->der->id << endl;
            return minimo(raiz->izq);
        }
        else
        {

            return raiz;
        }
    }

    // Reemplazar Nodo
    void reemplazarNodo(NodoArbol *nodoEliminar, NodoArbol *nuevo)
    {
        if (nodoEliminar == raiz)
        {
            if (nodoEliminar->id == nodoEliminar->izq->id)
            {
                nodoEliminar->izq = nuevo;
            }
            else if (nodoEliminar->id == nodoEliminar->der->id)
            {
                nodoEliminar->der = nuevo;
            }
        }
        if (nuevo)
        {
            raiz = nodoEliminar;
        }
    }

    void EliminarNodo(NodoArbol *nodoEliminar)
    {

        if (nodoEliminar->izq && nodoEliminar->der)
        {
            NodoArbol *menor = minimo(nodoEliminar->der);
            nodoEliminar->id = menor->id;
            EliminarNodo(menor);
        }
        else if (nodoEliminar->izq)
        {
            reemplazarNodo(nodoEliminar, nodoEliminar->izq);
            destruirNodo(nodoEliminar);
        }
        else if (nodoEliminar->der)
        {
            reemplazarNodo(nodoEliminar, nodoEliminar->der);
            destruirNodo(nodoEliminar);
        }
        else
        {
            reemplazarNodo(nodoEliminar, NULL);
            destruirNodo(nodoEliminar);
        }
    }

    ~ArbolBinario();
};

ArbolBinario::ArbolBinario()
{
}

ArbolBinario::~ArbolBinario()
{
}
