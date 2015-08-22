#ifndef NODO_H
#define NODO_H
#include<iostream>

using namespace std;

class Nodo
{
public:
    int valor;
    Nodo *sig;
    Nodo();
    Nodo(int valor);
};

#endif // NODO_H
