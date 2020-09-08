#include <iostream>
#include "NodoProyecto.h"
#pragma once
using namespace std;
//Lista doble
class ListaProyectos
{
private:
    /* data */
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
    else if (p_nuevo->getNumNiveles() <= cabeza->getNumNiveles())
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
            if (actual->getNumNiveles() > p_nuevo->getNumNiveles())
            {
                NodoProyecto *ant = actual->anterior;
                ant->siguiente = p_nuevo;
                p_nuevo->anterior = ant;
                p_nuevo->siguiente = actual;
                actual->anterior = p_nuevo;
                return;
            }
            else if (p_nuevo->getNumNiveles() <= actual->siguiente->getNumNiveles())
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
        cout << " >> Cant. Niveles: " << actual->getNumNiveles() << endl;
        cout << endl;
        
        actual = actual->siguiente;
        
    }
    
}

ListaProyectos::~ListaProyectos()
{
}
