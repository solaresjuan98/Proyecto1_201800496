#include <iostream>
#include <string.h>
#include "NodoAVL.h"
#pragma once
using namespace std;

class ArbolAVL
{
private:
    NodoAVL *raiz;
    NodoAVL* insertar(NodoAVL *raiz, int dato, bool &hc); //hc valor de escape
    NodoAVL* rotacionII();
    //min 31.50
public:
    ArbolAVL();
    ~ArbolAVL();
    NodoAVL *getRaiz();
};

ArbolAVL::ArbolAVL()
{
}

ArbolAVL::~ArbolAVL()
{
}
