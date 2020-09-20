
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class Node
{
public:
    //Datos del objeto
    int n;
    int x;
    int y;
    string letra;
    string color;

    //-----------------
    Node *right;
    Node *left;
    Node *down;
    Node *up;

    Node(int n, string letra, string color, int x, int y)
    {
        this->n = n;
        this->letra = letra;
        this->color = color;
        this->x = x;
        this->y = y;
        right = NULL;
        left = NULL;
        up = NULL;
        down = NULL;
    }

    ~Node();
};

/*
Node::Node()
{
}
*/
Node::~Node()
{
}
