#ifndef PILAGRAPH_H
#define PILAGRAPH_H
#include"pila.h"
#include <QWidget>
#include<QString>

namespace Ui {
class PilaGraph;
}

class PilaGraph : public QWidget
{
    Q_OBJECT

public:
    void insertar();
    explicit PilaGraph(QWidget *parent = 0);
    ~PilaGraph();

private slots:
    void on_push_clicked();

    void on_pop_clicked();

    void on_top_clicked();

    void on_Limpiar_clicked();

    void on_anular_clicked();

private:
    Pila* stack;
    Ui::PilaGraph *ui;

};

#endif // PILAGRAPH_H
