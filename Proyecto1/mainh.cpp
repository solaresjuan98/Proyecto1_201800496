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
json proyectosJson;
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
string r1, r2, r3, r4, r5;

int eleccion_p = 0;

int main()
{
    /*
    for (int i = 0; i < 51; i++)
    {
        avl->insertar(i);

        for (int j = 0; j < 6; j++)
        {
            avl->insertarNivel(i, j);

            for (int k = 0; k < 20; k++)
            {
                for (int l = 0; l < 18; l++)
                {
                    avl->insertarEnMatriz(i, j, 1, "l", "gray", k + 1, l + 1);
                }
            }
        }
    }*/

    /*
    avl->insertar(convertirASCII("JuanSolares"));
    avl->insertar(convertirASCII("Proyecto1"));
    avl->insertar(convertirASCII("Compiladores"));
    avl->insertar(convertirASCII("Guatemala"));
    avl->insertar(convertirASCII("VillaNueva"));
    avl->imprimir(avl->getRaiz(), 0);
    */

    /*
    Matrix *prueba = new Matrix();

    prueba->add(1, "m", "#0BDFD6", 2, 1);
    prueba->add(8, "j", "#B28912", 2, 2);
    prueba->add(9, "r", "#B28912", 2, 3);
    prueba->add(19, "k", "#B28912", 3, 3);
    prueba->add(39, "n", "#B28912", 5, 3);
    prueba->add(11, "z", "#B28912", 3, 2);


    prueba->delete_object(3, 3);
    prueba->delete_object(2, 1);
    prueba->move_object(2, 2, 6, 2);
    prueba->move_object(2, 3, 5, 7);
    prueba->generarMatriz();
    */

    //cargarArchivo("ejemplo1.json");
    //cargarArchivo("Archivos/prueba.json");
    //cargarArchivo("Archivos/prueba2.json");
    //cout << convertirASCII("febrero") << endl;
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
    int sub_opc = 0;
    int num_proyectos = 0;
    string nombre_proyecto;
    int id_proyecto, num_niveles;
    int id_objeto_lib = 0;
    // vairalbes de libreria
    string nombre_obj;
    string letra;
    string color;
    int x, y;

    cout << "\t ::: BIENVENIDO A PSEUDO-CAD ::: \n";
    cout << " Elige una opcion: " << endl;
    cout << " 1. Ver proyectos " << endl;
    cout << " 2. Editar proyectos " << endl;
    cout << " 3. Crear proyecto (manual) " << endl;
    cout << " 4. Cargar proyecto" << endl;
    cout << " 5. Guardar proyectos" << endl;
    cout << " 6. Cargar librerias" << endl;
    cout << " 7. Limpiar consola " << endl;
    cout << " 8. Seccion de reportes" << endl;
    cout << " 9. Gestionar librerias " << endl;
    cout << " 10. Salir de la aplicacion " << endl;
    cout << " Elige una opcion: ";

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
            cout << " >> Crear proyectos " << endl;
            cout << " << ¿Deseas crear proyecto por nombre o por numero?" << endl;
            cout << " << 1. Cargar por medio de codigo ASCII" << endl;
            cout << " << 2. Crear masivamente " << endl;
            cin >> sub_opc;

            // convirtiendo ascii
            if (sub_opc == 1)
            {
                cout << " >> Escribe el nombre del proyecto " << endl;
                cin.get();
                getline(cin, nombre_proyecto);
                id_proyecto = convertirASCII(nombre_proyecto);
                avl->insertar(id_proyecto);
                cout << " >> ¿Cuantos niveles deseas crear? " << endl;
                cin >> num_niveles;
                for (int i = 1; i < num_niveles; i++)
                {
                    avl->insertarNivel(id_proyecto, i);
                }
                cin.get();
            }
            //Agregando masivamente
            else if (sub_opc == 2)
            {
                cout << " << ¿Cuantos proyectos deseas crear ? ";
                cin >> num_proyectos;

                for (int i = 1; i <= num_proyectos; i++)
                {
                    avl->insertar(i);
                }

                cin.get();
            }

            system("clear");
            mostrarMenu();

        case 4:
            cout << "\n Cargar archivo: " << endl;
            cout << " Escribe la ruta del archivo: ";
            cin.get();
            getline(cin, ruta);
            cargarArchivo(ruta);

            cin.get();
            //r1 = "ejemplo1.json";
            /*r2 = "Archivos/ejemplo2.json";
            r3 = "Archivos/ejemplo3.json";
            r4 = "Archivos/ejemplo4.json";*/
            //r5 = "Archivos/ejemplo5.json";

            //cargarArchivo("ejemplo1.json");
            /*cargarArchivo(r2);
            cargarArchivo(r3);
            cargarArchivo(r4);*/
            //cargarArchivo(r5);
            system("clear");
            mostrarMenu();
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
            system("clear");
            mostrarMenu();
            break;
        case 8:
            system("clear");
            mostrarMenuReportes();
            //exit(1);
            break;
        case 9:
            system("clear");
            cout << " << :: GESTION DE LIBRERIAS :: " << endl;
            cout << " << 1. Ver librerias cargadas " << endl;
            cout << " << 2. Agregar objetos a la libreria " << endl;
            cout << " << 3. Eliminar objetos de la libreria " << endl;
            cout << " << 4. Buscar objeto " << endl;
            cout << " << 5. Regresar a menu principal" << endl;
            cout << " << Elige una opcion: ";
            cin >> sub_opc;

            if (sub_opc == 1)
            {
                cin.get();
                cout << "\n >> :: OBJETOS EN LIBRERIA " << endl;
                abbGlobal->inOrden(abbGlobal->raiz);
            }
            // Agregando objetos a la libreria
            else if (sub_opc == 2)
            {
                cout << " >> Ingresa id.: ";
                cin.get();
                cin >> id_objeto_lib;
                cout << " >> Ingresa Nombre del objeto: ";
                cin.get();
                getline(cin, nombre_obj);
                cout << " >> Ingresa letra: ";
                cin.get();
                getline(cin, letra);
                cin.get();
                cout << " >> Ingresa color: ";
                cout << " >> :: Colores sugeridos " << endl;
                cout << "     ->  #46DC1A (verde) " << endl;
                cout << "     ->  #DA3923 (rojo) " << endl;
                cout << "     ->  #2384DA (azul) " << endl;
                cout << "     ->  #BC23DA (purpura) " << endl;
                cout << "     ->  #F3EF16 (verde) " << endl;
                cin.get();
                getline(cin, color);
                cout.flush();
                cout << " >> Ingresa coordenada en x: ";
                cin.get();
                cin >> x;
                cout << " >> Ingresa coordenada en y: ";
                cin.get();
                cin >> y;

                abbGlobal->insertarNodo(new NodoArbol(id_objeto_lib, nombre_obj, letra, color, x, y));
            }
            // Eliminando objetos de la libreria
            else if (sub_opc == 3)
            {
                cout << "\n >> :: OBJETOS EN LIBRERIA " << endl;
                abbGlobal->inOrden(abbGlobal->raiz);
                cout << endl;
                cout << " >> Selecciona un objeto (por id) para eliminar: ";
                cin >> id_objeto_lib;
                abbGlobal->eliminar(id_objeto_lib);
            }
            // Buscando un objero
            else if (sub_opc == 4)
            {
                cout << " :: BUSQUEDA DE OBJETO " << endl;
                cout << " >> busca por id: ";
                cin >> id_objeto_lib;

                NodoArbol *nodo = abbGlobal->raiz;
                abbGlobal->busqueda(abbGlobal->raiz, id_objeto_lib);

                if (abbGlobal->busqueda(nodo, id_objeto_lib) == NULL)
                {
                    cout << " >> Nodo no existente. " << endl;
                }
                else
                {
                    cin.get();
                    cout << " :: Resultado " << endl;
                    cout << " >> Id. " << abbGlobal->busqueda(nodo, id_objeto_lib)->id << endl;
                    cout << " >> Nombre: " << abbGlobal->busqueda(nodo, id_objeto_lib)->nombre << endl;
                    cout << " >> Color: " << abbGlobal->busqueda(nodo, id_objeto_lib)->color << endl;
                    cout << " >> Letra: " << abbGlobal->busqueda(nodo, id_objeto_lib)->letra << endl;
                    cout << " >> Pos. en x: " << abbGlobal->busqueda(nodo, id_objeto_lib)->x << endl;
                    cout << " >> Pos. en y; " << abbGlobal->busqueda(nodo, id_objeto_lib)->y << endl;
                }
            }
            // Regresando al menu
            else if (sub_opc == 5)
            {
                system("clear");
                mostrarMenu();
            }

            break;

        case 10:
            exit(1);
            ;
            //avl->imprimirMatriz(97, 1);
            //avl->imprimirMatriz(98, 1);
            //avl->imprimirMatriz(99, 1);
            //avl->imprimirMatriz(104, 1);
            break;
        }

        cin.get();

    } while (opcion != 11);
}

void mostrarMenuReportes()
{
    int opcion = 0;
    int opc_reporte = 0;
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
            avl->generarListaPDesc(avl->getRaiz());
            avl->imprimirDesc();
            cin.get();
            system("clear");
            mostrarMenuReportes();
            break;

        case 5:
            cin.get();
            avl->inOrden(avl->getRaiz());
            cout << " >> Selecciona un proyecto: ";
            cin >> opc_reporte;
            cin.get();
            avl->genListaNivelesPorObjeto(opc_reporte);
            avl->imprimirListaNivelesPorObjeto(opc_reporte);
            cin.get();
            system("clear");
            mostrarMenuReportes();

            break;

        case 6:
            cin.get();
            avl->inOrden(avl->getRaiz());
            cout << " >> Selecciona un proyecto: ";
            cin >> opc_reporte;
            cin.get();
            avl->genListaMasEspacio(opc_reporte);
            avl->imprimirListaMasEspacio(opc_reporte);
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
    cout << " 5. Buscar Proyecto" << endl;
    cout << " 6. Regresar " << endl;
    cout << " >> Elige una opción: ";
    int opcion_editar;
    int proyecto;
    int num_niveles_nuevos;
    int nivel_eliminar;
    int nivel_matriz;
    int sub_opcion;

    // Objeto a agregar
    int id, x, y, x_, y_;
    string letra, color;
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
        cout << " >> Elige un nivel";
        cin >> nivel_matriz;
        cin.get();
        cout << " >> ¿Que deseas hacer? " << endl;
        cout << " >> 1. Agregar objeto " << endl;
        cout << " >> 2. Mover objeto " << endl;
        cout << " >> 3. Eliminar objeto " << endl;
        cout << " >> 4. Agregar Ventanas " << endl;
        cout << " >> 5. Agregar Paredes " << endl;
        cout << " >> 6. Agregar objetos en masa " << endl;
        cout << " >> Elige una opcion: ";
        cin >> sub_opcion;

        // Agregar objeto
        if (sub_opcion == 1)
        {

            cout << " >> Ingresa id.: ";
            cin.get();
            cin >> id;
            cout << " >> Ingresa letra: ";
            cin.get();
            cin >> letra;
            cin.get();
            cout << " >> Ingresa color: ";
            cout << " >> :: Colores sugeridos " << endl;
            cout << "     ->  #46DC1A (verde) " << endl;
            cout << "     ->  #DA3923 (rojo) " << endl;
            cout << "     ->  #2384DA (azul) " << endl;
            cout << "     ->  #BC23DA (purpura) " << endl;
            cout << "     ->  #F3EF16 (verde) " << endl;
            cin.get();
            cin >> color;
            cout.flush();
            cout << " >> Ingresa coordenada en x: ";
            cin.get();
            cin >> x;
            cout << " >> Ingresa coordenada en y: ";
            cin.get();
            cin >> y;

            avl->insertarEnMatriz(proyecto, nivel_matriz, id, letra, color, x, y);

            cout << " >> Objeto agregado. " << endl;
        }
        // Mover objeto
        else if (sub_opcion == 2)
        {

            cin.get();
            cout << " >> Ingresa coordenada inicial en x: ";
            cin >> x;
            cout << " >> Ingresa coordenada inicial en y: ";
            cin >> y;
            cout << " >> Ingresa coordenada a mover en x: ";
            cin >> x_;
            cout << " >> Ingresa coordenada a mover en y: ";
            cin >> y_;

            avl->moverenMatriz(proyecto, nivel_matriz, x, y, x_, y_);
        }
        // eliminar
        else if (sub_opcion == 3)
        {

            cin.get();
            cout << " >> Ingresa coordenada en x: ";
            cin >> x;
            cout << " >> Ingresa coordenada en y: ";
            cin >> y;
            avl->eliminarDeMatriz(proyecto, nivel_matriz, x, y);
        }
        // Agregar ventanas
        else if (sub_opcion == 4)
        {
            cin.get();
            cout << " >> Ingresa coordenada inicial en x: ";
            cin >> x;
            cout << " >> Ingresa coordenada inicial en y: ";
            cin >> y;
            cout << " >> Ingresa coordenada final en x: ";
            cin >> x_;
            cout << " >> Ingresa coordenada final en y: ";
            cin >> y_;

            // CRECE EN X
            if ((x_ > x) && (y = y_))
            {
                for (int i = x; i <= x_; i++)
                {
                    avl->insertarEnMatriz(proyecto, nivel_matriz, i, "v", "#84E3D5", i, y);
                    //avl->insertarnodoABB(id, n_nivel, i, "pared", "p", color, x, y);
                }
            }
            // CRECE EN Y
            else if ((y_ > y) && (x == x_))
            {
                for (int j = y; j <= y_; j++)
                {
                    avl->insertarEnMatriz(proyecto, nivel_matriz, j, "v", "#84E3D5", x, j);
                    //avl->insertarnodoABB(id, n_nivel, j, "pared", "p", color, x, y);
                }
            }
        }
        // Agregar paredes
        else if (sub_opcion == 5)
        {
            cin.get();
            cout << " >> Ingresa coordenada inicial en x: ";
            cin >> x;
            cout << " >> Ingresa coordenada inicial en y: ";
            cin >> y;
            cout << " >> Ingresa coordenada final en x: ";
            cin >> x_;
            cout << " >> Ingresa coordenada final en y: ";
            cin >> y_;

            // CRECE EN X
            if ((x_ > x) && (y = y_))
            {
                for (int i = x; i <= x_; i++)
                {
                    avl->insertarEnMatriz(proyecto, nivel_matriz, i, "p", "#758A87", i, y);
                    //avl->insertarnodoABB(id, n_nivel, i, "pared", "p", color, x, y);
                }
            }
            // CRECE EN Y
            else if ((y_ > y) && (x == x_))
            {
                for (int j = y; j <= y_; j++)
                {
                    avl->insertarEnMatriz(proyecto, nivel_matriz, j, "p", "#758A87", x, j);
                    //avl->insertarnodoABB(id, n_nivel, j, "pared", "p", color, x, y);
                }
            }
        }
        // Agregar en masa
        else if (sub_opcion == 6)
        {
            cout << " >> Ingresa id.: ";
            cin.get();
            cin >> id;
            cout << " >> Ingresa letra: ";
            cin.get();
            cin >> letra;
            cin.get();
            cout << " >> Ingresa color: ";
            cout << " >> :: Colores sugeridos " << endl;
            cout << "     ->  #46DC1A (verde) " << endl;
            cout << "     ->  #DA3923 (rojo) " << endl;
            cout << "     ->  #2384DA (azul) " << endl;
            cout << "     ->  #BC23DA (purpura) " << endl;
            cout << "     ->  #F3EF16 (verde) " << endl;
            cin.get();
            getline(cin, color);
            cout << " >> Ingresa coordenada en x: ";
            cin.get();
            cin >> x;
            cout << " >> Ingresa coordenada en y: ";
            cin.get();
            cin >> y;
            cout << " >> Ingresa coordenada final en x: ";
            cin >> x_;
            cout << " >> Ingresa coordenada final en y: ";
            cin >> y_;

            // CRECE EN X
            if ((x_ > x) && (y = y_))
            {
                for (int i = x; i <= x_; i++)
                {
                    avl->insertarEnMatriz(proyecto, nivel_matriz, i, letra, color, i, y);
                    //avl->insertarnodoABB(id, n_nivel, i, "pared", "p", color, x, y);
                }
            }
            // CRECE EN Y
            else if ((y_ > y) && (x == x_))
            {
                for (int j = y; j <= y_; j++)
                {
                    avl->insertarEnMatriz(proyecto, nivel_matriz, j, letra, color, x, j);
                    //avl->insertarnodoABB(id, n_nivel, j, "pared", "p", color, x, y);
                }
            }
        }

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

        cout << " >> ELIMINAR PROYECTO " << endl;
        avl->inOrden(avl->getRaiz());
        cout << endl;
        cin.get();
        cout << "Elige un poryecto (por id): ";
        cin >> proyecto;

        avl->eliminar(proyecto);
        avl->inOrden(avl->getRaiz());

        break;
    case 5:

        cout << " >> BUSCAR PROYECTO " << endl;
        cout << " Ingresa un id: ";
        cin >> proyecto;

        cin.get();
        if (avl->busquedaNodo(avl->getRaiz(), proyecto) != NULL)
        {
            getListaNivelesNodo(proyecto);
        }
        else
        {
            cout << " >> No encontrado " << endl;
        }
        break;

    case 6:
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
    //nlohmann:: json j = nlohmann::json::parse(archivo);
    //int iterador;
    int n_nivel = 0;
    if (archivo.fail())
    {
        cout << " El archivo no existe.";
    }
    else
    {
        //cout << " Archivo cargado" << endl;
        archivo >> totalJSON;

        //proyectosJson = totalJSON["proyectos"];
        if (totalJSON["proyectos"] != NULL)
        {
            for (const auto pos : totalJSON["proyectos"])
            {
                nombreP = pos["nombre"];
                id = convertirASCII(nombreP);
                //avl->insertar(id);
                cout << " Valor ascii: " << convertirASCII(nombreP) << endl;
                avl->insertar(id);

                if (pos["niveles"] != NULL)
                {
                    for (const auto niv : pos["niveles"])
                    {
                        avl->insertar(id);
                        cout << niv["nivel"] << endl;
                        n_nivel = niv["nivel"];
                        avl->insertarNivel(id, n_nivel);

                        //cout << niv["paredes"] << endl;
                        if (niv["paredes"] != NULL)
                        {
                            for (const auto pared : niv["paredes"])
                            {
                                cout << pared["inicio"] << endl;

                                x_inicial = pared["inicio"][0];
                                y_inicial = pared["inicio"][1];

                                x_final = pared["final"][0];
                                y_final = pared["final"][1];

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
                            }
                        }

                        if (niv["ventanas"] != NULL)
                        {
                            for (const auto ventana : niv["ventanas"])
                            {
                                cout << ventana["inicio"] << endl;

                                x_inicial_v = ventana["inicio"][0];
                                y_inicial_v = ventana["inicio"][1];

                                x_final_v = ventana["final"][0];
                                y_final_v = ventana["final"][1];

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
                        }

                        if (niv["objetos"] != NULL)
                        {
                            for (const auto obj : niv["objetos"])
                            {
                                cout << obj["identificador"] << endl;
                                cout << obj["nombre"].get<std::string>() << endl;
                                cout << obj["letra"].get<std::string>() << endl;
                                cout << obj["color"].get<std::string>() << endl;

                                id_objeto = obj["identificador"];
                                nombre = obj["nombre"];
                                letra = obj["letra"];
                                color = obj["color"];

                                if (obj["puntos"] != NULL)
                                {
                                    for (const auto punto : obj["puntos"])
                                    {
                                        cout << punto["x"] << endl;
                                        cout << punto["y"] << endl;
                                        x = punto["x"];
                                        y = punto["y"];

                                        avl->insertarEnMatriz(id, n_nivel, obj["identificador"], obj["letra"].get<std::string>(), obj["color"].get<std::string>(), x + 1, y + 1);
                                    }
                                }
                            }
                        }
                    }
                }
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
