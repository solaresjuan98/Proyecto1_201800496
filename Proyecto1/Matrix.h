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

    // buscar el nodo
    Node *nodoExiste(int x, int y)
    {
        Node *y_header = head->down;
        Node *x_header = head->right;
        Node *objeto = NULL;
        bool encontrado = false;

        while (x_header != NULL)
        {

            x_header = x_header->right;
            //largo++;
        }

        while (y_header != NULL)
        {
            Node *aux = y_header->right;

            while (aux)
            {

                if ((aux->x == x) && (aux->y == y))
                {
                    //cout << " >> Nodo encontrado en matriz " << endl;
                    encontrado = true;
                    objeto = aux;

                    if (objeto->down == NULL && objeto->right == NULL)
                    {
                        cout << " Arriba: " << objeto->up->letra << endl;
                        cout << " Izq : " << objeto->left->y << endl;
                    }
                    else if (objeto->right == NULL)
                    {
                        cout << " Arriba: " << objeto->up->letra << endl;
                        cout << " Abajo : " << objeto->down->letra << endl;
                        cout << " Izq : " << objeto->left->letra << endl;
                    }
                    else if (objeto->down == NULL)
                    {
                        cout << " Arriba: " << objeto->up->x << endl;
                        cout << " izq : " << objeto->left->letra << endl;
                        cout << " der : " << objeto->right->letra << endl;
                    }

                    else
                    {
                        cout << " Arriba: " << objeto->up->letra << endl;
                        cout << " Abajo : " << objeto->left->letra << endl;
                        cout << " Izq : " << objeto->left->letra << endl;
                        cout << " Der : " << objeto->right->letra << endl;
                    }

                    //return aux;
                    //break;
                }

                aux = aux->right;
            }

            y_header = y_header->down;
        }

        if (!encontrado)
        {
            //
        }

        return objeto;
    }

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

        if (nodoExiste(x, y))
        {
            //cout << " >> Nodo repetido. No se puede ingresar. " <<endl;
        }
        else
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
        }
    }

    void delete_object(int x, int y)
    {

        if (nodoExiste(x, y) != NULL)
        {
            Node *y_header = head->down;
            Node *x_header = head->right;
            Node *objetoBorrar = NULL;
            bool encontrado = false;

            while (x_header != NULL)
            {

                x_header = x_header->right;
                //largo++;
            }

            while (y_header != NULL)
            {
                Node *aux = y_header->right;

                while (aux)
                {

                    if ((aux->x == x) && (aux->y == y))
                    {
                        //cout << " >> Nodo encontrado en matriz " << endl;
                        encontrado = true;
                        objetoBorrar = aux;
                        Node *aux1 = objetoBorrar->up;
                        Node *aux2 = objetoBorrar->left;
                        Node *aux3 = objetoBorrar->down;
                        Node *aux4 = objetoBorrar->right;

                        // 1. No tiene nodos abajo ni a la derecha
                        if (objetoBorrar->down == NULL && objetoBorrar->right == NULL)
                        {
                            //cout << " Arriba: " << objetoBorrar->up->letra << endl;
                            //cout << " Izq : " << objetoBorrar->left->y << endl;

                            objetoBorrar->up = NULL;
                            aux1->down = NULL;
                            objetoBorrar->left = NULL;
                            aux2->right = NULL;
                            delete objetoBorrar;
                            break;
                        }
                        // 2. No tiene Nodos a la derecha
                        else if (objetoBorrar->right == NULL)
                        {
                            //cout << " Arriba: " << objetoBorrar->up->letra << endl;
                            //cout << " Abajo : " << objetoBorrar->down->letra << endl;
                            //cout << " Izq : " << objetoBorrar->left->letra << endl;

                            objetoBorrar->up = NULL;
                            objetoBorrar->down = NULL;
                            objetoBorrar->left = NULL;
                            aux2->right = NULL;
                            aux3->up = aux1;
                            aux1->down = aux3;

                            delete objetoBorrar;
                            break;
                        }
                        // 3. No tiene nodos abajo
                        else if (objetoBorrar->down == NULL)
                        {
                            //cout << " Arriba: " << objetoBorrar->up->x << endl;
                            //cout << " izq : " << objetoBorrar->left->letra << endl;
                            //cout << " der : " << objetoBorrar->right->letra << endl;

                            objetoBorrar->up = NULL;
                            aux1->down = NULL;
                            objetoBorrar->left = NULL;
                            aux2->right = aux4;
                            objetoBorrar->right = NULL;
                            aux4->left = aux2;

                            delete objetoBorrar;
                            break;
                        }
                        // 4. Tiene apuntadores hacia todos lados
                        else
                        {
                            //cout << " Arriba: " << objetoBorrar->up->letra << endl;
                            //cout << " Abajo : " << objetoBorrar->left->letra << endl;
                            //cout << " Izq : " << objetoBorrar->left->letra << endl;
                            //cout << " Der : " << objetoBorrar->right->letra << endl;

                            objetoBorrar->up = NULL;
                            aux1->down = aux3;
                            objetoBorrar->down = NULL;
                            aux3->up = aux1;
                            objetoBorrar->left = NULL;
                            aux2->right = aux4;
                            objetoBorrar->right = NULL;
                            aux4->left = aux2;

                            delete objetoBorrar;
                            break;
                        }

                        //return aux;
                        //break;
                    }

                    aux = aux->right;
                }

                y_header = y_header->down;
            }

            if (!encontrado)
            {
                //
            }
        }
        else
        {
            cout << " >> Nodo no encontrado " << endl;
        }
    }

    void move_object(int x_inicio, int y_inicio, int x_final, int y_final)
    {

        int valor;
        string letra, color;
        // Nodo que tendrá los datos del nodo
        Node *nodo_mover = nodoExiste(x_inicio, y_inicio);
        // Nodo que tendrá las coordenadas destino
        Node *nodo_destino = nodoExiste(x_final, y_final);
        // guardando en variables
        valor = nodo_mover->n;
        letra = nodo_mover->letra;
        color = nodo_mover->color;

        //1. Borrar objeto de su posicion vieja
        delete_object(x_inicio, y_inicio);

        //2. Ingresar el nuevo Nodo
        add(valor, letra, color, x_final, y_final);
    }

    void rotate_object(int x, int y, int grados)
    {

        Node *pivote = nodoExiste(x, y);

        // Si existe el nodo pivote
        if (pivote != NULL)
        {
            /*
                buscando los nodos a la derecha del pivot
                (esta a 0 grados)
            */
            Node *aux1 = nodoExiste(x + 1, y);
            Node *aux2 = nodoExiste(x + 2, y);
            /* 
                si esta de forma vertical lo que se desa rotar, utilizando el pivot
                como el nodo más arriba
                (está a 270 grados)
            */
            Node *aux3 = nodoExiste(x, y - 1);
            Node *aux4 = nodoExiste(x, y - 2);

            // Nodo que está en la "Esquina"
            Node *aux5 = nodoExiste(x + 1, y - 1);

            // Se quiere rotar dos nodos a partir del pivot
            if (aux1 != NULL && aux2 != NULL && aux3 == NULL && aux4 == NULL && aux5 == NULL)
            {
                //Rotar en funcion de los grados (mover los nodos)
                if (grados == 45)
                {
                    move_object(aux1->x, aux1->y, aux1->x, aux1->y + 1);
                    move_object(aux2->x, aux2->y, aux2->x, aux2->y + 2);
                }
                else if (grados == 90)
                {
                    move_object(aux1->x, aux1->y, x, y + 1);
                    move_object(aux2->x, aux2->y, x, y + 2);
                }
                else if (grados == 135)
                {
                    move_object(aux1->x, aux1->y, x - 1, y + 1);
                    move_object(aux2->x, aux2->y, x - 2, aux2->y + 2);
                }
                else if (grados == 180)
                {
                    move_object(aux1->x, aux1->y, x - 1, y);
                    move_object(aux2->x, aux2->y, x - 2, y);
                }
                else if (grados == 225)
                {
                    move_object(aux1->x, aux1->y, x - 1, y - 1);
                    move_object(aux2->x, aux2->y, x - 2, y - 2);
                }
                else if (grados == 270)
                {
                    move_object(aux1->x, aux1->y, x, y - 1);
                    move_object(aux2->x, aux2->y, x, y - 2);
                }
                else if (grados == 315)
                {
                    move_object(aux1->x, aux1->y, x + 1, y - 1);
                    move_object(aux2->x, aux2->y, x + 2, y - 2);
                }
                else
                {
                    cout << " >> inserta una medida correcta" << endl;
                }
            }
            // El nodo pivot solo tiene un nodo a la derecha
            else if (aux1 != NULL && aux2 == NULL && aux3 == NULL && aux4 == NULL && aux5 == NULL)
            {
                //Rotar en funcion de los grados (mover los nodos)
                if (grados == 45)
                {
                    move_object(aux1->x, aux1->y, aux1->x, aux1->y + 1);
                }
                else if (grados == 90)
                {
                    move_object(aux1->x, aux1->y, x, y + 1);
                }
                else if (grados == 135)
                {
                    move_object(aux1->x, aux1->y, x - 1, y + 1);
                }
                else if (grados == 180)
                {
                    move_object(aux1->x, aux1->y, x - 1, y);
                }
                else if (grados == 225)
                {
                    move_object(aux1->x, aux1->y, x - 1, y - 1);
                }
                else if (grados == 270)
                {
                    move_object(aux1->x, aux1->y, x, y - 1);
                }
                else if (grados == 315)
                {
                    move_object(aux1->x, aux1->y, x + 1, y - 1);
                }
                else
                {
                    cout << " >> inserta una medida correcta" << endl;
                }
            }
            // Si los objetos están posicionados verticalmente
            else if (aux3 != NULL && aux4 != NULL && aux1 == NULL && aux2 == NULL && aux5 == NULL)
            {
                //Rotar en funcion de los grados (mover los nodos)
                if (grados == 45)
                {
                    move_object(aux3->x, aux3->y, x + 1, y - 1);
                    move_object(aux4->x, aux4->y, x + 2, y - 2);
                }
                else if (grados == 90)
                {
                    move_object(aux3->x, aux3->y, x + 1, y);
                    move_object(aux4->x, aux4->y, x + 2, y);
                }
                else if (grados == 135)
                {

                    move_object(aux3->x, aux3->y, x + 1, y + 1);
                    move_object(aux4->x, aux4->y, x + 2, y + 2);
                }
                else if (grados == 180)
                {
                    move_object(aux3->x, aux3->y, x, y + 1);
                    move_object(aux4->x, aux4->y, x, y + 2);
                }
                else if (grados == 225)
                {

                    move_object(aux3->x, aux3->y, x - 1, y + 1);
                    move_object(aux4->x, aux4->y, x - 2, aux4->y + 4);
                }
                else if (grados == 270)
                {

                    move_object(aux3->x, aux3->y, x - 1, y);
                    move_object(aux4->x, aux4->y, x - 2, y);
                }
                else if (grados == 315)
                {
                    move_object(aux3->x, aux3->y, x - 1, y - 1);
                    move_object(aux4->x, aux4->y, x - 2, y - 2);
                }
                else
                {
                    cout << " >> inserta una medida correcta" << endl;
                }
            }
            // Si el nodo pivote solo tiene un nodo hacia abajo
            else if (aux3 != NULL && aux1 == NULL && aux2 == NULL && aux4 == NULL && aux5 == NULL)
            {
                //Rotar en funcion de los grados (mover los nodos)
                if (grados == 45)
                {
                    move_object(aux3->x, aux3->y, x + 1, y - 1);
                }
                else if (grados == 90)
                {
                    move_object(aux3->x, aux3->y, x + 1, y);
                }
                else if (grados == 135)
                {

                    move_object(aux3->x, aux3->y, x + 1, y + 1);
                }
                else if (grados == 180)
                {
                    move_object(aux3->x, aux3->y, x, y + 1);
                }
                else if (grados == 225)
                {

                    move_object(aux3->x, aux3->y, x - 1, y + 1);
                }
                else if (grados == 270)
                {

                    move_object(aux3->x, aux3->y, x - 1, y);
                }
                else if (grados == 315)
                {
                    move_object(aux3->x, aux3->y, x - 1, y - 1);
                }
                else
                {
                    cout << " >> inserta una medida correcta" << endl;
                }
            }
            // Rotando otro tipo de figura
            else if (aux1 != NULL && aux3 != NULL && aux2 == NULL && aux4 == NULL && aux5 == NULL)
            {
                if (grados == 180)
                {
                    move_object(aux1->x, aux1->y, x, y + 1);
                    move_object(aux3->x, aux3->y, aux3->x + 1, aux3->y + 1);
                }
                else if (grados == 270)
                {
                    move_object(aux1->x, aux1->y, x - 1, y);
                    move_object(aux3->x, aux3->y, x, y + 1);
                }
                else if (grados == 360)
                {
                    move_object(aux1->x, aux1->y, x, y - 1);
                    move_object(aux3->x, aux3->y, x - 1, y);
                }
            }
            // Rotando otro tipo de figura (el más complejo), con un nodo a la esquina
            else if (aux1 != NULL && aux3 != NULL && aux5 != NULL && aux2 == NULL && aux4 == NULL)
            {
                if (grados == 90)
                {
                    move_object(aux1->x, aux1->y, x, y + 1);
                    move_object(aux5->x, aux5->y, x + 1, y + 1);
                    move_object(aux3->x, aux3->y, x + 1, y);
                }
                else if (grados == 180)
                {
                    move_object(aux1->x, aux1->y, x - 1, y);
                    move_object(aux5->x, aux5->y, x - 1, y + 1);
                    move_object(aux3->x, aux3->y, x, y + 1);
                }
                else if (grados == 270)
                {
                    move_object(aux5->x, aux5->y, x - 1, y);
                    move_object(aux3->x, aux3->y, x - 1, y - 1);
                    move_object(aux1->x, aux1->y, x, y - 1);
                }
            }
        }
        else
        {
            cout << " >> El nodo no existe. " << endl;
        }
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
