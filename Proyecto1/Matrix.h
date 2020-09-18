#include <iostream>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
#pragma once
#include "Node.h"
using namespace std;

class Matrix
{

public:
    Node *head;
    //int cant_nodos = obtenerCantidadNodos();

    Matrix()
    {
        Node *tmp = new Node(0, "Raiz", "White", 0, 0);
        head = tmp;
    }
    ~Matrix();

    //add(int n, string letra, string color, int x, int y)
    void add(int n, string letra, string color, int x, int y)
    {
        //1. crear cabeceras
        //1.1 crear cabecera en x
        add_x_header(x, letra);
        //1.2 crear cabecera en y
        add_y_header(y, letra);
        //2. insertar el nodo
        Node *new_node = new Node(n, letra, color, x, y);
        add_node(n, letra, color, x, y);
    }

    void add_x_header(int x, string letra)
    {
        if (head->right == NULL)
        {
            Node *tmp = new Node(x, letra, "white", x, 0);
            head->right = tmp;
            tmp->left = head;
        }
        else
        {
            Node *tmp2 = head;

            while (tmp2->right != NULL && tmp2->right->n < x)
            {
                tmp2 = tmp2->right;
            }

            if (tmp2->right == NULL)
            {
                Node *new_tmp = new Node(x, letra, "white", x, 0);
                tmp2->right = new_tmp;
                new_tmp->left = tmp2;
            }
            else if (tmp2->right != NULL && tmp2->right->n != x)
            {
                // no se llegó al final (meter en medio)
                Node *new_tmp = new Node(x, letra, "white", x, 0);
                Node *der = tmp2->right;

                // Doble enlace
                tmp2->right = new_tmp;
                new_tmp->left = tmp2;
                new_tmp->right = der;
                der->left = new_tmp;
            }
        }
    }

    void add_y_header(int y, string letra)
    {
        if (head->down == NULL)
        {
            Node *tmp = new Node(y, letra, "white", 0, y);
            head->down = tmp;
            tmp->up = head; // primer nodo en Y
        }
        else
        {
            Node *tmp2 = head;

            while (tmp2->down != NULL && tmp2->down->n < y)
            {
                tmp2 = tmp2->down;
            }

            if (tmp2->down == NULL)
            {
                Node *new_tmp = new Node(y, letra, "white", 0, y);
                tmp2->down = new_tmp;
                new_tmp->up = tmp2;
            }
            else if (tmp2->down != NULL && tmp2->down->n != y)
            {
                Node *new_tmp = new Node(y, letra, "white", 0, y);
                Node *der = tmp2->down;
                tmp2->down = new_tmp;
                new_tmp->up = tmp2;
                new_tmp->down = der;
                der->up = new_tmp;
            }
        }
    }

    void print_x_header()
    {
        Node *tmp = head;

        while (tmp->right != NULL)
        {
            cout << tmp->n << " <-> ";
            tmp = tmp->right;
        }
        cout << tmp->n;
        cout << " \n";
    }

    void print_y_header()
    {
        Node *tmp = head->down;

        while (tmp->down != NULL)
        {
            cout << tmp->n << tmp->letra << endl;
            cout << "↓" << endl;
            tmp = tmp->down;
        }
        cout << tmp->n << tmp->letra;
        cout << " \n";
    }

    void print_headers()
    {
        print_x_header();
        cout << "↓\n";
        print_y_header();
        cout << "\n\n";
    }

    void add_node(int valor, string letra, string color, int x, int y)
    {
        Node *tmp = head;
        Node *tmp2 = head;
        Node *new_node = new Node(valor, letra, color, x, y);
        bool band = false;

        // Para columnas
        while (tmp->right != NULL)
        {
            tmp = tmp->right;

            if (tmp->x == x && tmp->down == NULL)
            {

                tmp->down = new_node;
                new_node->up = tmp;
                break;
            }
            else if (tmp->x == x && tmp->down != NULL)
            {
                Node *aux3 = tmp;
                Node *ant;

                while (aux3->down != NULL)
                {
                    ant = aux3;
                    aux3 = aux3->down;

                    if (aux3->y < y && aux3->down == NULL)
                    {
                        aux3->down = new_node;
                        new_node->up = aux3;
                        band = true;
                        break;
                    }
                    else if (aux3->y > y)
                    {
                        aux3->up = new_node;
                        new_node->down = aux3;
                        new_node->up = ant;
                        ant->down = new_node;
                        band = true;
                        break;
                    }
                }

                if (band)
                {
                    break;
                }
            }
        }

        // Para filas
        while (tmp2->down != NULL)
        {
            tmp2 = tmp2->down;

            if (tmp2->y == y && tmp2->right == NULL)
            {
                tmp2->right = new_node;
                new_node->left = tmp2;
                break;
            }
            else if (tmp2->y == y && tmp2->right != NULL)
            {
                Node *aux4 = tmp2;
                Node *ant;

                while (aux4->right != NULL)
                {
                    ant = aux4;
                    aux4 = aux4->right;

                    if (aux4->x < x && aux4->right == NULL)
                    {
                        aux4->right = new_node;
                        new_node->left = aux4;
                        band = true;
                        break;
                    }
                    else if (aux4->x > x)
                    {
                        aux4->left = new_node;
                        new_node->right = aux4;
                        new_node->left = ant;
                        ant->right = new_node;
                        band = true;
                        break;
                    }
                }

                if (band)
                {
                    break;
                }
            }
        }

        if (tmp->down == NULL) //INICIAL
        {
        }

        //cout << "Se va a ingresar en x = " << x << " y = " << y;
        cout << "\n";
    }

    void print_nodes_x()
    {
        Node *tmp = head->right;
        cout << " >> en x: " << endl;
        while (tmp->right != NULL)
        {
            cout << tmp->n;
            cout << "-> ";

            if (tmp->down != NULL)
            {
                cout << tmp->down->letra;
                cout << " " << tmp->down->color;
            }

            cout << "\n";
            tmp = tmp->right;
        }

        cout << tmp->n;
        cout << "-> ";

        if (tmp->down != NULL)
        {
            cout << tmp->down->letra;
            cout << " " << tmp->down->color;
        }

        cout << "\n";
    }

    void print_nodes_y()
    {
        Node *tmp = head->down;
        cout << " >> y: " << endl;
        while (tmp->down != NULL)
        {
            //cout << "  :::: Nodos en la fila y = " << tmp->n << endl;
            cout << tmp->n;
            cout << " -> ";

            if (tmp->right != NULL)
            {
                cout << tmp->right->letra;
                cout << " " << tmp->right->color;
                //cout << "Arriba: " << aux->up->letra << endl;
            }

            tmp = tmp->down;

            cout << "\n";
        }

        //cout << "  :::: Nodos en la fila y = " << tmp->n << endl;
        cout << tmp->n;
        cout << " -> ";

        if (tmp->right != NULL)
        {
            cout << tmp->right->letra;
            cout << "  " << tmp->right->color << endl;
        }

        cout << "\n";
    }

    Node *searchNode(int x, int y)
    {
    }

    void generarMatriz()
    {
        ofstream grafico;
        int nivel = 3;

        grafico.open("GraficoMatriz.txt", ios::out);

        if (grafico.fail())
        {
            cout << " Error al abrir el archivo " << endl;
        }

        grafico << "digraph G {\n"
                << "node[shape=circle]\n";

        // IMPRIMIENDO HEADERS
        // headers en x

        Node *header_x = head;

        while (header_x->right != NULL)
        {
            grafico << "nodo" << &*header_x << "[label= \"" << header_x->x << "\""
                    << "pos =\"" << header_x->x << "," << 0 << "!\""
                    << " color=gray style=filled];\n";

            // Generando enlaces
            if (header_x->right)
            {
                grafico << "nodo" << &*header_x << "->"
                        << "nodo" << &*header_x->right << "[dir=\"both\"];\n";
            }

            if (header_x->down)
            {
                grafico << "nodo" << &*header_x << "->"
                        << "nodo" << &*header_x->down << "[dir=\"both\"];\n";
            }

            header_x = header_x->right;
        }

        // generando el ultimo en X
        grafico << "nodo" << &*header_x << "[label= \"" << header_x->x << "\""
                << "pos =\"" << header_x->x << "," << 0 << "!\""
                << " color=gray style=filled];\n";
        // Enlace hacia abajo del ultimo en x
        grafico << "nodo" << &*header_x << "->"
                << "nodo" << &*header_x->down << "[dir=\"both\"];\n";

        // ----------------------------------------------------------

        Node *header_y = head->down;

        // IMPRIMIENDO EN Y
        while (header_y->down != NULL)
        {
            grafico << "nodo" << &*header_y << "[label= \"" << header_y->y << "\""
                    << "pos =\"" << 0 << "," << header_y->y << "!\""
                    << " color=gray style=filled];\n";

            // Generando enlaces
            if (header_y->down)
            {
                grafico << "nodo" << &*header_y << "->"
                        << "nodo" << &*header_y->down << "[dir=\"both\"];\n";
            }

            // Generando los enlaces a su derecha del header en y
            if (header_y->right)
            {
                grafico << "nodo" << &*header_y << "->"
                        << "nodo" << &*header_y->right << "[dir=\"both\"];\n";
            }

            header_y = header_y->down;
        }

        // generando el ultimo en y
        grafico << "nodo" << &*header_y << "[label= \"" << header_y->y << "\""
                << "pos =\"" << 0 << "," << header_y->y << "!\""
                << " color=gray style=filled];\n";

        // Generando el ultimo enlace en y
        grafico << "nodo" << &*header_y << "->"
                << "nodo" << &*header_y->right << "[dir=\"both\"];\n";

        // IMPRIMIENDO LOS NODOS
        Node *y_header_aux = head->down;

        while (y_header_aux != NULL)
        {
            Node *actual = y_header_aux->right;
            while (actual)
            {
                grafico << "nodo" << &*actual << "[label= \"" << actual->letra << "\""
                        << "pos =\"" << actual->x << "," << actual->y << "!\""
                        << "color=\"" << actual->color << "\" style=filled];\n";

                if (actual->down)
                {
                    grafico << "nodo" << &*actual << "->"
                            << "nodo" << &*actual->down << "[dir=\"both\"];\n";
                }

                if (actual->right)
                {
                    grafico << "nodo" << &*actual << "->"
                            << "nodo" << &*actual->right << "[dir=\"both\"];\n";
                }

                actual = actual->right;
            }

            y_header_aux = y_header_aux->down;
        }
        //grafico << "label = \"" << obtenerCantidadNodos() << " nodos \" \n;";
        grafico << "\n"
                << "}\n";

        grafico.close();

        string cmd, cmd2, cmd3;
        cmd = "fdp -Tjpg GraficoMatriz.txt -o Nivel";
        cmd2 = to_string(nivel) + ".png";
        cmd3 = cmd + cmd2;
        //cmd += nivel + ".jpg";
        int tam_cmd = cmd.length();
        char a[tam_cmd + 1];

        strcpy(a, cmd3.c_str());
        system(a);
    }

    void generarMatrizPorNivel(int nivel)
    {
        ofstream grafico;
        //int nivel = 3;

        grafico.open("GraficoMatriz.txt", ios::out);

        if (grafico.fail())
        {
            cout << " Error al abrir el archivo " << endl;
        }

        grafico << "digraph G {\n"
                << "node[shape=circle]\n";

        // IMPRIMIENDO HEADERS
        // headers en x

        Node *header_x = head;

        while (header_x->right != NULL)
        {
            grafico << "nodo" << &*header_x << "[label= \"" << header_x->x << "\""
                    << "pos =\"" << header_x->x << "," << 0 << "!\""
                    << " color=gray style=filled];\n";

            // Generando enlaces
            if (header_x->right)
            {
                grafico << "nodo" << &*header_x << "->"
                        << "nodo" << &*header_x->right << "[dir=\"both\"];\n";
            }

            if (header_x->down)
            {
                grafico << "nodo" << &*header_x << "->"
                        << "nodo" << &*header_x->down << "[dir=\"both\"];\n";
            }

            header_x = header_x->right;
        }

        // generando el ultimo en X
        grafico << "nodo" << &*header_x << "[label= \"" << header_x->x << "\""
                << "pos =\"" << header_x->x << "," << 0 << "!\""
                << " color=gray style=filled];\n";
        // Enlace hacia abajo del ultimo en x
        grafico << "nodo" << &*header_x << "->"
                << "nodo" << &*header_x->down << "[dir=\"both\"];\n";

        // ----------------------------------------------------------

        Node *header_y = head->down;

        // IMPRIMIENDO EN Y
        while (header_y->down != NULL)
        {
            grafico << "nodo" << &*header_y << "[label= \"" << header_y->y << "\""
                    << "pos =\"" << 0 << "," << header_y->y << "!\""
                    << " color=gray style=filled];\n";

            // Generando enlaces
            if (header_y->down)
            {
                grafico << "nodo" << &*header_y << "->"
                        << "nodo" << &*header_y->down << "[dir=\"both\"];\n";
            }

            // Generando los enlaces a su derecha del header en y
            if (header_y->right)
            {
                grafico << "nodo" << &*header_y << "->"
                        << "nodo" << &*header_y->right << "[dir=\"both\"];\n";
            }

            header_y = header_y->down;
        }

        // generando el ultimo en y
        grafico << "nodo" << &*header_y << "[label= \"" << header_y->y << "\""
                << "pos =\"" << 0 << "," << header_y->y << "!\""
                << " color=gray style=filled];\n";

        // Generando el ultimo enlace en y
        grafico << "nodo" << &*header_y << "->"
                << "nodo" << &*header_y->right << "[dir=\"both\"];\n";

        // IMPRIMIENDO LOS NODOS
        Node *y_header_aux = head->down;

        while (y_header_aux != NULL)
        {
            Node *actual = y_header_aux->right;
            while (actual)
            {
                grafico << "nodo" << &*actual << "[label= \"" << actual->letra << "\""
                        << "pos =\"" << actual->x << "," << actual->y << "!\""
                        << "color=\"" << actual->color << "\" style=filled];\n";

                if (actual->down)
                {
                    grafico << "nodo" << &*actual << "->"
                            << "nodo" << &*actual->down << "[dir=\"both\"];\n";
                }

                if (actual->right)
                {
                    grafico << "nodo" << &*actual << "->"
                            << "nodo" << &*actual->right << "[dir=\"both\"];\n";
                }

                actual = actual->right;
            }

            y_header_aux = y_header_aux->down;
        }
        //grafico << "label = \"" << obtenerCantidadNodos() << " nodos \" \n;";
        grafico << "\n"
                << "}\n";

        grafico.close();

        string cmd, cmd2, cmd3;
        cmd = "fdp -Tjpg GraficoMatriz.txt -o Nivel";
        cmd2 = to_string(nivel) + ".png";
        cmd3 = cmd + cmd2;
        //cmd += nivel + ".jpg";
        int tam_cmd = cmd.length();
        char a[tam_cmd + 1];

        strcpy(a, cmd3.c_str());
        system(a);
    }

    void imprimir_en_consola()
    {
        Node *x_header = head;
        // Columnas
        while (x_header != NULL)
        {
            Node *aux = x_header->down;
            cout << x_header->n << "  ";

            while (aux)
            {
                cout << aux->letra << "   ";

                aux = aux->down;
            }
            cout << "\n";

            x_header = x_header->right;
        }

        cout << "\n\n";
        // Filas
        Node *y_header = head;
        // Columnas
        while (y_header != NULL)
        {
            Node *aux = y_header->right;
            cout << y_header->n << "   ";

            while (aux)
            {
                cout << aux->letra << " -  (" << aux->x << "," << aux->y << ") " << aux->color;
                aux = aux->right;
            }
            cout << "\n";

            y_header = y_header->down;
        }
    }

    int obtenerCantidadNodos()
    {
        int cantidad_nodos = 0;
        int largo = 0;
        int alto = 0;
        int espacios_libres = 0;
        Node *y_header = head->down;
        Node *x_header = head->right;

        while (x_header != NULL)
        {

            x_header = x_header->right;
            largo++;
        }

        while (y_header != NULL)
        {
            Node *aux = y_header->right;

            while (aux)
            {

                aux = aux->right;
                cantidad_nodos++;
            }

            y_header = y_header->down;
            alto++;
        }

        //cout << "Cantidad Nodos: " << cantidad_nodos << endl;

        return cantidad_nodos;
    }

    int obtenerEspaciosLibres()
    {
        int cantidad_nodos = 0;
        int largo = 0;
        int alto = 0;
        int espacios_libres = 0;
        Node *y_header = head->down;
        Node *x_header = head->right;

        while (x_header != NULL)
        {

            x_header = x_header->right;
            largo++;
        }

        while (y_header != NULL)
        {
            Node *aux = y_header->right;

            while (aux)
            {

                aux = aux->right;
                cantidad_nodos++;
            }

            y_header = y_header->down;
            alto++;
        }

        espacios_libres = (alto * largo) - cantidad_nodos;

        return espacios_libres;
    }

    int obtenerParedes()
    {
        int cant_paredes = 0;

        Node *y_header = head->down;

        while (y_header != NULL)
        {
            Node *aux = y_header->right;

            while (aux)
            {

                if (aux->letra == "p")
                {
                    // es pared
                    cant_paredes++;
                }

                aux = aux->right;
            }

            y_header = y_header->down;
        }

        return cant_paredes;
    }

    int obtenerVentanas()
    {
        int cant_ventanas = 0;

        Node *y_header = head->down;

        while (y_header != NULL)
        {
            Node *aux = y_header->right;

            while (aux)
            {

                if (aux->letra == "v")
                {
                    // es ventana
                    cant_ventanas++;
                }

                aux = aux->right;
            }

            y_header = y_header->down;
        }

        return cant_ventanas;
    }
};

/*
Matrix::Matrix()
{
}
*/
Matrix::~Matrix()
{
}
