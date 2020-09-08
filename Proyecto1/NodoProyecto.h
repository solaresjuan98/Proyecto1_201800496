#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class NodoProyecto
{
private:
    int id_proyecto;
    int num_niveles;

public:
    NodoProyecto *siguiente;
    NodoProyecto *anterior;

    NodoProyecto(int id_proyecto, int num_niveles);
    int getID();
    void setID(int id);
    int getNumNiveles();
    void setNumNiveles(int num_niveles);
    ~NodoProyecto();
};

NodoProyecto::NodoProyecto(int id_proyecto, int num_niveles)
{
    this->id_proyecto = id_proyecto;
    this->num_niveles = num_niveles;
    this->siguiente = NULL;
}

void NodoProyecto::setID(int id)
{
    this->id_proyecto = id;   
}

void NodoProyecto::setNumNiveles(int num_niveles)
{
    this->num_niveles = num_niveles;
}

int NodoProyecto::getID()
{
    return this->id_proyecto;
}

int NodoProyecto::getNumNiveles()
{
    return this->num_niveles;
}

NodoProyecto::~NodoProyecto()
{
}
