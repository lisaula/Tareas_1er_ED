#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QMessageBox>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    arr= new Arreglo();
    insertarObjeto();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::insertarObjeto(){
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString texto = arr->imprimir();
    text->setText(texto);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);

}

//void Widget::on_textEdit_textChanged()
//{

//}

void Widget::on_Agregar_clicked()
{
    QString t = ui->Agregar_2->text();
    int n = t.toInt();
    arr->add(n);
    insertarObjeto();
    ui->Agregar_2->setText("");
}

void Widget::on_Insertar_clicked()
{
    QString t = ui->Agregar_2->text();
    QString p = ui->Posicion->text();
    if(p.isEmpty()){
        QMessageBox::warning(this,"Error","No incluyo posicion");
    }else{
        int n = t.toInt();
        int po = p.toInt();
        arr->insertar(po,n);
        insertarObjeto();
    }
    ui->Agregar_2->setText("");
    ui->Posicion->setText("");
}

void Widget::on_Eliminar_clicked()
{
     QString t = ui->Agregar_2->text();
     int n = t.toInt();
     arr->eliminar(n);
     insertarObjeto();
     ui->Agregar_2->setText("");

}
