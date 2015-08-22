#ifndef ARREGLO_H
#define ARREGLO_H
#include <iostream>
#include<QString>
using namespace std;

class Arreglo
{
public:
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    int cont;
    void add(int num);
    void desplazar(int pos, bool ID);
    void insertar(int pos, int num);
    void eliminar(int num);
    int buscar(int num);
    void print();
    QString imprimir();
    Arreglo();
};

#endif // ARREGLO_H
