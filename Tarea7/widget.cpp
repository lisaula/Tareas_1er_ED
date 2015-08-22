#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    arbol = new Arbol();
    io=false;
    pr=true;
    post=false;
    insertar();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::insertar(){
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();

    QString texto = "";
    if(pr){
        texto = arbol->imprimir();
    }else if(io){
        texto = arbol->printIO();
    }else{
        texto = arbol->printPO();
    }
    text->setText(texto);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
}

void Widget::on_agregar_clicked()
{
    QString a = ui->line->text();
    if(a.isEmpty()){
        QMessageBox::warning(this,"Error","No especifico numero a insertar");
    }else{
        int x = a.toInt();
        arbol->agregar(x);
        insertar();
        ui->line->setText("");
    }
}

void Widget::on_buscar_clicked()
{
    QString a = ui->line->text();
    if(a.isEmpty()){
        QMessageBox::warning(this,"Error","No especifico numero a insertar");
    }else{
        Nodo* t = arbol->buscar(a.toInt());
        if(t){
            QMessageBox::information(this,"Existe","Se encontro "+a);
        }else{
            QMessageBox::information(this,"No Existe","No Se encontro "+a);
        }
    }

}

void Widget::on_eliminar_clicked()
{
    QString a = ui->line->text();
    if(a.isEmpty()){
        QMessageBox::warning(this,"Error","No especifico numero a insertar");
    }else{
        arbol->eliminar2(a.toInt());
        insertar();
    }
}

void Widget::on_InOrden_clicked()
{
    io=true;
    pr=false;
    post=false;
    insertar();
}

void Widget::on_PreOrden_clicked()
{
    io=false;
    pr=true;
    post=false;
    insertar();
}

void Widget::on_PostOrden_clicked()
{
    io=false;
    pr=false;
    post=true;
    insertar();
}
