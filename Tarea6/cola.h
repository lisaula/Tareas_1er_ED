#ifndef COLA_H
#define COLA_H
#include"nodoc.h"
#include<QString>
using namespace std;
class Cola
{
public:
    NodoC* root, *end;
    void push(int valor);
    NodoC* pop();
    bool desplazar(int v);
    NodoC* first();
    void limpiar();
    void anular();
    QString imprimir();
    Cola();

};

#endif // COLA_H
