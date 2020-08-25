#include <iostream>
#include <string.h>
#pragma once
#include "Node.h"
using namespace std;

class Matrix
{

public:
    Node *head;

    Matrix()
    {
        Node *tmp = new Node(0, "Raiz");
        head = tmp;
    }
    ~Matrix();

    void add(int n, string data, int x, int y)
    {
        //1. crear cabeceras
        //1.1 crear cabecera en x
        add_x_header(x, data);
        //1.2 crear cabecera en y
        add_y_header(y, data);
        //2. insertar el nodo
        Node *new_node = new Node(n, data);
        add_x(new_node, x);
        add_y(new_node, y);
        add_node(n, data, x, y);
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

    void add_x_header(int x, string data)
    {
        if (head->right == NULL)
        {
            Node *tmp = new Node(x, data);
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
                Node *new_tmp = new Node(x, data);
                tmp2->right = new_tmp;
                new_tmp->left = tmp2;
            }
            else if (tmp2->right != NULL && tmp2->right->n != x)
            {
                // no se llegó al final (meter en medio)
                Node *new_tmp = new Node(x, data);
                Node *der = tmp2->right;

                // Doble enlace
                tmp2->right = new_tmp;
                new_tmp->left = tmp2;
                new_tmp->right = der;
                der->left = new_tmp;
            }
        }
    }

    void add_y_header(int y, string data)
    {
        if (head->down == NULL)
        {
            Node *tmp = new Node(y, data);
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
                Node *new_tmp = new Node(y, data);
                tmp2->down = new_tmp;
                new_tmp->up = tmp2;
            }
            else if (tmp2->down != NULL && tmp2->down->n != y)
            {
                Node *new_tmp = new Node(y, data);
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

    void add_node(int valor, string data, int x, int y)
    {
        Node *tmp = head;

        while (tmp->n != x)
        {
            tmp = tmp->right;
        }
        if (tmp->down == NULL) //INICIAL
        {
        }

        cout << "Se va a ingresar en x = " << x << " y = " << y;
        cout << "\n";
    }

    void print_nodes_x()
    {
        Node *tmp = head->right;

        while (tmp->right != NULL)
        {
            cout << tmp->n;
            cout << "-> ";

            if (tmp->down != NULL)
            {
                cout << tmp->down->data;
            }

            cout << "\n";
            tmp = tmp->right;
        }

        cout << tmp->n;
        cout << "-> ";

        if (tmp->down != NULL)
        {
            cout << tmp->down->data;
        }

        cout << "\n";
    }

    void print_nodes_y()
    {
        Node *tmp = head->down;
        
        
        while (tmp->down != NULL)
        {
            cout << "  :::: Nodos en la fila y = " << tmp->n << endl;
            cout << tmp->n;
            cout << " -> ";

            if (tmp->right != NULL)
            {
                cout << tmp->right->data << endl;
                //cout << "Arriba: " << aux->up->data << endl;
            }

            tmp = tmp->down;
            
            cout << "\n";
        }

        cout << "  :::: Nodos en la fila y = " << tmp->n << endl;
        cout << tmp->n;
        cout << " -> ";

        if (tmp->right != NULL)
        {
            cout << tmp->right->data << endl;
            //cout << "Arriba: " << aux->up->data << endl;
        }

        cout << "\n";
    }

    void print_in_order()
    {
        Node *actual = head->down;

        while (actual->right != NULL)
        {
            cout << actual->right->data;
        }
    }
};

/*
Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}
*/