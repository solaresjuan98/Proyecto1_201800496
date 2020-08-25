
#include <iostream>
#include <string.h>
#include <fstream>
#pragma once
using namespace std;

class NodoAVL
{

private:
    int id;
    int fe; //factor de equilibrio
    //fstream archivo;//archivo
    NodoAVL *izq;
    NodoAVL *der;

public:
    NodoAVL(int _id);
    //setters
    void setID(int id);
    void setFE(int factor);
    void setIzq(NodoAVL *izq);
    void setDer(NodoAVL *der);
    //void setArchivo(fstream archivo);
    //getters
    //fstream getArchivo();
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
    GETTERS
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
