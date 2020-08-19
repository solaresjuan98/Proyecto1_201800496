
#include <iostream>
#include <string.h>
#include "NodoMatriz.h"
#include "Cabecera.h"
#pragma once
using namespace std;

class Matriz
{
private:
    Cabecera *horizontal;
    Cabecera *vertical;
    Cabecera *getVertical(int columna);
    Cabecera *getHorizontal(int fila);
    Cabecera *crearVertical(int c);
    Cabecera *crearHorizontal(int f);
    NodoMatriz *getUltimoHorizontal(Cabecera *cab, int fila);
    NodoMatriz *getUltimoVertical(Cabecera *cab, int col);

public:
    Matriz();
    ~Matriz();
    void agregar(NodoMatriz *nuevo);
    void imprimirMatriz();
};

Matriz::Matriz()
{
    this->horizontal = NULL;
    this->vertical = NULL;
}

Matriz::~Matriz()
{
}

void Matriz::agregar(NodoMatriz *nuevo)
{
    Cabecera *eje_y = this->getVertical(nuevo->getY());
    Cabecera *eje_x = this->getHorizontal(nuevo->getX());

    if(vertical == NULL)
    {
        eje_y = crearVertical(nuevo->getY());
        //cout <<  nuevo->getNombreObj();
        cout << " vertical creado\n";
    }

    if(horizontal == NULL)
    {
        eje_x = crearHorizontal(nuevo->getX());
        //cout << nuevo->getNombreObj();
        cout << " horizontal creado\n";
    }

    NodoMatriz *izq = getUltimoHorizontal(vertical, nuevo->getX());
    NodoMatriz *sup = getUltimoVertical(horizontal, nuevo->getY());

    if(izq->getDerecha() == NULL)
    {
        izq->setDerecha(nuevo);
        nuevo->setIzquierda(izq);
    }
    else{
        NodoMatriz *tmp = izq->getDerecha();
        izq->setDerecha(nuevo);
        nuevo->setIzquierda(izq);
        tmp->setIzquierda(nuevo);
        nuevo->setDerecha(tmp);
    }


    if(sup->getAbajo() == NULL)
    {
        sup->setAbajo(nuevo);
        nuevo->setArriba(sup);
    }
    else{
        NodoMatriz *tmp = sup->getAbajo();
        sup->setAbajo(nuevo);
        nuevo->setArriba(sup);
        tmp->setArriba(nuevo);
        nuevo->setAbajo(tmp);
    }

}

Cabecera *Matriz::crearVertical(int col)
{
    if (this->vertical == NULL)
    {
        Cabecera *nuevo = new Cabecera(col);
        this->vertical = nuevo;
        return nuevo;
    }

    Cabecera *aux = this->vertical;

    if (col == aux->getY())
    {
        Cabecera *nuevo = new Cabecera(col);
        nuevo->setAbajo(this->vertical);
        this->vertical->setArriba(nuevo);
        this->vertical = nuevo;
        return nuevo;
    }

    while (aux->getAbajo() != NULL)
    {
        // si la coor.
        if (col == aux->getY())
        {
            Cabecera *nuevo = new Cabecera(col);
            Cabecera *tmp = (Cabecera *)aux->getAbajo();
            tmp->setArriba(nuevo);
            nuevo->setAbajo(tmp);
            aux->setAbajo(nuevo);
            nuevo->setArriba(aux);
            return nuevo;
        }

        aux = (Cabecera *)aux->getAbajo();
    }

    Cabecera *nuevo = new Cabecera(col);
    aux->setAbajo(nuevo);
    nuevo->setArriba(aux);
    return nuevo;
}

Cabecera *Matriz::crearHorizontal(int fila)
{
    if (this->horizontal == NULL)
    {
        Cabecera *nuevo = new Cabecera(fila);
        this->horizontal = nuevo;
        return nuevo;
    }

    Cabecera *aux = this->horizontal;

    if (fila <= aux->getY())
    {
        Cabecera *nuevo = new Cabecera(fila);
        nuevo->setDerecha(aux);
        this->horizontal->setIzquierda(nuevo);
        this->horizontal = nuevo;
        return nuevo;
    }

    while (aux->getDerecha() != NULL)
    {
        // si la coor.
        if (fila <= aux->getY())
        {
            Cabecera *nuevo = new Cabecera(fila);
            Cabecera *tmp = (Cabecera *)aux->getDerecha();
            tmp->setIzquierda(nuevo);
            nuevo->setDerecha(tmp);
            aux->setDerecha(nuevo);
            nuevo->setIzquierda(aux);
            return nuevo;
        }

        aux = (Cabecera *)aux->getDerecha();
    }

    Cabecera *nuevo = new Cabecera(fila);
    aux->setDerecha(nuevo);
    nuevo->setIzquierda(aux);
    return nuevo;
}

Cabecera *Matriz::getVertical(int columna)
{
    if (this->vertical == NULL)
    {
        return NULL;
    }

    Cabecera *aux = this->vertical;

    while (aux != NULL)
    {
        if (aux->getY() == columna)
        {
            return aux;
        }

        aux = (Cabecera *)aux->getAbajo();
    }

    return NULL;
}

Cabecera *Matriz::getHorizontal(int fila)
{
    if (this->horizontal == NULL)
    {
        return NULL;
    }

    Cabecera *aux = this->horizontal;

    while (aux != NULL)
    {
        if (aux->getX() == fila)
        {
            return aux;
        }

        aux = (Cabecera *)aux->getDerecha();
    }

    return aux;
}

NodoMatriz *Matriz::getUltimoHorizontal(Cabecera *cab, int fila)
{
    if (cab->getDerecha() == NULL)
    {
        return cab;
    }

    NodoMatriz *aux = cab->getDerecha();

    while (aux->getDerecha() != NULL)
    {
        if (fila <= aux->getY())
        {
            return aux;
        }

        aux = aux->getDerecha();
    }

    if (fila <= aux->getY())
    {
        return aux->getIzquierda();
    }

    return aux;
}

NodoMatriz *Matriz::getUltimoVertical(Cabecera *cab, int col)
{
    if (cab->getAbajo() == NULL)
    {
        return cab;
    }

    NodoMatriz *aux = cab->getDerecha();

    while (aux->getAbajo() != NULL)
    {
        if (col <= aux->getX())
        {
            return aux;
        }

        aux = aux->getAbajo();
    }

    if (aux->getX() <= col)
    {
        return aux->getArriba();
    }

    return aux;
}

void Matriz::imprimirMatriz()
{
    NodoMatriz *eje_y;
    NodoMatriz *eje_x;

    eje_y = this->vertical;
    eje_x = this->horizontal;


    while (eje_x != NULL)
    {
        cout << &(*eje_x) << ((Cabecera *)eje_x)->getNombreObj() << " - ";
        eje_x = eje_x->getAbajo();

        
        while (eje_x != NULL)
        {
            cout << &(*eje_y) << ((Cabecera *)eje_y)->getNombreObj() << " - ";
            eje_y = eje_y->getDerecha();
        }
        
    }
    
}
