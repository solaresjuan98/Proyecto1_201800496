
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class Node
{
public:
    //Datos del objeto
    int n;
    //string data;
    string letra;
    string color;

    //-----------------
    Node *right;
    Node *left;
    Node *down;
    Node *up;

    Node(int n, string letra, string color)
    {
        this->n = n;
        this->letra = letra;
        this->color = color;
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

Node::~Node()
{
}*/
