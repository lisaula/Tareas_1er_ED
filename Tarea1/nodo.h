#ifndef NODO_H
#define NODO_H
#include <vector>
#include<iostream>

using namespace std;

class Nodo
{
public:
    int numero;
    string nombre;
    vector<Nodo*>Adyancentes;
    void setGrupo(int n);
    void setAdyacente(Nodo* n);
    int getNumber();
    string getNombre();
    vector<Nodo*> getVector();
    Nodo(string nombre);
};

#endif // NODO_H
