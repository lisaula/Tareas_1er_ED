#ifndef ARBOL_H
#define ARBOL_H
#include"nodo.h"
#include <iostream>
#include <QString>

using namespace std;
class Arbol
{
public:


    void agregar(int valor);
    Nodo* buscar(int valor);
    void eliminar2(int valor);
    QString imprimir();
    QString printIO();
    QString printPO();
    Nodo* getTope();
    Arbol();
private:
    Nodo* buscar(int valor, Nodo* &raiz);
    QString imprimir(Nodo* &raiz,string t, QString acu);
    QString imprimirInOrden(Nodo* &raiz, QString acu);
    QString imprimirPostOrden(Nodo* &raiz,QString acu);
    void agregar(int valor, Nodo* &raiz);
    Nodo* buscarAnterior(Nodo*&,Nodo*&);
    void agregarArbol(Nodo* &a, Nodo* &e);
    void nuevaEliminar(int valor, Nodo* &raiz);
    Nodo *top;

};

#endif // ARBOL_H
