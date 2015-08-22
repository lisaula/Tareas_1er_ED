#include "widget.h"
#include <QApplication>
#include<nodo.h>
#include <iostream>
#include "lista.h"

using namespace std;

void imprimir(Nodo* n){
    if(n){
        cout<<n->valor<<endl;
        if(n->sig){
            imprimir(n->sig);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
