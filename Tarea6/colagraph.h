#ifndef COLAGRAPH_H
#define COLAGRAPH_H

#include <QWidget>
#include"cola.h"
#include <QWidget>
#include<QString>

namespace Ui {
class ColaGraph;
}

class ColaGraph : public QWidget
{
    Q_OBJECT

public:
    void insertar();
    explicit ColaGraph(QWidget *parent = 0);
    ~ColaGraph();

private slots:
    void on_push_clicked();

    void on_pop_clicked();

    void on_top_clicked();

    void on_limpiar_clicked();

    void on_anular_clicked();

private:
    Cola* cola;
    Ui::ColaGraph *ui;
};

#endif // COLAGRAPH_H
