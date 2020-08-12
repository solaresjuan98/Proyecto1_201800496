
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
    Proyecto();
    Proyecto(int id);
    ~Proyecto();
    int getIdProyecto();
    void agregarNivel(int n);
    //mostrarListaNiveles()
    //agregar a AVL de proyectos
};

Proyecto::Proyecto()
{

}

Proyecto::Proyecto(int id)
{
    this->IDProyecto = id;
}

int Proyecto::getIdProyecto()
{
    return IDProyecto;
}

//Agregar niveles al proyecto
void Proyecto::agregarNivel(int numeroNivel)
{
    cout << " agregando nivel " << numeroNivel << "..." << endl;
}

//Destructor
Proyecto::~Proyecto()
{
}
