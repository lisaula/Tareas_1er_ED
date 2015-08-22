#ifndef WIDGET_H
#define WIDGET_H
#include "lista.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Lista *l;
    void insertarObjeto();
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Agregar_clicked();

    void on_Insertar_clicked();

    void on_Eliminar_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
