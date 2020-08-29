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
#include "Clases/ListaNiveles.h"
#include "Clases/NodoNivel.h"

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
    cout << " 10. Buscar Proyecto " << endl;
    cout << " Elige una opcion: ";

    cin >> opcion;

    do
    {
        switch (opcion)
        {
        case 1:
            cout << "\n Proyectos existentes:" << endl;
            //imprimir arbol avl de proyectos existentes
            //avl->imprimir(avl->getRaiz(), 0);
            avl->inOrden(avl->getRaiz());
            cout << "\n\n";
            cin.get();
            mostrarMenu();
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
            cargarArchivo(ruta);
            cin.get();
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
            cin.get();
            mostrarMenu();
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

            break;
        case 10:
            {
                int num;
                cout << " Ingresa el id que deseas buscar: ";
                cin >> num;

                if (avl->busqueda(avl->getRaiz(), num))
                {
                    cout << " Proyecto encontrado " << endl;
                }
                else
                {
                    cout << " Proyecto no encontrado " << endl;
                }

                cout << "\n";

                break;
            }
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
        nombreProyectoJson = totalJSON["nombre"];
        string nombreP;

        cout << totalJSON["nombre"].get<std::string>() << endl;
        id = convertirASCII(nombreProyectoJson);
        cout << " Valor ascii: " << id << endl;

        avl->insertar(id);
        avl->crearListaNiveles(avl->getRaiz(), id);

        nivelesJson = totalJSON["niveles"];
        cout << "\n";
        for (const auto pos : nivelesJson)
        {
            //cout << "  Nivel: " << pos["nivel"] << endl;

            /*
                Paredes
                Ventanas
                objetos
            */
            paredesJson = pos["paredes"];
            //cout << " Parades: " << endl;

            for (const auto pos : paredesJson)
            {
               // cout << " - " << pos["inicio"] << " -- " << pos["final"] << endl;
            }

            ventanasJson = pos["ventanas"];

            for (const auto pos : ventanasJson)
            {
                //cout << " ";
            }

            objetosJson = pos["objetos"];

            for (const auto pos : objetosJson)
            {
                /*cout << " - Identificador: " << pos["identificador"] << endl;
                cout << " - Nombre: " << pos["nombre"].get<std::string>() << endl;
                cout << " - Letra: " << pos["letra"].get<std::string>() << endl;
                cout << " - Color: " << pos["color"].get<std::string>() << endl;*/

                puntosObjetosJson = pos["puntos"];

                for (const auto pos : puntosObjetosJson)
                {
                    //cout << " - Inicio: " << pos["x"] << " Final: " << pos["y"] << endl;
                }
            }

            cout << "\n";
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
        cout << " La libreria no existe";
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
                //cout << "     x: " << pos["x"] << endl;
                //cout << "     y: " << pos["y"] << endl;

                x = pos["x"];
                y = pos["y"];
                cout << "\n";

                abbGlobal->insertarNodo(new NodoArbolGlobal(id, nombre, letra, color, x, y));
            }
            cout << " \n";
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
