#include "nodo.h"

Nodo::Nodo(int sig)
{
    this->sig = sig;
    valor = '-';
}
Nodo::Nodo(char valor){
    this->valor=valor;
    sig=-1;
}

