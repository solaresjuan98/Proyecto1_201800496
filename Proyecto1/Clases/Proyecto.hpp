
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class Proyecto
{
private:
    int IDProyecto;

public:
    //Metodos
    Proyecto(int id);
    ~Proyecto();
    int getIdProyecto();
    //agregarNiveles(int n)
    //mostrarListaNiveles()
    //agregar a AVL de proyectos
};

Proyecto::Proyecto(int id)
{
    this->IDProyecto = id;
}

int Proyecto::getIdProyecto()
{
    return IDProyecto;
}

//Destructor
Proyecto::~Proyecto()
{
}
