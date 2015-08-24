#ifndef WIDGET_H
#define WIDGET_H
#include "arreglo.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void insertarObjeto();
private slots:
   // void on_textEdit_textChanged();

    void on_Agregar_clicked();

    void on_Insertar_clicked();

    void on_Eliminar_clicked();

    void on_Buscar_clicked();

private:
    Ui::Widget *ui;
    Arreglo *arr;
};

#endif // WIDGET_H
