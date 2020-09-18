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
void mostrarMenuReportes();
void mostrarMenuNiveles();

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

// Arbol del listado de objetos
ArbolBinario *abbGlobal = new ArbolBinario();

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
// Rutas de archivos xd
string r1, r2, r3, r4;

int eleccion_p = 0;

int main()
{


    mostrarDatos();
    mostrarMenu();

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
    std::cout << " 8. Seccion de reportes" << endl;
    std::cout << " 10. Salir de la aplicacion " << endl;
    std::cout << " Elige una opcion: ";

    cin >> opcion;

    do
    {
        switch (opcion)
        {
        case 1:

            cout << "\n Proyectos existentes:" << endl;
            avl->inOrden(avl->getRaiz());
            cout << "\n\n";
            cin.get();
            cout << " >> Selecciona un proyecto para graficar sus niveles: ";
            cin >> eleccion_p;

            avl->imprimirMatricesEnMasa(eleccion_p);
            mostrarMenu();
            break;
        case 2:
            system("clear");
            mostrarMenuNiveles();
            break;
        case 3:
            std::cout << "\n Cargar archivo: " << endl;
            //std::cout << " Escribe la ruta del archivo: ";
            //cin.get();
            //getline(cin, ruta);
            //cargarArchivo(ruta);

            //cin.get();
            r1 = "Archivos/ejemplo1.json";
            r2 = "Archivos/ejemplo2.json";
            r3 = "Archivos/ejemplo3.json";
            r4 = "Archivos/ejemplo4.json";

            cargarArchivo(r1);
            cargarArchivo(r2);
            cargarArchivo(r3);
            cargarArchivo(r4);
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
            system("clear");
            mostrarMenuReportes();
            //exit(1);
            break;
        case 9:
            cin.get();
            //avl->imprimirMatriz(97, 1);
            //avl->imprimirMatriz(98, 1);
            //avl->imprimirMatriz(99, 1);
            avl->imprimirMatriz(104, 1);
            break;
        case 10:
            exit(1);
            break;
        }

        cin.get();

    } while (opcion != 11);
}

void mostrarMenuReportes()
{
    int opcion = 0;

    cout << "\t ::: REPORTES ::: \n";
    cout << " Elige una opcion: " << endl;
    cout << " 1. Ver AVL de forma grafica " << endl;
    cout << " 2. Mostrar ABB de objetos de librerias" << endl;
    cout << " 3. Proyectos con mayor numero de niveles (Ascendente)" << endl;
    cout << " 4. Proyectos con mayor numero de niveles (Descendente)" << endl;
    cout << " 5. Proyectos ordenados por numero de objetos" << endl;
    cout << " 6. Nivel con mas espacio" << endl;
    cout << " 7. Nivel con menos paredes" << endl;
    cout << " 8. Nivel con mas paredes" << endl;
    cout << " 9. Nivel con mas espacio / ventanas " << endl;
    cout << " 10. Nivel con mas espacio / menos ventanas " << endl;
    cout << " 11. Regresar al menu principal " << endl;
    cout << " Elige una opcion: ";

    cin >> opcion;

    do
    {
        switch (opcion)
        {
        case 1:
            cin.get();
            avl->insertar(101);
            avl->Graficar();
            avl->imprimir(avl->getRaiz(), 0);
            mostrarMenuReportes();
            break;
        case 2:

            abbGlobal->GraficarABB();
            mostrarMenuReportes();

            break;
        case 3:
            cin.get();
            cout << " :: Proyectos con mayor candidad de niveles (Ascendente) " << endl
                 << endl;
            avl->generarListaPOrd(avl->getRaiz());
            avl->imprimirAsc();
            cin.get();
            system("clear");
            mostrarMenuReportes();
            break;

        case 4:
            cin.get();
            cout << " :: Proyectos con mayor candidad de niveles (Descendente) " << endl
                 << endl;
            //avl->generarListaPOrd(avl->getRaiz());
            //avl->imprimirDesc();
            cin.get();
            system("clear");
            mostrarMenuReportes();
            break;
        case 11:
            system("clear");
            mostrarMenu();
            break;
        default:
            cout << " opcion incorrecta. \n";
            break;
        }
    } while (opcion != 0);
}

void mostrarMenuNiveles()
{
    cout << "\n\t:: MENU DE EDICION DE PROYECTOS \n"
         << endl;
    cout << " 1. Agregar Niveles" << endl;
    cout << " 2. Editar Nivel" << endl;
    cout << " 3. Eliminar Nivel" << endl;
    cout << " 4. Eliminar Proyecto" << endl;
    cout << " 5. Regresar " << endl;
    cout << " >> Elige una opción: ";
    int opcion_editar;
    int proyecto;
    int num_niveles_nuevos;
    int nivel_eliminar;

    cin >> opcion_editar;
    switch (opcion_editar)
    {
    case 1:

        cout << " >> :: Agregar niveles :: " << endl;

        avl->inOrden(avl->getRaiz());

        cout << " >> Selecciona un proyecto: ";

        cin >> proyecto;

        cout << " >> Proyecto " << proyecto << " seleccionado. " << endl;
        cout << " >> ¿Cuantos niveles nuevos deseas agregar? ";
        cin >> num_niveles_nuevos;

        avl->crearPisos(proyecto, num_niveles_nuevos);
        mostrarMenuNiveles();

        break;
    case 2:
        cout << "\n Proyectos existentes:" << endl;
        //imprimir arbol avl de proyectos existentes

        // los imprime en la notación inOrden
        avl->inOrden(avl->getRaiz());
        cout << endl;
        cin.get();

        cout << "Elige un proyecto (por id): ";
        cin >> proyecto;
        //std::cout << "** Lista de niveles **"<<endl;
        getListaNivelesNodo(proyecto);

        break;
    case 3:
        cout << " >> ELIMINAR NIVEL " << endl;
        cout << "\n Proyectos existentes:" << endl;
        //imprimir arbol avl de proyectos existentes

        // los imprime en la notación inOrden
        avl->inOrden(avl->getRaiz());
        cout << endl;
        cin.get();

        cout << "Elige un proyecto (por id): ";
        cin >> proyecto;

        getListaNivelesNodo(proyecto);

        cout << " >> Elige el nivel a eliminar: ";
        cin >> nivel_eliminar;

        avl->eliminarNivel(proyecto, nivel_eliminar);

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
}

void cargarArchivo(string ruta)
{
    //Variables de los objetos que irán en el abb de objetos
    int id_objeto = 0;
    int x, y;
    string nombre;
    string letra;
    string color;
    string nombreP;

    // Coordenadas de las paredes
    int x_inicial, x_final;
    int y_inicial, y_final;

    // Coordenadas de las ventanas
    int x_inicial_v, x_final_v;
    int y_inicial_v, y_final_v;

    std::ifstream archivo(ruta);
    int n_nivel = 0;
    if (archivo.fail())
    {
        cout << " El archivo no existe.";
    }
    else
    {
        //cout << " Archivo cargado" << endl;
        archivo >> totalJSON;
        nombreP = totalJSON["nombre"].get<std::string>();

        //std::cout << totalJSON["nombre"].get<std::string>() << endl;
        id = convertirASCII(nombreP);
        cout << " Valor ascii: " << convertirASCII(nombreP) << endl;

        //fflush(stdin);
        avl->insertar(id);
        //avl->crearListaNiveles(avl->getRaiz(), convertirASCII(nombreProyectoJson));
        //avl->crearABB(avl->getRaiz(), id)
        nivelesJson = totalJSON["niveles"];
        for (const auto pos : nivelesJson)
        {

            n_nivel = pos["nivel"];
            fflush(stdin);
            avl->insertarNivel(id, n_nivel);

            /*
                Paredes
                Ventanas
                objetos
            */
            paredesJson = pos["paredes"];

            // Agregando paredes
            for (const auto pos : paredesJson)
            {

                x_inicial = pos["inicio"][0];
                y_inicial = pos["inicio"][1];

                x_final = pos["final"][0];
                y_final = pos["final"][1];

                // CRECE EN X
                if ((x_final > x_inicial) && (y_inicial = y_final))
                {
                    for (int i = x_inicial; i <= x_final; i++)
                    {
                        avl->insertarEnMatriz(id, n_nivel, i, "p", "#726D66", i + 1, y_inicial + 1);
                        //avl->insertarnodoABB(id, n_nivel, i, "pared", "p", color, x, y);
                    }
                }
                // CRECE EN Y
                else if ((y_final > y_inicial) && (x_inicial == x_final))
                {
                    for (int j = y_inicial; j <= y_final; j++)
                    {
                        avl->insertarEnMatriz(id, n_nivel, j, "p", "#726D66", x_inicial + 1, j + 1);
                        //avl->insertarnodoABB(id, n_nivel, j, "pared", "p", color, x, y);
                    }
                }

                //break;

                //
            }

            ventanasJson = pos["ventanas"];

            // Agregando ventanas
            for (const auto pos : ventanasJson)
            {
                x_inicial_v = pos["inicio"][0];
                y_inicial_v = pos["inicio"][1];

                x_final_v = pos["final"][0];
                y_final_v = pos["final"][1];

                // CRECE EN X
                if ((x_final_v > x_inicial_v) && (y_inicial_v == y_final_v))
                {
                    for (int i = x_inicial_v; i <= x_final_v; i++)
                    {
                        avl->insertarEnMatriz(id, n_nivel, i, "v", "#0BDFD6", i + 1, y_inicial_v + 1);
                    }
                }
                // CRECE EN Y
                else if ((y_final_v > y_inicial_v) && (x_inicial_v == x_final_v))
                {
                    for (int j = y_inicial_v; j <= y_final_v; j++)
                    {
                        avl->insertarEnMatriz(id, n_nivel, j, "p", "#0BDFD6", x_inicial_v + 1, j + 1);
                    }
                }
            }

            objetosJson = pos["objetos"];

            for (const auto pos : objetosJson)
            {

                id_objeto = pos["identificador"];
                nombre = pos["nombre"];
                letra = pos["letra"];
                color = pos["color"];

                puntosObjetosJson = pos["puntos"];

                for (const auto pos : puntosObjetosJson)
                {
                    //cout << " - Inicio: " << pos["x"] << " Final: " << pos["y"] << endl;
                    x = pos["x"];
                    y = pos["y"];

                    //AGREGAR OBJETOS A LA MATRIZ
                    avl->insertarEnMatriz(id, n_nivel, id_objeto, letra, color, x + 1, y + 1);
                    //avl->insertarnodoABB(id, n_nivel, id_objeto, nombre, letra, color, x, y);
                    //break;
                }

                //break;
            }
        }
    }

    archivo.close();
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

                abbGlobal->insertarNodo(new NodoArbol(id, nombre, letra, color, x, y));
            }
            std::cout << " \n";
        }
    }

    libreria.close();
    //abbGlobal->imprimirArbol(abbGlobal->raiz, 0);
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
