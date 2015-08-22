#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include <QString>

class Lista
{
public:
    Nodo *raiz, *final;
    Nodo* buscar(int valor, Nodo* raiz);
    QString imprimir();
    void agregar(int valor);
    void eliminar(int valor);
    void eliminarRecursiva(int valor, Nodo* &);
    void eliminarRecursiva(int valor);
    bool insertar(int valor_pos, int numero);
    Lista();
};

#endif // LISTA_H
