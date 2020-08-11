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
void cargarArchivo();

//variables de lectura de archivo JSON
json totalJSON;
json nivelesJson;
json paredesJson;
json ventanasJson;
json objetosJson;
json puntosObjetosJson;

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

            break;
        case 2:

            break;
        case 3:
            cout << "\n Cargar archivo: "<<endl;
            cargarArchivo();
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


void cargarArchivo()
{
    string ruta;
    cout << " Escribe la ruta del archivo: ";
    cin.get();
    getline(cin, ruta);

    std::ifstream archivo(ruta);

    if(archivo.fail())
    {
        cout << " El archivo no se ha encontrado. "<<endl;
    }else{
        //cout << " Archivo encontrado." <<endl;
        archivo >> totalJSON;
        nivelesJson = totalJSON["niveles"];
    }
    

    
}