#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoProyecto
{
private:
    int id_proyecto;
    int cantidad;

public:
    NodoProyecto *siguiente;
    NodoProyecto *anterior;
    NodoProyecto *ultimo;

    NodoProyecto(int id_proyecto, int cantidad);
    int getID();
    void setID(int id);
    int getNum();
    void setNum(int cantidad);
    ~NodoProyecto();
};

NodoProyecto::NodoProyecto(int id_proyecto, int cantidad)
{
    this->id_proyecto = id_proyecto;
    this->cantidad = cantidad;
    this->siguiente = NULL;
    this->ultimo = NULL;
}

void NodoProyecto::setID(int id)
{
    this->id_proyecto = id;   
}

void NodoProyecto::setNum(int cantidad)
{
    this->cantidad = cantidad;
}

int NodoProyecto::getID()
{
    return this->id_proyecto;
}

int NodoProyecto::getNum()
{
    return this->cantidad;
}

NodoProyecto::~NodoProyecto()
{
}
