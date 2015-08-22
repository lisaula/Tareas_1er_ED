#ifndef WIDGET_H
#define WIDGET_H
#include "arbol.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    void insertar();
    bool io,pr,post;
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_agregar_clicked();

    void on_buscar_clicked();

    void on_eliminar_clicked();

    void on_InOrden_clicked();

    void on_PreOrden_clicked();

    void on_PostOrden_clicked();

private:
    Arbol* arbol;
    Ui::Widget *ui;
};

#endif // WIDGET_H
