#ifndef WIDGET_H
#define WIDGET_H
#include"arreglo.h"
#include<vector>
#include <QString>
#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Arreglo* cursor;
    vector<QString>listas;
    string lista_actual;
    void insertarObjeto();
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Alista_clicked();

    void on_Agregar_clicked();

    void on_Lista_textEdited(const QString &arg1);

    void on_Insertar_clicked();

    void on_Eliminar_clicked();

    void on_pushButton_clicked();

    void on_Buscar_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
