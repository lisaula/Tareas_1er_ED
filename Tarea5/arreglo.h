#ifndef ARREGLO_H
#define ARREGLO_H
#include "nodo.h"
#include "lista.h"
#include <vector>
#include<QString>

class Arreglo
{
public:
    Nodo* arr[10]= {0,0,0,0,0,0,0,0,0,0};
    vector<Lista*>ls;
    Lista* disponible;
    void agregar(char valor, string name);
    void eliminar(string name,char valor);
    void insertar(string name,int pos, char valor);
    int contarNodos(int l);
    int buscarUltimo(Lista* l);
    int buscarAnterior(int l,char valor);
    int buscar(int l,char valor);
    int getPosicion(Lista*l, int p);
    void addList(string name);
    Lista* seekList(string name);
    QString imprimirLista(string name);
    QString printArr();
    Arreglo();

};

#endif // ARREGLO_H
