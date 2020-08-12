#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "json.hpp"
#include <time.h>
using namespace std;
using json = nlohmann::json;

// funciones principales
void mostrarDatos();
void mostrarMenu();
void cargarArchivo(string);

//variables de lectura de archivo JSON
json totalJSON;
json nivelesJson;
json paredesJson;
json ventanasJson;
json objetosJson;
json puntosObjetosJson;

string ruta;

//funciones para mostrar los datos del archivoJSON
void mostrarNiveles(json j);
void mostrarParedes(json j);
void mostrarVentanas(json j);
void mostrarObjetos(json j);
void mostrarPuntosObjetos(json j);

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
    cout << " Elige una opcion: ";

    cin >> opcion;

    do
    {
        switch (opcion)
        {
        case 1:
            cout << "\n Proyectos existentes:"<<endl;
            //imprimir arbol avl de proyectos existentes
            break;
        case 2:

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

            break;
        case 7:
            //system("clear");
            break;
        case 8:
            exit(1);
            break;

        default:
            break;
        }

        cin.get();

    } while (opcion != 7);
}

void cargarArchivo(string ruta)
{
    std::ifstream archivo(ruta);

    if (archivo.fail())
    {
        cout << " El archivo no existe.";
    }
    else
    {
        archivo >> totalJSON;
        nivelesJson = totalJSON["niveles"];
        mostrarNiveles(nivelesJson);
    }
}

void mostrarNiveles(json j)
{
    cout << " \nNiveles: \n";

    for (const auto pos : j)
    {
        cout << " - Nivel " << pos["nivel"] << endl;

        //Obtengo las pos. de las paredes
        paredesJson = pos["paredes"];
        mostrarParedes(paredesJson);

        //Obtengo las pos. de las ventanas
        ventanasJson = pos["ventanas"];
        mostrarVentanas(ventanasJson);

        //Obtengo los datos de los objetos
        objetosJson = pos["objetos"];
        mostrarObjetos(objetosJson);
    }

    cout << "\n";
}

void mostrarParedes(json j)
{
    cout << " \nParedes: \n";
    for (const auto pos : j)
    {
        cout << " - " << pos["inicio"] << " -- " << pos["final"] << endl;
    }

    cout << "\n";
}

void mostrarVentanas(json j)
{
    cout << " \nVentanas: \n";

    for (const auto pos : j)
    {
        cout << " - " << pos["inicio"] << " -- " << pos["final"] << endl;
    }

    cout << "\n";
}

void mostrarObjetos(json j)
{
    cout << " \nObjetos: \n";

    for (const auto pos : j)
    {
        cout << " - Identificador: " << pos["identificador"] << endl;
        cout << " - Nombre: " << pos["nombre"].get<std::string>() << endl;
        cout << " - Letra: " << pos["letra"].get<std::string>() << endl;
        cout << " - Color: " << pos["color"].get<std::string>() << endl;

        // obtengo los puntos de los objetos
        puntosObjetosJson = pos["puntos"];
        mostrarPuntosObjetos(puntosObjetosJson);
    }

    cout << "\n";
}

void mostrarPuntosObjetos(json j)
{
    cout << " \nPuntos objetos: \n";

    for (const auto pos : j)
    {
        cout << " - Inicio: " << pos["x"] << " Final: " << pos["y"] << endl;
    }

    cout << "\n";

    //mostrarMenu();
}