#include "nodo.h"

Nodo::Nodo(string nombre)
{
    this->nombre=nombre;
    this->numero=0;
}

void Nodo::setGrupo(int n){
    this->numero=n;
}

void Nodo::setAdyacente(Nodo* n){
    this->Adyancentes.push_back(n);
    n->Adyancentes.push_back(this);
}

int Nodo::getNumber(){
    return this->numero;
}

vector<Nodo*> Nodo::getVector(){
    return this->Adyancentes;
}

string Nodo::getNombre(){
    return this->nombre;
}

