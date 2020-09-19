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
    void agregarDato(NodoProyecto *p_nuevo);
    //Agregar de FORMA DESCENDENTE cada datos en funcion del dato numerico que se le envía
    void agregarDatoDesc(NodoProyecto *p_nuevo);

    //Valida si el dato existe
    NodoProyecto *existe(int n); // n-> numero proyecto
    void imprimirLista();
    void imprimirDescendente();
    void imprimirMayor();
    ~ListaProyectos();
};

ListaProyectos::ListaProyectos(NodoProyecto *proyecto)
{
    this->cabeza = proyecto;
}

NodoProyecto *ListaProyectos::existe(int n)
{
    NodoProyecto *temp = NULL;
    NodoProyecto *ptr = cabeza;
    bool encontrado = false;

    while (ptr != NULL)
    {
        if (ptr->getID() == n)
        {
            temp = ptr;
            encontrado = true;
        }

        ptr = ptr->siguiente;
    }

    if (!encontrado)
    {
        // nodo no existe, entonces se puede agregar
    }

    return temp;
}

void ListaProyectos::agregarDato(NodoProyecto *p_nuevo)
{

    if (existe(p_nuevo->getID()) != NULL)
    {
        // NO SE ADMITEN NODOS REPETIDOS
    }
    else
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
}

void ListaProyectos::agregarDatoDesc(NodoProyecto *p_nuevo)
{
    if (existe(p_nuevo->getID()) != NULL)
    {
        // No se aceptan nodos repetidos
    }
    else
    {
        if (cabeza == NULL)
        {
            cabeza = p_nuevo;
        }
        else if (p_nuevo->getNum() >= cabeza->getNum())
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
                if (actual->getNum() < p_nuevo->getNum())
                {
                    NodoProyecto *ant = actual->anterior;
                    ant->siguiente = p_nuevo;
                    p_nuevo->anterior = ant;
                    p_nuevo->siguiente = actual;
                    actual->anterior = p_nuevo;
                    return;
                }
                else if (p_nuevo->getNum() >= actual->siguiente->getNum())
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
}

void ListaProyectos::imprimirLista()
{
    NodoProyecto *actual = cabeza;

    while (actual != NULL)
    {
        cout << " >> Num. : " << actual->getID() << endl;
        cout << " >> Cantidad : " << actual->getNum() << endl;
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

void ListaProyectos::imprimirMayor()
{
    NodoProyecto *actual = cabeza;

    while (actual != NULL)
    {
        if (actual == cabeza)
        {
            cout << " >> Num. : " << actual->getID() << endl;
            cout << " >> Cantidad : " << actual->getNum() << endl;
            cout << endl;
        }

        actual = actual->siguiente;
    }
}

ListaProyectos::~ListaProyectos()
{
}
