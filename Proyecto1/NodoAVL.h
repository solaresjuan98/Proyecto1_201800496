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
    ListaNiveles *lista = new ListaNiveles();

public:
    NodoAVL(int _id);
    //setters
    void setID(int id);
    void setFE(int factor);
    void setIzq(NodoAVL *izq);
    void setDer(NodoAVL *der);
    void setLista(ListaNiveles *lista);
    void agregarNivel(NodoNivel *n);
    //getters
    NodoAVL *getDer();
    NodoAVL *getIzq();
    int getFE();
    int getID();
    ListaNiveles *getLista();
    
    //otros metodos
    void imprimirLista(ListaNiveles *lista);

    ~NodoAVL();
};


NodoAVL::NodoAVL(int _id)
{
    this->id = _id;
    this->izq = NULL;
    this->der = NULL;
    //this->lista = NULL;
}


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

void NodoAVL::setLista(ListaNiveles *lista)
{
    this->lista = lista;
}

ListaNiveles *NodoAVL::getLista()
{
    return this->lista;
}

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
    return this->izq;// Truena aqui al borrar dos veces raiz
}

NodoAVL *NodoAVL::getDer()
{
    return this->der;
}

void NodoAVL::imprimirLista(ListaNiveles *l)
{
    this->lista->imprimirLista();
}

void NodoAVL::agregarNivel(NodoNivel *n)
{
    this->lista->agregarNuevoNivel(n);
}

NodoAVL::~NodoAVL()
{
}


