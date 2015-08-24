#include "widget.h"
#include "ui_widget.h"
#include <qgraphicsscene.h>
#include "QGraphicsSimpleTextItem"
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    l = new Lista();
    ui->extra->setVisible(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::insertarObjeto(){
    ui->Add->setText("");
    ui->Pos->setText("");
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString texto = l->imprimir();
    text->setText(texto);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);

}

void Widget::on_Agregar_clicked()
{
    int x = ui->Add->text().toInt();
    l->agregar(x);
    insertarObjeto();
    ui->extra->setVisible(false);
}

void Widget::on_Insertar_clicked()
{
    int x = ui->Add->text().toInt();
    QString p = ui->Pos->text();
    if(p.isEmpty()){
        QMessageBox::warning(this,"Error","No ha especificado posicion");
    }
    else{
        int y = p.toInt();
        l->insertar(y,x);
        insertarObjeto();
    }
    ui->extra->setVisible(false);
}

void Widget::on_Eliminar_clicked()
{
    int x = ui->Add->text().toInt();
    //l->eliminar(x);
    l->eliminarRecursiva(x);
    insertarObjeto();
    ui->extra->setVisible(true);
}

void Widget::on_Buscar_clicked()
{
    QString t= ui->Add->text();
    if(l->buscar(t.toInt(),l->raiz)!=NULL){
        QMessageBox::information(this,"Buscar","Si encontro al elemento");
    }else{
         QMessageBox::information(this,"Buscar","No encontro al elemento");
    }
    ui->Add->setText("");
}
