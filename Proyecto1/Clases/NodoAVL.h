#include <iostream>
#include <string.h>
#include <fstream>
#include "ListaNiveles.h"
#pragma once
using namespace std;

class NodoAVL
{

private:
    int id;
    int fe;
    NodoAVL *izq;
    NodoAVL *der;
    // apuntar a Lista de niveles
    //ListaNiveles *lista;

public:
    NodoAVL(int _id);
    //setters
    void setID(int id);
    void setFE(int factor);
    void setIzq(NodoAVL *izq);
    void setDer(NodoAVL *der);
    //void setLista(ListaNiveles *lista);

    //getters
    NodoAVL *getDer();
    NodoAVL *getIzq();
    int getFE();
    int getID();
    
    //otros metodos
    void leerArchivo();

    ~NodoAVL();
};

NodoAVL::NodoAVL(int _id)
{
    this->id = _id;
    this->izq = NULL;
    this->der = NULL;
}

/*
    SETTERS
*/

void NodoAVL::setID(int id)
{
    this->id = id;
}

void NodoAVL::setFE(int factor)
{
    this->fe = factor;
}

void NodoAVL::setIzq(NodoAVL *izq)
{
    this->izq = izq;
}

void NodoAVL::setDer(NodoAVL *der)
{
    this->der = der;
}
/*
void NodoAVL::setLista(ListaNiveles *lista)
{
    this->lista = lista;
}
*/
int NodoAVL::getFE()
{
    return this->fe;
}

int NodoAVL::getID()
{
    return this->id;
}

NodoAVL *NodoAVL::getIzq()
{
    return this->izq;
}

NodoAVL *NodoAVL::getDer()
{
    return this->der;
}

NodoAVL::~NodoAVL()
{
}

