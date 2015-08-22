#include "colagraph.h"
#include "ui_colagraph.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QMessageBox>

ColaGraph::ColaGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColaGraph)
{
    ui->setupUi(this);
    cola = new Cola();
}

ColaGraph::~ColaGraph()
{
    delete ui;
}
void ColaGraph::insertar(){
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString texto = cola->imprimir();
    text->setText(texto);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
}

void ColaGraph::on_push_clicked()
{
    QString a = ui->line->text();
    if(a.isEmpty()){
        QMessageBox::warning(this,"Error","No especifico numero");
    }else{
        cola->push(a.toInt());
        insertar();
        ui->line->setText("");
    }
}

void ColaGraph::on_pop_clicked()
{
    NodoC* temp =cola->pop();
    if(temp){
        QString o = QString("%1").arg(temp->valor);
        ui->line->setText(o);
        insertar();
    }else{
        ui->line->setText("");
    }
}

void ColaGraph::on_top_clicked()
{
    NodoC* temp =cola->first();
    if(temp){
        QString o = QString("%1").arg(temp->valor);
        ui->line->setText(o);
        insertar();
    }else{
        ui->line->setText("");
    }
}

void ColaGraph::on_limpiar_clicked()
{
    cola->limpiar();
    insertar();
}

void ColaGraph::on_anular_clicked()
{
    cola->anular();
    insertar();
}
