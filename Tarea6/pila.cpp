#include "pila.h"

Pila::Pila()
{
    tope=NULL;
}

void Pila::push(int valor){
    if(!tope){
        tope = new NodoP(valor);
    }else{
        NodoP *temp = new NodoP(valor);
        temp->next=tope;
        tope = temp;
    }
}

NodoP* Pila::top(){
    return tope;
}

NodoP* Pila::pop(){
    if(!tope){
        return NULL;
    }else{
        NodoP* temp = tope;
        tope = tope->next;
        temp->next=NULL;
        return temp;
    }
}

void Pila::limpiar(){
    if(tope){
        pop();
        limpiar();
    }
}

void Pila::anular(){
    if (tope){
        delete pop();
        anular();
    }
}

QString Pila::imprimir(){
    if(tope){
        QString tex="";
        NodoP* temp= tope;
        while(temp){
            tex+=QString("%1 ->").arg(temp->valor);
            temp=temp->next;
        }
        tex+="NULL";
        tex+="\n";
        return tex;
    }
    return "";
}
