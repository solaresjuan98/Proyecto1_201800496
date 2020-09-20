
#include <iostream>
#include <fstream>
#include <sstream>
#include "NodoArbol.h"
#define SPACE 10
#pragma once
using namespace std;

class ArbolBinario
{
public:
    NodoArbol *raiz;
    string contenido_grafico = "";
    ArbolBinario();

    bool estaVacio()
    {
        if (raiz == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertarNodo(NodoArbol *nuevo_nodo)
    {
        if (raiz == NULL)
        {
            raiz = nuevo_nodo;
            //cout << " insertado al inicio :)" << endl;
        }
        else
        {
            NodoArbol *temp = raiz;

            while (temp != NULL)
            {
                if (nuevo_nodo->id == temp->id) //Aqui truena
                {
                    //cout << " Nodo repetido, intenta de nuevo :'v" << endl;
                    //return; // no se aceptan nodos repetidos
                    return;
                }
                else if (nuevo_nodo->id < temp->id && temp->izq == NULL)
                {
                    // insertar nodo en hijo izquierdo
                    temp->izq = nuevo_nodo;
                    //cout << " Nodo insertado a la izq :)" << endl;
                    break;
                }
                else if (nuevo_nodo->id < temp->id)
                {
                    temp = temp->izq;
                }
                else if (nuevo_nodo->id > temp->id && temp->der == NULL)
                {
                    // insertar nodo en hijo derecho
                    temp->der = nuevo_nodo;
                    //cout << " id insertado a la der :)" << endl;
                    break;
                }
                else
                {
                    // pasar a nodo siguiente
                    temp = temp->der;
                }
            }
        }
    }

    void imprimirArbol(NodoArbol *raiz, int cont)
    {
        if (raiz == NULL)
        {
            //cout << " Arbol vacío :'v"<<endl;
            return;
        }
        else
        {
            imprimirArbol(raiz->der, cont + 1);
            for (int i = 0; i < cont; i++)
            {
                cout << "   ";
            }

            cout << "[" << raiz->id << " " << raiz->nombre << "]" << endl;
            imprimirArbol(raiz->izq, cont + 1);
        }
    }

    void preOrden(NodoArbol *arbol)
    {
        if (arbol == NULL)
        {
            return;
        }
        else
        {
            cout << "  >> " << arbol->id << "  " << arbol->nombre << endl;
            preOrden(arbol->izq);
            preOrden(arbol->der);
        }
    }

    void inOrden(NodoArbol *arbol)
    {

        if (arbol == NULL)
        {
            return;
        }
        else
        {
            inOrden(arbol->izq);
            cout << "  >> " << arbol->id << "  " << arbol->nombre << endl;
            inOrden(arbol->der);
        }
    }

    void postOrden(NodoArbol *arbol)
    {
        if (arbol == NULL)
        {
            return;
        }
        else
        {
            postOrden(arbol->izq);
            postOrden(arbol->der);
            cout << "  >> " << arbol->id << " " << arbol->nombre << endl;
        }
    }

    void destruirNodo(NodoArbol *nodo)
    {
        nodo->izq = NULL;
        nodo->der = NULL;

        delete nodo;
    }

    bool eliminar(int id)
    {
        NodoArbol *aux = raiz;
        NodoArbol *padre = raiz;

        bool Hijoizq = true;

        while (aux->id != id)
        {
            padre = aux;

            if (id < aux->id)
            {
                Hijoizq = true;
                aux = aux->izq;
            }
            else
            {
                Hijoizq = false;
                aux = aux->der;
            }

            if (aux == NULL)
            {
                return false;
            }
        }

        if (aux->izq == NULL && aux->der == NULL)
        {
            //Es un nodo hoja
            if (aux == raiz)
            {
                //unico nodo
                raiz = NULL;
            }
            else if (Hijoizq)
            {
                padre->izq = NULL;
            }
            else
            {
                padre->der = NULL;
            }
        }
        else if (aux->der == NULL)
        {
            //Es un nodo hoja
            if (aux == raiz)
            {
                //unico nodo
                raiz = aux->izq;
            }
            else if (Hijoizq)
            {
                padre->izq = aux->izq;
            }
            else
            {

                padre->der = aux->izq;
            }
        }
        else if (aux->izq == NULL)
        {
            if (aux == raiz)
            {
                //unico nodo
                raiz = aux->der;
            }
            else if (Hijoizq)
            {
                padre->izq = aux->der;
            }
            else
            {
                padre->der = aux->der;
            }
        }
        else
        {
            //Buscando el nodo reemplazo
            NodoArbol *reemp = getRemplazo(aux);

            if (aux == raiz)
            {
                raiz = reemp;
            }
            else if (Hijoizq)
            {
                padre->izq = reemp;
            }
            else
            {
                padre->der = reemp;
            }

            reemp->izq = aux->izq;
        }

        return true;
    }

    //get nodo reemplazo
    NodoArbol *getRemplazo(NodoArbol *nodoR)
    {
        NodoArbol *reem_padre = nodoR;
        NodoArbol *reem = nodoR;
        NodoArbol *aux = nodoR->der;

        while (aux != NULL)
        {
            reem_padre = reem;
            reem = aux;
            aux = aux->izq;
        }

        if (reem != nodoR->der)
        {
            reem_padre->izq = reem->der;
            reem->der = nodoR->der;
        }

        cout << " Nodo reemp: " << reem << endl;
    }

    // Determinar el nodo más izquierdo
    NodoArbol *minimo(NodoArbol *raiz)
    {
        if (raiz == NULL)
        {
            return NULL;
        }

        if (raiz->izq)
        {
            //cout << raiz->izq->id << endl;
            //cout << raiz->der->id << endl;
            return minimo(raiz->izq);
        }
        else
        {

            return raiz;
        }
    }

    // Reemplazar Nodo (No lo estoy usando)
    void reemplazarNodo(NodoArbol *nodoEliminar, NodoArbol *nuevo)
    {
        if (nodoEliminar == raiz)
        {
            if (nodoEliminar->id == nodoEliminar->izq->id)
            {
                nodoEliminar->izq = nuevo;
            }
            else if (nodoEliminar->id == nodoEliminar->der->id)
            {
                nodoEliminar->der = nuevo;
            }
        }
        if (nuevo)
        {
            raiz = nodoEliminar;
        }
    }

    /*
    void EliminarNodo(NodoArbol *nodoEliminar)
    {

        if (nodoEliminar->izq && nodoEliminar->der)
        {
            NodoArbol *menor = minimo(nodoEliminar->der);
            nodoEliminar->id = menor->id;
            EliminarNodo(menor);
        }
        else if (nodoEliminar->izq)
        {
            reemplazarNodo(nodoEliminar, nodoEliminar->izq);
            destruirNodo(nodoEliminar);
        }
        else if (nodoEliminar->der)
        {
            reemplazarNodo(nodoEliminar, nodoEliminar->der);
            destruirNodo(nodoEliminar);
        }
        else
        {
            reemplazarNodo(nodoEliminar, NULL);
            destruirNodo(nodoEliminar);
        }
    }
    */

    // Generar en graphviz
    void GraficarABB()
    {
        ofstream graficoBST;
        string cadena;
        graficoBST.open("ArbolBinario.txt", ios::out);

        if (graficoBST.fail())
        {
            cout << "*No se pudo abrir el archivo*" << endl;
            system("pause");
            //exit(1);
        }

        graficoBST << " digraph BST {\n";
        graficoBST << "node [shape = record, style=filled, fillcolor=gray];\n";

        graficarRecursivo(this->raiz);

        cadena += this->contenido_grafico;
        graficoBST << cadena;
        graficoBST << "}";
        graficoBST.close();

        string cmd;
        cmd = "dot -Tpng ArbolBinario.txt -o Arbolbinario.jpg";
        int tam_cmd = cmd.length();
        char a[tam_cmd + 1];
        strcpy(a, cmd.c_str());
        system(a);
        this->contenido_grafico = "";
    }

    void graficarRecursivo(NodoArbol *r)
    {
        //stringstream cad;
        if (r != NULL)
        {

            if (r->izq == NULL && r->der == NULL)
            {
                this->contenido_grafico += "nodo" + to_string(r->id) + "[label=\"" + r->nombre + "\"];\n";
            }
            else
            {
                this->contenido_grafico += "nodo" + to_string(r->id) + "[label=\"<A0>|" + r->nombre + "|<A1>\"];\n";
            }

            if (r->izq != NULL)
            {
                graficarRecursivo(r->izq);
                this->contenido_grafico += "nodo" + to_string(r->id) + ":A0->nodo" + to_string(r->izq->id) + "\n";
            }

            if (r->der != NULL)
            {
                graficarRecursivo(r->der);
                this->contenido_grafico += "nodo" + to_string(r->id) + ":A1->nodo" + to_string(r->der->id) + "\n";
            }
        }
    }

    ~ArbolBinario();
};

ArbolBinario::ArbolBinario()
{
}

ArbolBinario::~ArbolBinario()
{
}
