#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoProyecto
{
private:
    int id_proyecto;
    int cantidad;
    int num_nivel;
public:
    NodoProyecto *siguiente;
    NodoProyecto *anterior;
    NodoProyecto *ultimo;

    NodoProyecto(int id_proyecto, int cantidad);
    NodoProyecto(int id_proyecto, int nivel, int num_obj);
    int getID();
    void setID(int id);
    int getNum();
    void setNum(int cantidad);
    int getNivel();
    void setNivel(int cantidad);
    ~NodoProyecto();
};

NodoProyecto::NodoProyecto(int id_proyecto, int cantidad)
{
    this->id_proyecto = id_proyecto;
    this->cantidad = cantidad;
    this->siguiente = NULL;
    this->ultimo = NULL;
}

NodoProyecto::NodoProyecto(int id_proyecto, int nivel, int num_obj)
{
    this->id_proyecto = id_proyecto;
    this->num_nivel = nivel;
    this->cantidad = num_obj;
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

void NodoProyecto::setNivel(int nivel)
{
    this->num_nivel = nivel;
}

int NodoProyecto::getID()
{
    return this->id_proyecto;
}

int NodoProyecto::getNum()
{
    return this->cantidad;
}

int NodoProyecto::getNivel()
{
    return this->num_nivel;
}

NodoProyecto::~NodoProyecto()
{
}
