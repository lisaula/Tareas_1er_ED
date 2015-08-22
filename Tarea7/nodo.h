#ifndef NODO_H
#define NODO_H
#include<iostream>

class Nodo
{
public:
    int valor;
    Nodo* izq, *der;
    Nodo(int valor);
};

#endif // NODO_H
