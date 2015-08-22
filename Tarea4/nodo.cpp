#include "nodo.h"

Nodo::Nodo()
{
    valor =0;
    sig=NULL;
}

Nodo::Nodo(int valor){
    this->valor = valor;
    sig=NULL;
}
