#include <iostream>
#include <stdbool.h>
#include <string.h>
#include "NodoAVL.h"
#include "ListaProyectos.h"
#include "NodoProyecto.h"
#include "Matrix.h"
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
    string contenido_grafico = "";
    // listas donde se va a ordenar los proyectos por cantidad de niveles
    //Lista Ordenada ascendentemente
    ListaProyectos *lista = new ListaProyectos();
    //Lista Ordenana descendentemente
    ListaProyectos *lista_desc = new ListaProyectos();
    //lista que tiene la cantidad de objetos de cada matriz
    ListaProyectos *lista_objetos = new ListaProyectos();

    // Rotaciones
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
    NodoAVL *busquedaNodo(NodoAVL *nodo, int id);
    void imprimir(NodoAVL *raiz, int cont);
    NodoAVL *getReemplazo(NodoAVL *raiz);

    //Impresión de AVL en Graphviz
    void Graficar();
    void GraficarRecursivo(NodoAVL *raiz);

    //Eliminación de nodoAVL
    bool eliminar(int idProyecto);

    // Listas en nodo AVL
    void crearListaNiveles(int id);
    void insertarNivel(int id, int numeroNivel);
    void obtenerListaNodo(NodoAVL *raiz, int id);
    void eliminarNivel(int id, int numeroNivel);
    void obtenerNumNiveles(int id);
    void crearPisos(int id, int cantidadPisos);
    void copiarNivel(int id, int nivelCopiar, int nivelDestino);

    // Agregando a lista ascendente y descendente para el reporte
    //void agregarenListaAsc(int id, int cant);

    // copia de lista

    //Obtener los proyectos con mayor numero de niveles en forma ascendente
    // - Generando lista
    void generarListaPOrd(NodoAVL *actual);

    // Obtener los proyecto con mayor numero de niveles en forma descendente
    // - Generando lista
    void generarListaPDesc(NodoAVL *actual);

    void imprimirAsc();
    void imprimirDesc();

    // Arboles ABB en nodo AVL
    void crearABBObjetos(NodoAVL *raiz, int id, int nivel);
    void insertarnodoABB(int id, int nivel, int id_obj, string nombre, string letra, string color, int x, int y);
    void imprimirABBobjetos(int id, int numeroNivel);
    void imprimirABBInOrder(int id, int numeroNivel);
    void eliminarnodoABB(int id, int numeroNivel, int id_obj);

    // Matrices de la lista
    void insertarEnMatriz(int id, int nivel, int id_obj, string letra, string color, int x, int y);
    void eliminarDeMatriz(int id, int nivel, int x, int y);
    void moverenMatriz(int id, int nivel, int x, int y, int x_, int y_);
    void imprimirMatriz(int id, int numeroNivel);
    void imprimirMatricesEnMasa(int id);
    void imprimirNivel(int id, int nivel);
    void rotarObjeto(int id, int nivel, int x, int y, int grados);

    // PARA REPORTES:
    void genListaNivelesPorObjeto(int id_proyecto);
    void imprimirListaNivelesPorObjeto(int id_proyecto);
    void genListaMasEspacio(int id_proyecto);
    void imprimirListaMasEspacio(int id_proyecto);
    void genListaParedes(int id_proyecto);
    void imprimirListaParedes(int id_proyecto);
    void genListaParedesA(int id_proyecto);
    void imprimirListaParedesA(int id_proyecto);
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

// graficando en Graphviz
void ArbolAVL::Graficar()
{
    ofstream graficoAVL;
    string cadena;
    graficoAVL.open("ProyectosAVL.txt", ios::out);

    if (graficoAVL.fail())
    {
        cout << "*No se pudo abrir el archivo*" << endl;
        system("pause");
        //exit(1);
    }

    graficoAVL << " digraph BST {\n";
    graficoAVL << "node [shape = record, style=filled, fillcolor=gray];\n";

    GraficarRecursivo(this->raiz);

    cadena += this->contenido_grafico;
    graficoAVL << cadena;
    //graficoAVL << aux;

    graficoAVL << "}";

    graficoAVL.close();

    string cmd;
    cmd = "dot -Tjpg ProyectosAVL.txt -o Proyectos.jpg";
    int tam_cmd = cmd.length();
    char a[tam_cmd + 1];

    strcpy(a, cmd.c_str());
    system(a);

    this->contenido_grafico = "";
}

void ArbolAVL::GraficarRecursivo(NodoAVL *raiz)
{
    if (raiz != NULL)
    {

        if (raiz->getIzq() == NULL && raiz->getDer() == NULL)
        {
            this->contenido_grafico += "nodo" + to_string(raiz->getID()) + "[label=\"" + to_string(raiz->getID()) + "\"];\n";
        }
        else
        {
            this->contenido_grafico += "nodo" + to_string(raiz->getID()) + "[label=\"<A0>|" + to_string(raiz->getID()) + "|<A1>\"];\n";
        }

        if (raiz->getIzq() != NULL)
        {
            GraficarRecursivo(raiz->getIzq());
            this->contenido_grafico += "nodo" + to_string(raiz->getID()) + ":A0->nodo" + to_string(raiz->getIzq()->getID()) + "\n";
        }

        if (raiz->getDer() != NULL)
        {
            GraficarRecursivo(raiz->getDer());
            this->contenido_grafico += "nodo" + to_string(raiz->getID()) + ":A1->nodo" + to_string(raiz->getDer()->getID()) + "\n";
        }
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

        cout << " >> Proyecto: " << actual->getID() << endl;
        //std::cout << " Lista : " << actual->getLista() << endl;
        if (actual->getLista() != NULL)
        {
            //actual->getLista()->imprimirLista();
            //cout << actual->getLista()->get
        }

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

//Eliminando nodo de AVL
bool ArbolAVL::eliminar(int idProyecto)
{

    NodoAVL *aux = this->raiz;
    NodoAVL *padre = this->raiz;

    bool h_izq = true;

    while (aux->getID() != idProyecto)
    {
        padre = aux;

        if (aux->getID() > idProyecto)
        {
            h_izq = true;
            aux = aux->getIzq();
        }
        else
        {
            h_izq = false;
            aux = aux->getDer();
        }

        if (aux == NULL)
        {
            return false;
        }
    }

    // Es un nodo hoja
    if (aux->getIzq() == NULL && aux->getDer() == NULL)
    {
        if (aux == this->raiz)
        {
            this->raiz = NULL;
        }
        else if (h_izq)
        {
            padre->getIzq() == NULL;
        }
        else
        {
            padre->getDer() == NULL;
        }
    }
    else if (aux->getDer() == NULL)
    {

        if (aux == this->raiz)
        {
            this->raiz = aux->getIzq();
        }
        else if (h_izq)
        {
            padre->setIzq(aux->getIzq());
        }
        else
        {
            padre->setDer(aux->getIzq());
        }
    }
    else if (aux->getIzq() == NULL)
    {
        if (aux == this->raiz)
        {
            this->raiz = aux->getDer();
        }
        else if (h_izq)
        {
            //padre->setIzq(aux->getDer());
            padre->setDer(aux->getDer());
        }
        else
        {
            padre->setDer(aux->getIzq());
            //padre->setDer(aux->getDer());
        }
    }
    else
    {
        // Buscar el reemplazo del nodo eliminado
        NodoAVL *reemplazo = getReemplazo(aux);

        if (aux == this->raiz)
        {
            this->raiz = reemplazo;
        }
        else if (h_izq)
        {
            padre->setIzq(reemplazo);
        }
        else
        {
            padre->setDer(reemplazo);
        }

        reemplazo->setIzq(aux->getIzq());
    }

    return true;
}

NodoAVL *ArbolAVL::getReemplazo(NodoAVL *nodoReemplazo)
{
    NodoAVL *reemplazo_padre = nodoReemplazo;
    NodoAVL *reemplazo = nodoReemplazo;
    NodoAVL *aux = nodoReemplazo->getIzq();

    while (aux != NULL)
    {
        reemplazo_padre = reemplazo;
        reemplazo = aux;
        aux = aux->getIzq();
    }

    if (reemplazo != nodoReemplazo->getDer())
    {
        reemplazo_padre->setIzq(reemplazo->getDer());
        reemplazo->setDer(nodoReemplazo->getDer());
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
        lista->agregarDato(new NodoProyecto(actual->getID(), actual->getLista()->obtenerTamanio()));

        generarListaPOrd(actual->getDer());
    }
}

void ArbolAVL::generarListaPDesc(NodoAVL *actual)
{

    if (actual == NULL)
    {
        return;
    }
    else
    {
        generarListaPDesc(actual->getIzq());
        //agregando a lista
        lista_desc->agregarDatoDesc(new NodoProyecto(actual->getID(), actual->getLista()->obtenerTamanio()));
        generarListaPDesc(actual->getDer());
    }
}

void ArbolAVL::imprimirAsc()
{
    lista->imprimirLista();
}

void ArbolAVL::imprimirDesc()
{
    lista_desc->imprimirLista();
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
        //cout << " --" << endl;
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
    if (busquedaNodo(nodo, id))
    {
        tmp = this->raiz;
        //cout << nodo->getLista() << endl;
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

//Crear nivel via json

//Crear pisos a partir del ultimo nivel
void ArbolAVL::crearPisos(int id, int numeroNiveles)
{
    NodoAVL *nodo = this->raiz;
    int nuevototal = 0;
    int tamanio = 0;

    if (busquedaNodo(nodo, id))
    {
        // Tamaño de la lista al inicio
        tamanio = busquedaNodo(nodo, id)->getLista()->obtenerTamanio();

        nuevototal = numeroNiveles + busquedaNodo(nodo, id)->getLista()->obtenerTamanio();
        // Agregar niveles a partir del ultimo nivel de la lista
        for (int i = tamanio; i < nuevototal; i++)
        {
            //cout << " >> Creando nivel " << i << endl;
            busquedaNodo(nodo, id)->getLista()->agregarNuevoNivel(new NodoNivel(i));
        }
    }
    else
    {
        /* code */
    }
}

//Copiar niveles (idProyecto, copia, nivelDestino)
void ArbolAVL::copiarNivel(int id, int nivelCopia, int nivelDestino)
{
    NodoAVL *nodo = this->raiz;
    //Matrix *mat_original;
    Matrix *mat_copia;
    NodoNivel *temp;

    NodoNivel *destino;

    if (busquedaNodo(nodo, id))
    {
        // Llamar los metodos ValidarSiNodoExiste que retornan nodo
        temp = busquedaNodo(nodo, id)->getLista()->validarSiNodoExiste(nivelCopia);
        destino = temp;
        destino = busquedaNodo(nodo, id)->getLista()->validarSiNodoExiste(nivelDestino);
        destino->setMatriz(busquedaNodo(nodo, id)->getLista()->validarSiNodoExiste(nivelCopia)->getMatriz());
    }
    else
    {
        /* code */
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

void ArbolAVL::insertarnodoABB(int id, int nivel, int id_obj, string nombre, string letra, string color, int x, int y)
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
            busquedaNodo(tmp, id)->getLista()->agregar_nodo_abb(nivel, id_obj, nombre, letra, color, x, y);
            //cout << "Lista: " << nodo->getLista() << endl;
        }
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

void ArbolAVL::imprimirABBInOrder(int id, int numeroNivel)
{
    NodoAVL *nodo = this->raiz;

    if (busquedaNodo(nodo, id))
    {
        //busquedaNodo(nodo, id)->getLista()->validarSiNodoExiste(numeroNivel)->verArbolObjetos()
    }
    else
    {
    }
}

/*
    MATRIZ 
*/

void ArbolAVL::insertarEnMatriz(int id, int id_nivel, int id_obj, string letra, string color, int x, int y)
{
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        if (busquedaNodo(tmp, id)->getLista() != NULL)
        {

            busquedaNodo(tmp, id)->getLista()->agregar_nodo_matriz(id_nivel, id_obj, letra, color, x, y);
            //busquedaNodo(tmp, id)->getLista()->agregar_nodo_abb(id_nivel, id_obj, "nombre", letra, color, x, y);
        }
    }
    else
    {
        cout << " >> No encontrado " << endl;
    }
}

void ArbolAVL::eliminarDeMatriz(int id, int id_nivel, int x, int y)
{
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        if (busquedaNodo(tmp, id)->getLista() != NULL)
        {

            busquedaNodo(tmp, id)->getLista()->eliminar_nodo_matriz(id_nivel, x, y);
            //busquedaNodo(tmp, id)->getLista()->agregar_nodo_abb(id_nivel, id_obj, "nombre", letra, color, x, y);
        }
    }
    else
    {
        cout << " >> No encontrado " << endl;
    }
}

void ArbolAVL::moverenMatriz(int id, int id_nivel, int x, int y, int x_, int y_)
{
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        if (busquedaNodo(tmp, id)->getLista() != NULL)
        {

            busquedaNodo(tmp, id)->getLista()->mover_nodo_matriz(id_nivel, x, y, x_, y_);
        }
    }
    else
    {
        cout << " >> No encontrado " << endl;
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

void ArbolAVL::imprimirMatricesEnMasa(int id)
{
    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id))
    {
        busquedaNodo(temp, id)->getLista()->GraficarL();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::imprimirNivel(int id, int nivel)
{
    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id))
    {
        busquedaNodo(temp, id)->getLista()->GraficarNivel(nivel);
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::rotarObjeto(int id, int nivel, int x, int y, int grados)
{
    NodoAVL *tmp = this->raiz;

    if (busquedaNodo(tmp, id))
    {
        if (busquedaNodo(tmp, id)->getLista() != NULL)
        {

            busquedaNodo(tmp, id)->getLista()->rotar_objeto_matriz(nivel, x, y, grados);
        }
    }
    else
    {
        cout << " >> No encontrado " << endl;
    }
}

// REPORTES

void ArbolAVL::genListaNivelesPorObjeto(int id_proyecto)
{

    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->insertarNumObjNiveles();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::imprimirListaNivelesPorObjeto(int id_proyecto)
{
    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->imprimirListaCantObj();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::genListaMasEspacio(int id_proyecto)
{

    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->insertarNumEspaciosVacios();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::imprimirListaMasEspacio(int id_proyecto)
{
    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->imprimirListaCantEspacios();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::genListaParedes(int id_proyecto)
{

    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->insertarNumParedes();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::imprimirListaParedes(int id_proyecto)
{
    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->imprimirListaParedes();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::genListaParedesA(int id_proyecto)
{

    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->insertarNumParedes();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}

void ArbolAVL::imprimirListaParedesA(int id_proyecto)
{
    NodoAVL *temp = this->raiz;

    if (busquedaNodo(temp, id_proyecto))
    {
        busquedaNodo(temp, id_proyecto)->getLista()->imprimirListaParedesA();
    }
    else
    {
        cout << " >> Proyecto no encontrado. " << endl;
    }
}
