
#include <iostream>
#include <string.h>
#include "ListaDobleNiveles.hpp"
#include "NodoNivel.hpp"
#pragma once
using namespace std;

class Proyecto
{
private:
    int IDProyecto;

public:
    ListaDobleNiveles lista;
    NodoNivel *nodo = new NodoNivel();
    //Metodos
    Proyecto();
    Proyecto(int id);
    ~Proyecto();
    int getIdProyecto();
    void agregarNivel(int n);
    void verNiveles();
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
    //cout << " agregando nivel " << numeroNivel << "..." << endl;
    nodo->id = numeroNivel;
    lista.agregarNuevoNivel(nodo);
}

void Proyecto::verNiveles()
{
   lista.imprimirLista();
}

//Destructor
Proyecto::~Proyecto()
{
}
