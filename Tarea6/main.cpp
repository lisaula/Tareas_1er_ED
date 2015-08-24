#include "widget.h"
#include "form.h"
#include <QApplication>
#include "cola.h"
#include "pila.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    Cola* cola=new Cola();


    return a.exec();
}
