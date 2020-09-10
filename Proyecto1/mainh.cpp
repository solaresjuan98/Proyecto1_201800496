#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "json.hpp"
#include <time.h>

//clases / estructuras
#include "Matrix.h"
#include "ArbolAVL.h"
#include "ArbolBinario.h"
#include "NodoArbol.h"
#include "ListaNiveles.h"
#include "NodoNivel.h"
#include "ListaProyectos.h"
#include "NodoProyecto.h"

using namespace std;
using json = nlohmann::json;

// funciones principales
void mostrarDatos();
void mostrarMenu();

//variables de lectura de archivo JSON
json totalJSON;
json nombreProyectoJson;
json nivelesJson;
json paredesJson;
json ventanasJson;
json objetosJson;
json puntosObjetosJson;

//variables de lectura de libreria JSON
json libJSON;
json idJson;
json nombreJson;
json letraJson;
json colorJson;
json puntos_lib;
json x_json;
json y_json;

/*
 * ESTRUCTURAS
 * 
*/
// Arbol donde se van a almacenar todos los proyectos
ArbolAVL *avl = new ArbolAVL();
ArbolAVL *pr = new ArbolAVL();
// Arbol del listado de objetos
ArbolBinario *abbGlobal = new ArbolBinario();
ListaNiveles *ln1 = new ListaNiveles();
//
ListaProyectos *lp = new ListaProyectos();

// ruta de archivo a leer
string ruta;
string cadena;
// Variables de atributos de nivel
int numeroNivel;
int id = 0;
//funciones para mostrar los datos del archivoJSON
void cargarArchivo(string ruta);
void cargarLibrerias(string ruta);
// obtener el equivalente en ascii
int convertirASCII(string cadena);

void getListaNivelesNodo(int id);

string n1, n2, n3, n4, n5;
string r1, r2, r3, r4;
int main()
{
    /*Matrix *md = new Matrix();

    md->add(10, "m", "white", 2, 1);
    md->add(12, "t", "black", 3, 1);
    md->add(14, "l", "red", 3, 2);
    md->add(12, "s", "brown", 5, 4);
    md->add(13, "e", "black", 4, 3);

    md->print_headers();
    md->print_nodes_x();
    md->print_nodes_y();

    cout << " -------------------------" << endl;*/

    avl->insertar(1002);
    for (int i = 1; i < 6; i++)
    {
        avl->insertarNivel(1002, i);
    }

    // Eliminando niveles del proyecto con ID 1002
    avl->eliminarNivel(1002, 2);
    avl->eliminarNivel(1002, 3);

    avl->insertar(100);
    // insertarNivel(id en avl, # nivel)
    avl->insertarNivel(100, 33);
    avl->insertarNivel(100, 44);
    avl->insertarNivel(100, 55);
    avl->insertarNivel(100, 66);

    // Insertar en abb de objetos
    avl->insertarnodoABB(100, 33, 1, "Mesa");
    avl->insertarnodoABB(100, 33, 2, "Escritorio");

    // Insertar en Matriz (proyecto, nivel, id, letra, color, x, y)
    avl->insertarEnMatriz(100, 33, 1, "m", "azul", 1, 2);
    avl->insertarEnMatriz(100, 33, 2, "e", "red", 2, 3);
    avl->insertarEnMatriz(100, 33, 3, "l", "yellow", 4, 4);
    avl->insertarEnMatriz(100, 33, 4, "b", "brown", 2, 4);
    /*avl->insertarEnMatriz(100, 33, 5, "p", "red", 2, 1);
    avl->insertarEnMatriz(100, 33, 6, "r", "red", 4, 1);
    avl->insertarEnMatriz(100, 33, 7, "k", "red", 11, 7);
    avl->insertarEnMatriz(100, 33, 8, "o", "red", 10, 4);
    avl->insertarEnMatriz(100, 33, 9, "c", "red", 15, 2);
    avl->insertarEnMatriz(100, 33, 10, "t", "blue", 13, 11);
    avl->insertarEnMatriz(100, 33, 11, "j", "white", 19, 12);*/
    /*for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            avl->insertarEnMatriz(100, 33, i, "p", "red", i, j);
        }
        
    }*/

    cout << " -- " << endl;
    avl->insertarnodoABB(100, 44, 3, "Silla");
    avl->insertarnodoABB(100, 44, 4, "Puerta");
    avl->insertarnodoABB(100, 44, 5, "Mesa");
    //AGREGAR A MATRIZ

    avl->insertar(101);
    //avl->crearListaNiveles(101);
    for (int i = 1; i < 17; i++)
    {
        avl->insertarNivel(101, i);
    }

    // Insertar en abb de objetos
    avl->insertarnodoABB(101, 2, 1, "Mesa");
    avl->insertarnodoABB(101, 2, 2, "Escritorio");

    // Insertar en Matriz (proyecto, nivel, id, letra, color, x, y)
    avl->insertarEnMatriz(101, 2, 1, "m", "azul", 5, 1);
    avl->insertarEnMatriz(101, 2, 2, "e", "red", 2, 1);

    avl->insertar(102);
    //avl->crearListaNiveles(102);
    for (int i = 1; i < 5; i++)
    {
        avl->insertarNivel(102, i);
    }

    avl->insertar(103);
    //avl->crearListaNiveles(103);
    for (int i = 1; i < 9; i++)
    {
        avl->insertarNivel(103, i);
    }

    cout << " --------------------------- \n";

    //avl->imprimir(avl->getRaiz(), 0);
    avl->inOrden(avl->getRaiz());

    cout << "\n\n";

    avl->imprimirABBobjetos(100, 33);
    avl->imprimirMatriz(100, 33);
    cout << "\n";
    avl->imprimirABBobjetos(100, 44);

    cout << "\t :: AVL CON PROYECTOS ACTUALES :: \n";

    //avl->imprimir(avl->getRaiz(), 0);
    avl->inOrden(avl->getRaiz());
    //mostrarDatos();
    //mostrarMenu();

    //cout << "\n\n";

    //cout << " \t ..:: Reportes 3 y 4 ::..\n";
    /*avl->obtenerNumNiveles(100);
    avl->obtenerNumNiveles(101);
    avl->obtenerNumNiveles(102);
    avl->obtenerNumNiveles(103);
    avl->obp
tenerNumNiveles(1002);*/

    //avl->generarListaPOrd(avl->getRaiz());
    //avl->imprimirAsc();

    //CANT. NIVELES DE FORMA ASCENDENTE
    /*lp->agregarProyecto(new NodoProyecto(1, 7));
        lp->agregarProyecto(new NodoProyecto(2, 10));
    lp->agregarProyecto(new NodoProyecto(3, 2));
    lp->agregarProyecto(new NodoProyecto(4, 1));
    lp->agregarProyecto(new NodoProyecto(5, 14));
    lp->agregarProyecto(new NodoProyecto(6, 25));
    lp->agregarProyecto(new NodoProyecto(7, 20));
    lp->agregarProyecto(new NodoProyecto(8, 5));
    lp->agregarProyecto(new NodoProyecto(9, 11));
    
    
    lp->imprimirLista();*/
    cin.get();
    return 0;
}

void mostrarDatos()
{
    std::cout << " ************************************************** " << endl;
    std::cout << " * USAC                                           * " << endl;
    std::cout << " * Estructuras de Datos                           * " << endl;
    std::cout << " * Seccion A                                      * " << endl;
    std::cout << " * Juan Antonio Solares Samayoa                   * " << endl;
    std::cout << " * 201800496                                      * " << endl;
    std::cout << " ************************************************** " << endl;
}

void mostrarMenu()
{
    int opcion = 0;

    std::cout << "\t ::: BIENVENIDO A PSEUDO-CAD ::: \n";
    std::cout << " Elige una opcion: " << endl;
    std::cout << " 1. Ver proyectos " << endl;
    std::cout << " 2. Editar proyectos " << endl;
    std::cout << " 3. Cargar proyecto" << endl;
    std::cout << " 4. Graficar proyectos" << endl;
    std::cout << " 5. Guardar proyectos" << endl;
    std::cout << " 6. Cargar librerias" << endl;
    std::cout << " 7. Limpiar consola " << endl;
    std::cout << " 8. Salir de la aplicacion " << endl;
    std::cout << " 9. Lista de prueba " << endl;
    std::cout << " 10. Buscar Proyecto " << endl;
    std::cout << " Elige una opcion: ";

    cin >> opcion;

    do
    {
        switch (opcion)
        {
        case 1:
            std::cout << "\n Proyectos existentes:" << endl;
            //imprimir arbol avl de proyectos existentes
            avl->imprimir(avl->getRaiz(), 0);
            // los imprime en la notación inOrden
            //avl->inOrden(avl->getRaiz());
            std::cout << "\n\n";
            cin.get();
            mostrarMenu();
            break;
        case 2:
            //system("clear");
            std::cout << "\n\t:: Editar proyectos \n"
                      << endl;
            std::cout << " 1. Agregar Nivel" << endl;
            std::cout << " 2. Editar Nivel" << endl;
            std::cout << " 3. Eliminar Nivel" << endl;
            std::cout << " 4. Eliminar Proyecto" << endl;
            std::cout << " 5. salir " << endl;
            std::cout << " Elige una opción " << endl;
            int opcion_editar;
            cin >> opcion_editar;
            switch (opcion_editar)
            {
            case 1:
                break;
            case 2:

                int sel_proyecto;
                std::cout << "\n Proyectos existentes:" << endl;
                //imprimir arbol avl de proyectos existentes

                // los imprime en la notación inOrden
                avl->inOrden(avl->getRaiz());
                std::cout << endl;
                cin.get();

                std::cout << "Elige un proyecto (por id): ";
                cin >> sel_proyecto;

                //std::cout << "** Lista de niveles **"<<endl;
                getListaNivelesNodo(sel_proyecto);
                //avl->obtenerListaNodo(avl->getRaiz(), sel_proyecto);
                //llamar funcion
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                system("clear");
                mostrarMenu();
                break;
            default:
                break;
            }

            break;
        case 3:
            std::cout << "\n Cargar archivo: " << endl;
            std::cout << " Escribe la ruta del archivo: ";
            cin.get();
            getline(cin, ruta);
            cargarArchivo(ruta);

            cin.get();
            /*r1 = "Archivos/ejemplo1.json";
            r2 = "Archivos/ejemplo2.json";
            r3 = "Archivos/ejemplo3.json";
            r4 = "Archivos/ejemplo4.json";

            cargarArchivo(r1);
            cargarArchivo(r2);
            cargarArchivo(r3);
            cargarArchivo(r4);*/
            //system("clear");
            mostrarMenu();
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            std::cout << "\n Cargar librerias\n";
            std::cout << "\n Cargar libreria: " << endl;
            std::cout << " Escribe la ruta del libreria: ";
            cin.get();
            getline(cin, ruta);
            cargarLibrerias(ruta);
            cin.get();
            mostrarMenu();
            break;
        case 7:
            system("clear");
            mostrarMenu();
            break;
        case 8:
            exit(1);
            break;
        case 9:

            //avl->imprimir(avl->getRaiz(), 0);

            /*Matrix *md = new Matrix();

            md->add(10, "m", "white", 2, 1);
            md->add(12, "t", "black", 3, 1);
            md->add(14, "l", "red", 3, 2);
            md->add(12, "s", "brown", 5, 4);
            md->add(13, "e", "black", 4, 3);

            md->print_headers();
            md->print_nodes_x();
            md->print_nodes_y();

            cout << " -------------------------" << endl;
            n1 = "Proyecto1";
            n2 = "Proyecto2";
            n3 = "Proyecto3";
            n3 = "Proyecto4";
            n3 = "Proyecto5";*/
            //convertirASCII(n1);
            //convertirASCII(n2);
            /*
            avl->insertar(convertirASCII(n1));
            avl->crearListaNiveles(avl->getRaiz(), convertirASCII(n1));

            for (int i = 0; i < 5; i++)
            {
                avl->insertarNivel(avl->getRaiz(), convertirASCII(n1), i);
                avl->crearABBObjetos(avl->getRaiz(), convertirASCII(n1), i);

                for (int j = 0; j < 4; j++)
                {
                    avl->insertarnodoABB(avl->getRaiz(), convertirASCII(n1), i, j, "prueba");
                    for (int k = 0; k < 3; k++)
                    {
                    }
                }
            }

            avl->insertar(convertirASCII(n2));
            avl->crearListaNiveles(avl->getRaiz(), convertirASCII(n2));

            for (int i = 0; i < 7; i++)
            {
                avl->insertarNivel(avl->getRaiz(), convertirASCII(n2), i);
                avl->crearABBObjetos(avl->getRaiz(), convertirASCII(n2), i);

                for (int j = 0; j < 4; j++)
                {
                    avl->insertarnodoABB(avl->getRaiz(), convertirASCII(n2), i, j, "prueba");
                    for (int k = 0; k < 3; k++)
                    {
                    }
                }
            }

            avl->insertar(convertirASCII(n3));
            avl->crearListaNiveles(avl->getRaiz(), convertirASCII(n3));

            for (int i = 0; i < 2; i++)
            {
                avl->insertarNivel(avl->getRaiz(), convertirASCII(n3), i);
                avl->crearABBObjetos(avl->getRaiz(), convertirASCII(n3), i);

                for (int j = 0; j < 4; j++)
                {
                    avl->insertarnodoABB(avl->getRaiz(), convertirASCII(n3), i, j, "prueba");
                    for (int k = 0; k < 3; k++)
                    {
                    }
                }
            }

            avl->imprimir(avl->getRaiz(), 0);
            avl->inOrden(avl->getRaiz());
            */
            break;
        }

        cin.get();

    } while (opcion != 10);
}

void cargarArchivo(string ruta)
{
    //Variables de los objetos que irán en el abb de objetos
    int id_objeto = 0;
    string nombre;

    std::ifstream archivo(ruta);
    int n_nivel;
    if (archivo.fail())
    {
        std::cout << " El archivo no existe.";
    }
    else
    {
        std::cout << " Archivo cargado" << endl;
        archivo >> totalJSON;
        nombreProyectoJson = totalJSON["nombre"];
        string nombreP;

        //std::cout << totalJSON["nombre"].get<std::string>() << endl;
        id = convertirASCII(nombreProyectoJson);
        std::cout << " Valor ascii: " << id << endl;

        fflush(stdin);
        avl->insertar(id);

        //avl->crearListaNiveles(avl->getRaiz(), convertirASCII(nombreProyectoJson));
        //avl->crearABB(avl->getRaiz(), id)
        nivelesJson = totalJSON["niveles"];
        std::cout << "\n";
        for (const auto pos : nivelesJson)
        {

            n_nivel = pos["nivel"];
            fflush(stdin);
            avl->insertarNivel(id, n_nivel);
            //avl->crearABBObjetos(avl->getRaiz(), convertirASCII(nombreProyectoJson), n_nivel);
            /*
                Paredes
                Ventanas
                objetos
            */
            paredesJson = pos["paredes"];
            std::cout << " Parades: " << endl;

            for (const auto pos : paredesJson)
            {
                //std::cout << " - " << pos["inicio"] << " -- " << pos["final"] << endl;
            }

            ventanasJson = pos["ventanas"];

            for (const auto pos : ventanasJson)
            {
                //std::cout << " ";
            }

            objetosJson = pos["objetos"];

            for (const auto pos : objetosJson)
            {
                /*std::cout << " - Identificador: " << pos["identificador"] << endl;
                std::cout << " - Nombre: " << pos["nombre"].get<std::string>() << endl;
                std::cout << " - Letra: " << pos["letra"].get<std::string>() << endl;
                std::cout << " - Color: " << pos["color"].get<std::string>() << endl;*/

                id_objeto = pos["identificador"];
                nombre = pos["nombre"];
                letraJson = pos["letra"];
                colorJson = pos["color"];

                //AGREGAR OBJETOS AL ABB DE OBJETOS
                //avl->insertarnodoABB(id, n_nivel, id_objeto, nombre, letraJson, colorJson);

                //avl->insertarnodoABB(avl->getRaiz(), id, n_nivel, id_objeto, nombre);
                puntosObjetosJson = pos["puntos"];

                for (const auto pos : puntosObjetosJson)
                {
                    //std::cout << " - Inicio: " << pos["x"] << " Final: " << pos["y"] << endl;

                    //AGREGAR OBJETOS A LA MATRIZ
                }
            }

            std::cout << "\n";
        }

        //mostrarNiveles(nivelesJson);
    }
}

void cargarLibrerias(string ruta)
{
    int id, x, y;
    string nombre, letra, color;

    ifstream libreria(ruta);

    if (libreria.fail())
    {
        std::cout << " La libreria no existe";
    }
    else
    {
        libreria >> libJSON;
        idJson = libJSON["Libreria"];

        for (const auto pos : idJson)
        {
            id = pos["identificador"];
            nombre = pos["nombre"].get<std::string>();
            letra = pos["letra"].get<std::string>();
            color = pos["color"].get<std::string>();

            puntos_lib = pos["puntos"];

            for (const auto pos : puntos_lib)
            {
                //std::cout << "     x: " << pos["x"] << endl;
                //std::cout << "     y: " << pos["y"] << endl;

                x = pos["x"];
                y = pos["y"];
                std::cout << "\n";

                //abbGlobal->insertarNodo(new NodoArbol(id, nombre, letra, color, x, y));
            }
            std::cout << " \n";
        }
    }

    abbGlobal->imprimirArbol(abbGlobal->raiz, 0);
}

int convertirASCII(string s)
{
    int value = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        value += int(c);
    }

    return value;
}

void getListaNivelesNodo(int id)
{
    avl->obtenerListaNodo(avl->getRaiz(), id);
}
