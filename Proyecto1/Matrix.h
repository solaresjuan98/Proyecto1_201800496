#include <iostream>
#include <string.h>
#include <fstream>
#pragma once
#include "Node.h"
using namespace std;

class Matrix
{

public:
    Node *head;

    Matrix()
    {
        Node *tmp = new Node(0, "Raiz", "White");
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
        Node *new_node = new Node(n, letra, color);
        add_x(new_node, x);
        add_y(new_node, y);
        add_node(n, letra, color, x, y);
    }

    void add_x(Node *new_node, int x)
    {
        Node *tmp = head;

        while (tmp->n != x)
        {
            tmp = tmp->right;
        }
        if (tmp->down == NULL) //INICIAL
        {
            tmp->down = new_node;
            new_node->up = tmp;
        }
    }

    void add_y(Node *new_node, int y)
    {
        Node *tmp = head;
        while (tmp->n != y)
        {
            tmp = tmp->down;
        }

        if (tmp->right == NULL)
        {
            tmp->right = new_node;
            new_node->left = tmp;
        }
    }

    void add_x_header(int x, string letra)
    {
        if (head->right == NULL)
        {
            Node *tmp = new Node(x, letra, "white");
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
                Node *new_tmp = new Node(x, letra, "white");
                tmp2->right = new_tmp;
                new_tmp->left = tmp2;
            }
            else if (tmp2->right != NULL && tmp2->right->n != x)
            {
                // no se llegó al final (meter en medio)
                Node *new_tmp = new Node(x, letra, "white");
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
            Node *tmp = new Node(y, letra, "white");
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
                Node *new_tmp = new Node(y, letra, "white");
                tmp2->down = new_tmp;
                new_tmp->up = tmp2;
            }
            else if (tmp2->down != NULL && tmp2->down->n != y)
            {
                Node *new_tmp = new Node(y, letra, "white");
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
            cout << tmp->n << endl;
            cout << "↓" << endl;
            tmp = tmp->down;
        }
        cout << tmp->n;
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
        Node *new_node = new Node(valor, letra, color);

        while (tmp->right != NULL)
        {
            tmp = tmp->right;

            if (tmp->n == x)
            {
                tmp->down = new_node;
                new_node->up = tmp;
            }
        }

        while (tmp->down != NULL)
        {
            tmp = tmp->down;

            if (tmp->n == y)
            {
                tmp->right = new_node;
                new_node->left = tmp;
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

    void print_in_order()
    {
        Node *x_header = head;
        Node *y_header = head->down;
        Node *actual = head;
        Node *actual_2;
        Node *actual_3;
        int pos = 0;

        // Archivo que tendrá el grafico
        ofstream grafico;

        grafico.open("Grafico.txt", ios::out);

        if (grafico.fail())
        {
            cout << " Error ";
        }

        grafico << "digraph G {\n"
                << "node[shape=box]\n"
                << "{ rank = same; \n"
                << "raiz[label=\"RAIZ\"]\n";

        x_header = head;

        grafico << "raiz->"
                << "nodo" << &*x_header->right << "[dir=\"both\"]\n";

        //Recorriendo los headers en X
        while (x_header->right != NULL)
        {
            //Node *ant = x_header->left;
            x_header = x_header->right;
            grafico << "nodo" << &*x_header << "[label =\"" << x_header->n << "\" group=" << x_header->n << "];\n";
            //grafico << "nodo" << &*x_header->down << "[label =\"" << x_header->down->letra << "\" group=" << x_header->n << "];\n";
            //cout << "  >>> " << x_header->down->letra << endl;
            if (x_header->right)
            {
                grafico << "nodo" << &*x_header << " ->"
                        << "nodo" << &*x_header->right << "[dir=\"both\"]\n";
            }
        }

        //Fin del rank = same
        grafico << "}\n";

        Node *aux = head;
        Node *aux2 = x_header->down;
        Node *aux3 = aux2->right;
        x_header = head->right;

        grafico << "raiz->"
                << "nodo" << &*y_header << "[dir=\"both\"]\n";
        grafico << "{ rank = same; \n";
        grafico << "nodo1" << &*aux->down << "[label = \"" << aux->down->letra
                << "\" group=" << aux->n << "];\n";
        grafico << "nodo" << &*y_header << "[label =\"" << y_header->n << "\"];\n";
        grafico << "}\n";
        grafico << "nodo" << &*y_header << "->"
                << "nodo" << &*y_header->down << "[dir=\"both\"]\n";

        grafico << "nodo1" << &*aux->down << "->"
                << "nodo" << &*x_header << ";\n"; // ojo aqui
        cout << " Derecho de actual: " << y_header->letra << endl;
        //grafico << "nodo1" << &*aux->down << "->"
        //        << "nodo" << &*aux2->up << ";\n";

        cout << "--" << endl;

        //Recorriendo los headers en Y
        while (y_header->down != NULL)
        {
            grafico << "{ rank = same; \n";
            y_header = y_header->down;
            //x_header = x_header->right;
            aux = aux->down;
            aux2 = y_header->right;
            // Creando las cabeceras en y
            grafico << "nodo" << &*y_header << "[label = \"" << y_header->n << "\" group=0];\n";
            cout << " y_header actual: " << y_header->n << endl;
            cout << " Dirección a la derecha: " << &*y_header->right << endl;
            cout << " Valor a la derecha: " << y_header->right->letra << endl;

            grafico << "nodo1" << &*aux->down << "[label = \"" << aux->down->letra
                    << "\" group=" << aux->n << "];\n";
            grafico << "}\n";

            // hacer enlace
            grafico << "nodo1" << &*aux->down << "->"
                    << "nodo" << &*aux2->up << ";\n";
            //cout << aux2->down->letra << endl;
            
            //No tocar
            //cout << aux2->up->n << endl;
            //cout << &*aux2->up << endl;//*IMPORTANTE*

            // Enlazando los headers en y
            if (y_header->down)
            {
                grafico << "nodo" << &*y_header << "->"
                        << "nodo" << &*y_header->down << "[dir=\"both\"]\n";
            }
        }

        grafico << "\n"
                << "label = MATRIZ ;\n"
                << " \n } \n }";

        grafico.close();
    }

    void generarMatriz()
    {
        Node *actual_x = head;
        Node *actual_y = head->down;
        Node *aux1 = actual_y->right;

        while (actual_y->down != NULL)
        {
            cout << " GENERANDO " << endl;
            while (aux1->right != NULL)
            {
                cout << aux1->letra << endl;
                aux1 = aux1->right;
            }

            actual_y = actual_y->down;
        }
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
