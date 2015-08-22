#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsSimpleTextItem>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    cursor = new Arreglo();
    ui->setupUi(this);
    insertarObjeto();
    lista_actual="";
    //insertar();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::insertarObjeto(){
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setParent(ui->graphicsView);
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem(), *te= new QGraphicsSimpleTextItem();
    QString texto = cursor->printArr();
    text->setText(texto);
    QString l="";
    if(listas.size()!=0){
        string name ="";

        for(int x =0; x<listas.size();x++){
            name = listas[x].toStdString();
            QString q = name.c_str();
            q+="->";
            l+=q;
            l+=QString("%1").arg(cursor->imprimirLista(name));
            l+="\n";
        }
    }
    te->setText(l);
    te->setPos(80,0);
    scene->addItem(text);
    scene->addItem(te);
    ui->graphicsView->setScene(scene);
}

void Widget::on_Alista_clicked()
{
    QString c = ui->Lista->text();
    string ca = c.toStdString();
    lista_actual=ca;
    cursor->addList(ca);
    listas.push_back(c);
    insertarObjeto();
}

void Widget::on_Agregar_clicked()
{
    QString c = ui->add->text();
    if(c.isEmpty()){
        QMessageBox::warning(this,"Error", "No especifico numero");
    }else{
        string v= c.toStdString();
        char valor = v[0];

        if(lista_actual==""){
            QMessageBox::warning(this,"Error","No ha especificado la lista");
        }else if(cursor->disponible->inicio==-1){
            QMessageBox::warning(this,"Error","LISTA LLENA");
        }else{
            cursor->agregar(valor,lista_actual);
            insertarObjeto();
            ui->add->setText("");
        }
    }
}

void Widget::on_Lista_textEdited(const QString &arg1)
{
    lista_actual=ui->Lista->text().toStdString();
}

void Widget::on_Insertar_clicked()
{
    string valor = ui->add->text().toStdString();
    QString p =ui->pos->text();
    if(valor==""){
        QMessageBox::warning(this,"Error","No especifico el valor a insertar");
    }else if(p.isEmpty()){
        QMessageBox::warning(this,"Error","No especifico la posicion");
    }else if(lista_actual==""){
        QMessageBox::warning(this,"Error","No ha especificado la lista");
    }else if(cursor->disponible->inicio==-1){
        QMessageBox::warning(this,"Error","LISTA LLENA");
    }else{
        int pos = p.toInt();
        char v=valor[0];
        cursor->insertar(lista_actual,pos,v);
        insertarObjeto();
    }
}

void Widget::on_Eliminar_clicked()
{
    QString valor = ui->add->text();
    if(valor.isEmpty()){
         QMessageBox::warning(this,"Error","No especifico el valor a eliminar");
    }else if(lista_actual==""){
        QMessageBox::warning(this,"Error","No ha especificado la lista");
    }else{
        string v = valor.toStdString();
        Lista * l = cursor->seekList(lista_actual);
        if(l->inicio!=-1){
            cursor->eliminar(lista_actual,v[0]);
            insertarObjeto();
        }
    }
}

void Widget::on_pushButton_clicked()
{
    ui->add->setText("");
    ui->pos->setText("");
    ui->Lista->setText("");
}
