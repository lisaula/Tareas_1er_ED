#ifndef PILA_H
#define PILA_H
#include "nodop.h"
#include <QString>
using namespace std;
class Pila
{
public:
    NodoP *tope;
    void push(int valor);
    NodoP* pop();
    NodoP* top();
    void limpiar();
    void anular();
    QString imprimir();
    Pila();
};

#endif // PILA_H
