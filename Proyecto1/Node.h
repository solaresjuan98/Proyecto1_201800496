
#include <iostream>
#include <string.h>
#pragma once
using namespace std;

class Node
{
public:
    int n;
    string data;
    Node *right;
    Node *left;
    Node *down;
    Node *up;

    Node(int n,string data){
        this->n = n;
        this->data = data;
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
