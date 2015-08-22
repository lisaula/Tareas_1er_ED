#ifndef WIDGET_H
#define WIDGET_H
#include "pilagraph.h"
#include"colagraph.h"
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

private slots:
    void on_Pila_clicked();

    void on_Cola_clicked();

private:
    QWidget *padre;
    PilaGraph* p;
    ColaGraph* c;
    Ui::Widget *ui;
};

#endif // WIDGET_H
