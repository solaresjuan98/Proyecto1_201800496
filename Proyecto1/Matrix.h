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
            Node *ant = x_header->left;
            x_header = x_header->right;
            grafico << "nodo" << &*x_header << "[label =\"" << x_header->n << "\" group=" << x_header->n << "];\n";
            cout << x_header->n << endl;
            cout << x_header->down->letra << endl;
            cout << "\n";
            if (x_header->right)
            {
                grafico << "nodo" << &*x_header << " ->"
                        << "nodo" << &*x_header->right << "[dir=\"both\"]\n";
            }

        }

        grafico << "}\n";

        // Enlazando las cabeceras en y con el nodo raiz
        grafico << "nodo" << &*y_header << "[label =\"" << y_header->n << "\"];\n";
        grafico << "raiz->"
                << "nodo" << &*y_header << "[dir=\"both\"]\n";

        grafico << "nodo" << &*y_header << "->"
                << "nodo" << &*y_header->down << "[dir=\"both\"]\n";

        cout << "--" << endl;
        cout << y_header->n << endl;
        cout << y_header->right->letra << endl;
        
        //Recorriendo los headers en Y
        while (y_header->down != NULL)
        {
            //Node *aux;
            y_header = y_header->down;
            grafico << "nodo" << &*y_header << "[label = \"" << y_header->n << "\"];\n";
            cout << y_header->n << endl;
            cout << y_header->right->letra << endl;
            //cout << "-----\n";
            //cout << y_header->right->up->letra << endl;
            cout << "\n";
            if (y_header->down)
            {
                grafico << "nodo" << &*y_header << " ->"
                        << "nodo" << &*y_header->down << "[dir=\"both\"]\n";
            }
        }


        //grafico << &*x_header << "[label =\"" << x_header->n << "\"]\n";

        /*
        //Recorriendo por la derecha
        while (actual->right != NULL)
        {
            grafico << "Node" << &*actual << "[label = \"" << actual->letra << "\", color = \"" << actual->color << "\"]; "
                    << " \n";
            if (actual->right)
            {
                grafico << "Node" << &*actual << "->";
                grafico << "Node" << &*actual->right << "[dir = both] "
                        << ";";
            }

            actual = actual->right;
            grafico << " Node" << &*actual << "[ label = \"" << actual->letra << "\", color = \"" << actual->color << "\"]; "
                    << " \n";
        }

        grafico << "}";
        
        actual = head;

        // Recorriendo por debajo
        while (actual->down != NULL)
        {
            //cout << "Nodo: " << *&actual << actual->letra << endl;
            grafico << "Node" << &*actual << "[label = \"" << actual->letra << "\", color = \"" << actual->color << "\"]; "
                    << " \n";

            if (actual->down)
            {
                grafico << "Node" << &*actual << "->";
                grafico << "Node" << &*actual->down << "[dir = both] "
                        << ";";
                //cout << "Nodo: " << *&actual << " ->";
                //cout << "Nodo: " << *&actual->down << endl;
            }

            actual = actual->down;
            grafico << " Node" << &*actual << "[ label = \"" << actual->letra << "\", color = \"" << actual->color << "\"]; "
                    << "\n";
        }

        actual = head;

        while (actual->down != NULL)
        {
            if (actual->right != NULL && actual != head)
            {
                actual_3 = actual;

                grafico << "{rank = same;";
                grafico << "Node" << *&actual_3 << "[ label = \"" << actual->letra << "\", color = \"" << actual->color << "\"]; "
                        << "\n";

                while (actual_3->right != NULL)
                {
                    grafico << "Node" << actual_3->n << "[ label = \"" << actual->letra << "\", color = \"" << actual->color << "\"]; "
                            << "\n";

                    if (actual_3->right)
                    {
                        grafico << "Node" << &*actual_3 << "->";
                        grafico << "Node" << &*actual_3->right << "[dir = both]"
                                << ";";
                    }

                    actual_3 = actual_3->right;
                }

                grafico << "}";
                grafico << "Node" << &*actual_3 << "[ label = \"" << actual_3->letra << "\"];"
                        << "\n";
            }

            actual = actual->down;
        }

        actual = head;
        
        while (actual->right != NULL)
        {
            if (actual->down != NULL && actual != head)
            {
                actual_2 = actual;
                grafico << "Node" << *&actual_2 << "[ label = \"" << actual->letra << "\", color = \"" << actual->color << "\"]; "
                        << "\n";

                while (actual_2->down != NULL)
                {
                    if (actual->down)
                    {
                        grafico << "Node" << &*actual_2 << "->";
                        grafico << "Node" << &*actual_2->down << "[dir = both]"
                                << ";";
                    }

                    actual_2 = actual_2->down;
                }

                grafico << "Node" << &*actual_2 << "[ label = \"" << actual_2->letra << "\"];"
                        << "\n";
            }

            actual = actual->right;
        }
        */

        grafico << "\n"
                << "label = MATRIZ ;\n"
                << " \n } \n }";

        grafico.close();

        /*
        while (actual->right != NULL && actual->down != NULL)
        {
            //Imprimir hacia la derecha
            cout << actual->right->letra << " <-> ";
            if (actual->right == NULL)
            {
                actual = actual->down;
            }
            actual = actual->right;
        }*/
    }

    void generarMatriz()
    {
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
