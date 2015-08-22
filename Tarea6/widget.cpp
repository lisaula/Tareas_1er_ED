#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //p = new PilaGraph(parent);
    padre = parent;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Pila_clicked()
{
    p = new PilaGraph(padre);
    p->setVisible(true);
}

void Widget::on_Cola_clicked()
{
    c = new ColaGraph(padre);
    c->setVisible(true);
}
