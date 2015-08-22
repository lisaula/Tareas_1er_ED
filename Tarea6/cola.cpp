#include "cola.h"

Cola::Cola()
{
    root = NULL;
    end = NULL;
}

void Cola::push(int valor){
    if(!root){
        root = new NodoC(valor);
        end = root;
    }else{
        end->next= new NodoC(valor);
        end->next->prev=end;
        end= end->next;
    }
}

bool Cola::desplazar(int v){
    if(v==100){
        NodoC* s = new NodoC(v);
        s->next=root;
        root->prev=s;
        root=s;
        return true;
    }
    return false;
}

NodoC* Cola::pop(){
    if(!root)
        return NULL;

    NodoC* temp= root;
    root = root->next;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

NodoC* Cola::first(){
    return root;
}

void Cola::limpiar(){
    if(root){
        pop();
        limpiar();
    }
}


void Cola::anular(){
    if(root){
        delete pop();
        anular();
    }
}

QString Cola::imprimir(){
    QString t="";
    if(root){
        NodoC* temp = root;
        while(temp){
            t+=QString("%1->").arg(temp->valor);
            temp = temp->next;
        }
        t+="NULL";
        t+="\n";
        return t;
    }
    return t;
}

