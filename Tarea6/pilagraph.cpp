#include "pilagraph.h"
#include "ui_pilagraph.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QMessageBox>

PilaGraph::PilaGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PilaGraph)
{
    ui->setupUi(this);
    stack= new Pila();
}

PilaGraph::~PilaGraph()
{
    delete ui;
}
void PilaGraph::insertar(){
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString texto = stack->imprimir();
    text->setText(texto);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
}

void PilaGraph::on_push_clicked()
{
    QString a = ui->Line->text();
    if(a.isEmpty()){
        QMessageBox::warning(this,"Error","No especifico numero");
    }else{
        stack->push(a.toInt());
        insertar();
        ui->Line->setText("");
    }
}

void PilaGraph::on_pop_clicked()
{
    NodoP* temp =stack->pop();
    if(temp){
        QString o = QString("%1").arg(temp->valor);
        ui->Line->setText(o);
        insertar();
    }else{
        ui->Line->setText("");
    }
}

void PilaGraph::on_top_clicked()
{
    NodoP* temp =stack->top();
    if(temp){
        QString o = QString("%1").arg(temp->valor);
        ui->Line->setText(o);
        insertar();
    }else{
        ui->Line->setText("");
    }

}

void PilaGraph::on_Limpiar_clicked()
{
    stack->limpiar();
    insertar();
}

void PilaGraph::on_anular_clicked()
{
    stack->anular();
    insertar();
}
