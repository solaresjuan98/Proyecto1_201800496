#include <iostream>
#include "NodoProyecto.h"
#pragma once
using namespace std;
//Lista doble
class ListaProyectos
{
private:
    
public:
    NodoProyecto *cabeza;

    ListaProyectos()
    {
        cabeza = NULL;
    };

    ListaProyectos(NodoProyecto *proyecto);
    //Agregar DE FORMA ASCENDENTE cada proyecto en función de la cantidad de niveles que tiene
    void agregarProyecto(NodoProyecto *p_nuevo);
    void imprimirLista();
    void imprimirDescendente();
    ~ListaProyectos();
};

ListaProyectos::ListaProyectos(NodoProyecto *proyecto)
{
    this->cabeza = proyecto;
}

void ListaProyectos::agregarProyecto(NodoProyecto *p_nuevo)
{
    if (cabeza == NULL)
    {
        cabeza = p_nuevo;
    }
    else if (p_nuevo->getNum() <= cabeza->getNum())
    {
        p_nuevo->siguiente = cabeza;
        cabeza->anterior = p_nuevo;
        cabeza = p_nuevo;
    }
    else
    {
        NodoProyecto *actual = cabeza;

        while (actual->siguiente != NULL)
        {
            if (actual->getNum() > p_nuevo->getNum())
            {
                NodoProyecto *ant = actual->anterior;
                ant->siguiente = p_nuevo;
                p_nuevo->anterior = ant;
                p_nuevo->siguiente = actual;
                actual->anterior = p_nuevo;
                return;
            }
            else if (p_nuevo->getNum() <= actual->siguiente->getNum())
            {
                NodoProyecto *sig = actual->siguiente;
                actual->siguiente = p_nuevo;
                p_nuevo->siguiente = actual;
                p_nuevo->siguiente = sig; 
                sig->anterior = p_nuevo;
                return;
            }

            actual = actual->siguiente;
        }
        actual->siguiente = p_nuevo;
        p_nuevo->anterior = actual;
    }
}

void ListaProyectos::imprimirLista()
{
    NodoProyecto *actual = cabeza;

    while (actual != NULL)
    {
        cout << " >> Id. Proyecto: " << actual->getID() << endl;
        cout << " >> Cant. Niveles: " << actual->getNum() << endl;
        cout << endl;

        actual = actual->siguiente;
    }
}

void ListaProyectos::imprimirDescendente()
{
    NodoProyecto *actual = cabeza;

    while (actual != NULL)
    {
        //cout << " >> Id. Proyecto: " << actual->getID() << endl;
        //cout << " >> Cant. Niveles: " << actual->getNum() << endl;
        //cout << endl;

        actual = actual->siguiente;
    }

    NodoProyecto *aux = cabeza;

    while (!cabeza)
    {

        cout << " >> Id. Proyecto: " << actual->getID() << endl;
        cout << " >> Cant. Niveles: " << actual->getNum() << endl;

        aux = aux->anterior;
    }
}

ListaProyectos::~ListaProyectos()
{
}
