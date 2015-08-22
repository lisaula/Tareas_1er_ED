#include "widget.h"
#include <QApplication>
#include<iostream>
using namespace std;

void print(Nodo* arr[]){
    for(int x =0;x<10;x++){
        cout<<x<<" "<<arr[x]->valor<<"|"<<arr[x]->sig<<endl;
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
