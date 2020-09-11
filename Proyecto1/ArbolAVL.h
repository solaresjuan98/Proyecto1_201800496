#include <iostream>
#include <stdbool.h>
#include <string.h>
#include "NodoAVL.h"
#include "ListaProyectos.h"
#include "NodoProyecto.h"
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

    //Lista Ordenada ascendentemente
    ListaProyectos *lista = new ListaProyectos();

    //Recorridos
    void inOrden(NodoAVL *n);
    void postOrden(NodoAVL *n);
    void preOrden(NodoAVL *n);
    bool busqueda(NodoAVL *n, int id);
    NodoAVL *busquedaNodo(NodoAVL *nodo, int id);
    void imprimir(NodoAVL *raiz, int cont);

    // Listas en nodo AVL
    void crearListaNiveles(int id);
    void insertarNivel(int id, int numeroNivel);
    void obtenerListaNodo(NodoAVL *raiz, int id);
    void eliminarNivel(int id, int numeroNivel);
    void obtenerNumNiveles(int id);

    //Obtener los proyectos con mayor numero de niveles en forma ascendente
    // - Generando lista
    void generarListaPOrd(NodoAVL *actual);
    void imprimirAsc();

    // Arboles ABB en nodo AVL
    void crearABBObjetos(NodoAVL *raiz, int id, int nivel);
    void insertarnodoABB(int id, int nivel, int id_obj, string nombre);
    void imprimirABBobjetos(int id, int numeroNivel);
    void eliminarnodoABB(int id, int numeroNivel, int id_obj);

    // Matrices de la lista
    void insertarEnMatriz(int id, int nivel, int id_obj, string letra, string color, int x, int y);
    void imprimirMatriz(int id, int numeroNivel);

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
    cout << " --" << endl;
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
        //std::cout << " Lista : " << actual->getLista() << endl;
        /*if (actual->getLista() != NULL)
        {
            actual->getLista()->imprimirLista();
        }*/

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

/*
    LISTAS EN NODO AVL
*/

void ArbolAVL::generarListaPOrd(NodoAVL *actual)
{

    if (actual == NULL)
    {
        return;
    }
    else
    {
        generarListaPOrd(actual->getIzq());

        //agregando a lista
        lista->agregarProyecto(new NodoProyecto(actual->getID(), actual->getLista()->obtenerTamanio()));

        generarListaPOrd(actual->getDer());
        /* code */
    }
}

void ArbolAVL::imprimirAsc()
{
    lista->imprimirLista();
}

void ArbolAVL::crearListaNiveles(int n)
{
    NodoAVL *tmp = this->raiz;
    if (busqueda(tmp, n))
    {

        busquedaNodo(tmp, n)->setLista(new ListaNiveles());
        std::cout << tmp->getLista() << endl;
    }
    else
    {
        std::cout << " no encontrado " << endl;
    }
}

NodoAVL *ArbolAVL::busquedaNodo(NodoAVL *nodo, int id)
{

    if (nodo == NULL)
    {
        return NULL;
    }
    else if (nodo->getID() == id)
    {
        return nodo;
    }
    else if (id < nodo->getID())
    {
        return busquedaNodo(nodo->getIzq(), id);
    }
    else
    {
        return busquedaNodo(nodo->getDer(), id);
    }
}

void ArbolAVL::insertarNivel(int id, int numeroNivel)
{
    NodoAVL *tmp = this->raiz;
    if (busqueda(tmp, id))
    {
        tmp = this->raiz;
        cout << " --" << endl;
        busquedaNodo(tmp, id)->getLista()->agregarNuevoNivel(new NodoNivel(numeroNivel));
        //cout << " Insertando nivel" << numeroNivel << " en proyecto " << tmp->getID() << endl;
    }
    else
    {
        std::cout << " no encontrado " << endl;
    }
}

void ArbolAVL::eliminarNivel(int id, int numeroNivel)
{
    NodoAVL *tmp = this->raiz;

    if (busqueda(tmp, id))
    {
        busquedaNodo(tmp, id)->getLista()->eliminar_nivel(numeroNivel);
    }
}

void ArbolAVL::obtenerListaNodo(NodoAVL *nodo, int id)
{
    NodoAVL *tmp = this->raiz;
    if (busqueda(nodo, id))
    {
        tmp = this->raiz;
        cout << nodo->getLista() << endl;
        busquedaNodo(tmp, id)->getLista()->imprimirLista();
    }
    else
    {
        std::cout << " no encontrado " << endl;
    }
}

void ArbolAVL::obtenerNumNiveles(int id)
{
    NodoAVL *nodo = this->raiz;

    if (busquedaNodo(nodo, id))
    {
        cout << " Proyecto: " << busquedaNodo(nodo, id)->getID() << endl;
        cout << " No. Niveles -> " << busquedaNodo(nodo, id)->getLista()->obtenerTamanio() << endl;
    }
    else
    {
        cout << " No encontrado. " << endl;
    }
}

/*
    ARBOLES ABB DE OBJETOS
*/
void ArbolAVL::imprimirABBobjetos(int id, int numeroNivel)
{
    NodoAVL *tmp = this->raiz;

    // Si el nodoAVL existe
    if (busquedaNodo(tmp, id))
    {

        busquedaNodo(tmp, id)->getLista()->retornarABB(numeroNivel);

        //Buscar nodo
        //busquedaNodo(tmp, id)->getLista()
    }
}

void ArbolAVL::crearABBObjetos(NodoAVL *nodo, int id, int nivel)
{
    if (busqueda(nodo, id))
    {

        nodo->getLista()->crearArbol(nivel);

        /*
            1. Verificar si tiene lista
            2. Buscar NodoNivel
                2.1 Si existe el NodoNivel, setear el arbol binario al nodo
        */
    }
    else
    {
    }
}

void ArbolAVL::insertarnodoABB(int id, int nivel, int id_obj, string nombre)
{
    //1. buscar si el nodo avl existe
    //2. Verificar si ese nodo avl está apuntada a una lista
    //3. Si existe la lista, buscar el nivel al que partenece el objeto
    //4. Agregar objeto al ABB de objetos
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        if (busquedaNodo(tmp, id)->getLista() != NULL)
        {
            busquedaNodo(tmp, id)->getLista()->agregar_nodo_abb(nivel, id_obj, nombre);
            //cout << "Lista: " << nodo->getLista() << endl;
        }
    }
    else
    {
        cout << " no encontrado " << endl;
    }
}

void ArbolAVL::eliminarnodoABB(int id, int nivel, int id_obj)
{
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        if (busquedaNodo(tmp, id)->getLista() != NULL)
        {
            busquedaNodo(tmp, id)->getLista()->eliminar_nodo_abb(nivel, id_obj);
            //cout << "Lista: " << nodo->getLista() << endl;
        }
    }
    else
    {
        cout << " no encontrado " << endl;
    }
}

void ArbolAVL::insertarEnMatriz(int id, int id_nivel, int id_obj, string letra, string color, int x, int y)
{
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        if (busquedaNodo(tmp, id)->getLista() != NULL)
        {

            busquedaNodo(tmp, id)->getLista()->agregar_nodo_matriz(id_nivel, id_obj, letra, color, x, y);
        }
    }
}

void ArbolAVL::imprimirMatriz(int id, int numeroNivel)
{
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        busquedaNodo(tmp, id)->getLista()->retornarMatriz(numeroNivel);
    }
    else
    {
        cout << " ";
    }
}
