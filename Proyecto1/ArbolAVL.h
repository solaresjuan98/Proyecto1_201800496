#include <iostream>
#include <stdbool.h>
#include <string.h>
#include "NodoAVL.h"
#pragma once
using namespace std;

class ArbolAVL
{
private:
    NodoAVL *raiz;
    NodoAVL *insertar(NodoAVL *raiz, int dato, bool &hc); //hc valor de escape
public:
    ArbolAVL();
    ~ArbolAVL();
    void insertar(int valor);
    NodoAVL *rotacionII(NodoAVL *n, NodoAVL *n1);
    NodoAVL *rotacionDD(NodoAVL *n, NodoAVL *n1);
    NodoAVL *rotacionIzqDer(NodoAVL *n, NodoAVL *n1);
    NodoAVL *rotacionDerIzq(NodoAVL *n, NodoAVL *n1);
    NodoAVL *getRaiz();
    void setRaiz(NodoAVL *n);
    //Recorridos
    void inOrden(NodoAVL *n);
    void postOrden(NodoAVL *n);
    void preOrden(NodoAVL *n);
    bool busqueda(NodoAVL *n, int id);
    void imprimir(NodoAVL *raiz, int cont);

    // Listas en nodo
    void crearListaNiveles(NodoAVL *raiz, int id);
    void insertarNivel(NodoAVL *raiz, int id, int numeroNivel);
    void obtenerListaNodo(NodoAVL *raiz, int id);
    //
    void generar();
    void Delete(NodoAVL *raiz);
};

ArbolAVL::ArbolAVL()
{
    this->raiz = NULL;
}

ArbolAVL::~ArbolAVL()
{
    Delete(this->raiz);
}

NodoAVL *ArbolAVL::getRaiz()
{
    return this->raiz;
}

void ArbolAVL::setRaiz(NodoAVL *n)
{
    this->raiz = n;
}

void ArbolAVL::Delete(NodoAVL *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    Delete(raiz->getIzq());
    Delete(raiz->getDer());
}

NodoAVL *ArbolAVL::rotacionII(NodoAVL *n, NodoAVL *n1)
{
    n->setIzq(n1->getDer());
    n1->setDer(n);

    // no tenia hijos
    if (n1->getFE() == -1)
    {
        n->setFE(0);
        n1->setFE(0);
    }
    else
    {
        n->setFE(-1); //se va ir a su izq
        n1->setFE(1);
    }

    return n1;
}

NodoAVL *ArbolAVL::rotacionDD(NodoAVL *n, NodoAVL *n1)
{
    n->setDer(n1->getIzq());
    n1->setIzq(n);

    if (n1->getFE() == 1) //solo tenia un hijo a la derecha
    {
        n->setFE(0);
        n1->setFE(0);
    }
    else
    {
        n->setFE(1);
        n1->setFE(-1);
    }

    return n1;
}

NodoAVL *ArbolAVL::rotacionIzqDer(NodoAVL *n, NodoAVL *n1)
{
    NodoAVL *n2 = n1->getDer();
    n->setIzq(n2->getDer());
    n2->setDer(n);
    n1->setDer(n2->getIzq());
    n2->setIzq(n1);

    if (n2->getFE() == 1)
    {
        n1->setFE(-1);
    }
    else
    {
        n1->setFE(0);
    }

    if (n2->getFE() == -1)
    {
        n->setFE(1);
    }
    else
    {
        n->setFE(0);
    }

    n2->setFE(0);

    return n2;
}

NodoAVL *ArbolAVL::rotacionDerIzq(NodoAVL *n, NodoAVL *n1)
{
    NodoAVL *n2 = n1->getIzq();
    n->setDer(n2->getIzq());
    n2->setIzq(n);
    n1->setIzq(n2->getDer());
    n2->setDer(n1);

    if (n2->getFE() == 1) // solo trae un hijo der
    {
        n->setFE(-1);
    }
    else
    {
        n->setFE(0);
    }

    if (n2->getFE() == -1) // solo trae un hijo hacia la izq
    {
        n1->setFE(1);
    }
    else
    {
        n1->setFE(0);
    }

    n2->setFE(0);

    return n2;
}

NodoAVL *ArbolAVL::insertar(NodoAVL *raiz, int dato, bool &hc)
{
    NodoAVL *n1;

    if (raiz == NULL)
    {
        raiz = new NodoAVL(dato);
        hc = true;
    }
    else if (dato < raiz->getID())
    {
        NodoAVL *izq = insertar(raiz->getIzq(), dato, hc);
        raiz->setIzq(izq);

        if (hc)
        {
            switch (raiz->getFE())
            {
            case 1:
                // ya trae un hijo hacia la derecha
                raiz->setFE(0);
                hc = false;
                break;
            case 0:
                // no llevaba ningún hijo
                raiz->setFE(-1);
                break;
            case -1:
                n1 = raiz->getIzq();
                if (n1->getFE() == -1)
                {
                    raiz = rotacionII(raiz, n1);
                }
                else
                {
                    raiz = rotacionIzqDer(raiz, n1);
                }
                hc = false;
                break;
            }
        }
    }
    else if (dato > raiz->getID())
    {
        NodoAVL *der = insertar(raiz->getDer(), dato, hc);
        raiz->setDer(der);

        if (hc)
        {
            switch (raiz->getFE())
            {
            case 1:
                //crecio hacia la derecha
                n1 = raiz->getDer();

                //crecio dos veces hacia la derecha
                if (n1->getFE() == 1)
                {
                    raiz = rotacionDD(raiz, n1);
                }
                else
                {
                    raiz = rotacionDerIzq(raiz, n1);
                }
                hc = false;
                break;
            //no tenia ningún hijo
            case 0:
                raiz->setFE(1);
                break;
            //
            case -1:
                raiz->setFE(0);
                break;
            default:
                break;
            }
        }
    }

    return raiz;
}

void ArbolAVL::insertar(int valor)
{
    bool b = false;
    bool *a = &b;

    this->raiz = insertar(this->raiz, valor, *a);
}

void ArbolAVL::imprimir(NodoAVL *raiz, int cont)
{
    if (raiz == NULL)
    {
        return;
    }
    else
    {
        imprimir(raiz->getDer(), cont + 1);

        for (int i = 0; i < cont; i++)
        {
            std::cout << "  ";
        }

        std::cout << raiz->getID() << endl;
        imprimir(raiz->getIzq(), cont + 1);
    }
}


void ArbolAVL::inOrden(NodoAVL *actual)
{
    if (actual == NULL)
    {
        return;
    }
    else
    {
        inOrden(actual->getIzq());
        std::cout << " Proyecto: " << actual->getID() << endl;
        inOrden(actual->getDer());
    }
}

bool ArbolAVL::busqueda(NodoAVL *nodo, int id)
{
    if (nodo == NULL)
    {
        return false;
    }
    else if (nodo->getID() == id)
    {
        return true;
    }
    else if (id < nodo->getID())
    {
        return busqueda(nodo->getIzq(), id);
    }
    else
    {
        return busqueda(nodo->getDer(), id);
    }
}


void ArbolAVL::crearListaNiveles(NodoAVL *nodo, int n)
{
    if (busqueda(nodo, n))
    {
        std::cout << " encontrado " << endl;
        //ListaNiveles *l = new ListaNiveles();
        nodo->setLista(new ListaNiveles());
        //std::cout << " lista creada" << endl;
        std::cout << nodo->getLista() << endl;
    }
    else
    {
        std::cout << " no encontrado " << endl;
    }
}

void ArbolAVL::insertarNivel(NodoAVL *nodo, int id, int numeroNivel)
{
    if (busqueda(nodo, id))
    {
        nodo->getLista()->agregarNuevoNivel(new NodoNivel(numeroNivel));
    }
    else
    {
        std::cout << " no encontrado " << endl;
    }
}

void ArbolAVL::obtenerListaNodo(NodoAVL *nodo, int id)
{
    if(busqueda(nodo, id))
    {
        nodo->getLista()->imprimirLista();
    }
    else
    {
        std::cout << " no encontrado " << endl;
    }
    
}
