#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "json.hpp"
#include <time.h>

//clases
#include "Clases/Matrix.h"
#include "Clases/ArbolAVL.h"
#include "Clases/ArbolBinario.h"
#include "Clases/NodoArbolGlobal.h"

using namespace std;
using json = nlohmann::json;

// funciones principales
void mostrarDatos();
void mostrarMenu();

//variables de lectura de archivo JSON
json totalJSON;
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

//Esctructuras
ArbolBinario *abbGlobal = new ArbolBinario();

// ruta de archivo a leer
string ruta;
string cadena;
// Variables de atributos de nivel
int numeroNivel;
int id = 0;
//funciones para mostrar los datos del archivoJSON
void mostrarNiveles(json j);
void mostrarParedes(json j);
void mostrarVentanas(json j);
void mostrarObjetos(json j);
void mostrarPuntosObjetos(json j);
void cargarArchivo(string ruta);
void cargarLibrerias(string ruta);
int convertirASCII(string cadena);
int main()
{
    mostrarDatos();
    mostrarMenu();

    cin.get();
    return 0;
}

void mostrarDatos()
{
    cout << " ************************************************** " << endl;
    cout << " * USAC                                           * " << endl;
    cout << " * Estructuras de Datos                           * " << endl;
    cout << " * Seccion A                                      * " << endl;
    cout << " * Juan Antonio Solares Samayoa                   * " << endl;
    cout << " * 201800496                                      * " << endl;
    cout << " ************************************************** " << endl;
}

void mostrarMenu()
{
    int opcion = 0;

    cout << "\t ::: BIENVENIDO A PSEUDO-CAD ::: \n";
    cout << " Elige una opcion: " << endl;
    cout << " 1. Ver proyectos " << endl;
    cout << " 2. Editar proyectos " << endl;
    cout << " 3. Cargar proyecto" << endl;
    cout << " 4. Graficar proyectos" << endl;
    cout << " 5. Guardar proyectos" << endl;
    cout << " 6. Cargar librerias" << endl;
    cout << " 7. Limpiar consola " << endl;
    cout << " 8. Salir de la aplicacion " << endl;
    cout << " 9. Lista de prueba " << endl;
    cout << " Elige una opcion: ";

    cin >> opcion;

    do
    {
        switch (opcion)
        {
        case 1:
            cout << "\n Proyectos existentes:" << endl;
            //imprimir arbol avl de proyectos existentes
            break;
        case 2:
            /*
            cout << "\nescribe algo \n";
            cin.get();
            getline(cin, cadena);
            id = convertirASCII(cadena);
            cout << " Valor ascii: " << id << endl;
            */

            break;
        case 3:
            cout << "\n Cargar archivo: " << endl;
            cout << " Escribe la ruta del archivo: ";
            cin.get();
            getline(cin, ruta);
            //NodoAVL *nuevo = new NodoAVL()
            cargarArchivo(ruta);
            cin.get();
            id = convertirASCII(ruta);
            cout << " Ascii: " << id << endl;
            mostrarMenu();
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            cout << "\n Cargar librerias\n";
            cout << "\n Cargar libreria: " << endl;
            cout << " Escribe la ruta del libreria: ";
            cin.get();
            getline(cin, ruta);
            cargarLibrerias(ruta);
            /*for (int i = 0; i < 3; i++)
            {
                abbGlobal->insertarNodo(new NodoArbolGlobal(i, "Sofa", 'A', "Azul", 0, i));
            }
            
            abbGlobal->imprimirArbol(abbGlobal->raiz, 0);*/
            //cin.get();
            break;
        case 7:
            //system("clear");
            break;
        case 8:
            exit(1);
            break;
        case 9:
            /*
            Matrix *md = new Matrix();

            md->add(10, "Mesa", 2, 1);
            md->add(12, "TV", 3, 1);
            md->add(14, "Lampara", 3, 2);
            md->add(12, "Sillon", 5, 4);
            md->add(13, "Escritorio", 4, 3);

            md->print_headers();
            md->print_nodes_x();
            md->print_nodes_y();
        */
            /*
            ArbolAVL *arbol = new ArbolAVL();

            arbol->insertar(1);
            arbol->insertar(2);
            arbol->insertar(3);
            arbol->insertar(4);
            arbol->insertar(5);
            arbol->insertar(6);
            arbol->insertar(7);

            cout << "\n\n";
            arbol->imprimir(arbol->getRaiz(), 0);

            delete arbol;
        */
            break;
        }

        cin.get();

    } while (opcion != 10);
}

void cargarArchivo(string ruta)
{
    //cout << p1.getIdProyecto() << endl;
    std::ifstream archivo(ruta);

    if (archivo.fail())
    {
        cout << " El archivo no existe.";
    }
    else
    {
        cout << " Archivo cargado" << endl;
        archivo >> totalJSON;
        nivelesJson = totalJSON["niveles"];
        mostrarNiveles(nivelesJson);
    }
}

void cargarLibrerias(string ruta)
{
    int id, x, y;
    string nombre, letra, color;

    ifstream libreria(ruta);

    if (libreria.fail())
    {
        cout << " La libreria no existe";
    }
    else
    {
        libreria >> libJSON;
        idJson = libJSON["Libreria"];

        for (const auto pos : idJson)
        {
            /*cout << " - Identificador: " << pos["identificador"] << endl;
            cout << " - Nombre: " << pos["nombre"].get<std::string>() << endl;
            cout << " - Letra: " << pos["letra"].get<std::string>() << endl;
            cout << " - Color: " << pos["color"].get<std::string>() << endl;*/
            
            id = pos["identificador"];
            nombre = pos["nombre"].get<std::string>();
            letra  = pos["letra"].get<std::string>();
            color = pos["color"].get<std::string>();

            puntos_lib = pos["puntos"];

            for (const auto pos : puntos_lib)
            {
                cout << "     x: " << pos["x"] << endl;
                cout << "     y: " << pos["y"] << endl;

                x = pos["x"];
                y = pos["y"];
                cout << "\n";

                abbGlobal->insertarNodo(new NodoArbolGlobal(id, nombre, letra, color, x, y));
            }
            cout << " \n";
        }
    }

    /*
    for (int i = 1; i < 4; i++)
    {
        abbGlobal->insertarNodo(new NodoArbolGlobal(i, "Sofa", 'A', "Azul", 0, i));
    }*/

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

void mostrarNiveles(json j)
{
    //NodoNivel *nivelNuevo = new NodoNivel();
    int nivel;
    //p.verNiveles();
    //Proyecto p;
    //p = Proyecto(1);
    //p.verNiveles();

    cout << " \nNiveles: \n";

    for (const auto pos : j)
    {
        cout << " - Nivel " << pos["nivel"] << endl;
        nivel = pos["nivel"];
        //nivelNuevo->id = nivel;
        //lista.agregarNuevoNivel(nivelNuevo);

        //Obtengo las pos. de las paredes
        /*paredesJson = pos["paredes"];
        mostrarParedes(paredesJson);

        //Obtengo las pos. de las ventanas
        ventanasJson = pos["ventanas"];
        mostrarVentanas(ventanasJson);

        //Obtengo los datos de los objetos
        objetosJson = pos["objetos"];
        mostrarObjetos(objetosJson);*/

        //lista.agregarNuevoNivel(nivelNuevo);
    }
    cout << "\n";
}

void mostrarParedes(json j)
{
    //cout << " \nParedes: \n";
    for (const auto pos : j)
    {
        // cout << " - " << pos["inicio"] << " -- " << pos["final"] << endl;
    }

    //cout << "\n";
}

void mostrarVentanas(json j)
{
    //cout << " \nVentanas: \n";

    for (const auto pos : j)
    {
        // cout << " - " << pos["inicio"] << " -- " << pos["final"] << endl;
    }

    //cout << "\n";
}

void mostrarObjetos(json j)
{
    //cout << " \nObjetos: \n";

    for (const auto pos : j)
    {
        /*
        cout << " - Identificador: " << pos["identificador"] << endl;
        cout << " - Nombre: " << pos["nombre"].get<std::string>() << endl;
        cout << " - Letra: " << pos["letra"].get<std::string>() << endl;
        cout << " - Color: " << pos["color"].get<std::string>() << endl;
        */
        // obtengo los puntos de los objetos
        puntosObjetosJson = pos["puntos"];
        mostrarPuntosObjetos(puntosObjetosJson);
    }

    cout << "\n";
}

void mostrarPuntosObjetos(json j)
{

    //cout << " \nPuntos objetos: \n";

    for (const auto pos : j)
    {
        // cout << " - Inicio: " << pos["x"] << " Final: " << pos["y"] << endl;
    }
}