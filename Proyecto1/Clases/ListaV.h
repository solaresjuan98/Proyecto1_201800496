#include <iostream>
#include <string.h>
#include "Objeto.h"
#include "Objeto.h"
#pragma once
using namespace std;

class ListaV
{
public:
    Objeto *primero;
    Objeto *ultimo;

public:
    ListaV();
    ~ListaV();
    void insertar(Objeto *obj);
    void insertarFrente(Objeto *obj);
    void insertarMedio(Objeto *obj);
    void insertarFinal(Objeto *obj);
    bool estaVacia();
};

ListaV::ListaV()
{
    this->primero = NULL;
    this->ultimo = NULL;
}

ListaV::~ListaV()
{
}

void ListaV::insertar(Objeto *obj)
{
    /*if (estaVacia())
    {
        primero = ultimo = obj;
    }
    else
    {
        if (obj->getY() < primero->getY())
        {
            //insertar al frente
            insertarFrente(obj);
        }
        else if (obj->getY() > ultimo->getY())
        {
            //insertar al final
            insertarFinal(obj);
        }
        else
        {
            // insercion en medio
            insertarMedio(obj);
        }
    }*/

    if(primero == NULL)
    {
        primero = obj;
        std::cout << " Objeto agregado al principio.";

    }else{
        Objeto *ptr = primero;

        while (ptr->getAbajo() != NULL)
        {
            ptr = ptr->getAbajo();
        }
        
    }
}

void ListaV::insertarFrente(Objeto *obj)
{
    //Objeto *tmp = primero->getArriba;

    /*primero->getArriba()* =* obj;
    obj->getAbajo() = primero;
    primero = primero->getArriba();*/

    //25.32
}

void ListaV::insertarFinal(Objeto *obj)
{
    //ultimo->getAbajo() =obj;
    //primero->getAbajo() = obj;
}

bool ListaV::estaVacia()
{
    if (this->primero == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}