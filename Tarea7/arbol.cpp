#include "arbol.h"

Arbol::Arbol()
{
    top=NULL;
}

void Arbol::agregar(int valor, Nodo* &raiz){
    if(raiz==NULL){
        raiz = new Nodo(valor);
        cout<<"Agrego"<<endl;
    }else{
        if(valor < raiz->valor){
            agregar(valor,raiz->izq);
        }else{
            agregar(valor,raiz->der);
        }
    }
}

Nodo* Arbol::getTope(){
    return top;
}

void Arbol::agregar(int valor){
    agregar(valor,top);
}

Nodo* Arbol::buscar(int valor){
    return buscar(valor,top);
}

Nodo* Arbol::buscar(int valor, Nodo* &raiz){
    if(raiz){
        if(raiz->valor==valor){
            return raiz;
        }else{
            if(valor<raiz->valor){
                return buscar(valor,raiz->izq);
            }
            else{
                return buscar(valor,raiz->der);
            }
        }
    }
    return NULL;
}
void Arbol::eliminar2(int valor){
    nuevaEliminar(valor,top);
}

void Arbol::nuevaEliminar(int valor, Nodo* &raiz){
    if(!raiz)return;
    if(raiz->valor==valor){
        if(raiz->izq==NULL && raiz->der==NULL){
            Nodo * t = raiz;
            raiz = NULL;
            delete raiz;
        }else if(raiz->izq && raiz->der==NULL){
                Nodo *a = buscarAnterior(top,raiz);
                if(a->izq->valor==raiz->valor){
                    Nodo* temp = raiz;
                    a->izq=raiz->izq;
                    delete temp;
                }else{
                    Nodo* temp = raiz;
                    a->der=raiz->izq;
                    delete temp;
                }
        }else if(raiz->der && raiz->izq==NULL){
            Nodo *a = buscarAnterior(top,raiz);
            if(a->izq->valor==raiz->valor){
                Nodo* temp = raiz;
                a->izq=raiz->der;
                delete temp;
            }else{
                Nodo* temp = raiz;
                a->der=raiz->der;
                delete temp;
            }
        }else{
            Nodo* temp=raiz;
            raiz=temp->izq;
            agregarArbol(temp->der,raiz->der);
            delete temp;
        }
    }else{
        nuevaEliminar(valor,raiz->izq);
        nuevaEliminar(valor,raiz->der);
    }
}

Nodo* Arbol::buscarAnterior(Nodo* &raiz, Nodo* &b){
    if(!raiz){
        return NULL;
    }
    if(b->valor<raiz->valor){
        if(raiz->izq->valor==b->valor){
            return raiz;
        }else{
            return buscarAnterior(raiz->izq,b);
        }
    }else{
        if(raiz->der->valor==b->valor){
            return raiz;
        }else{
            return buscarAnterior(raiz->der,b);
        }
    }

}

void Arbol::agregarArbol(Nodo *&a, Nodo* &e){
    if(!e){
        e=a;
    }else{
        if(a->valor<e->valor){
            agregarArbol(a,e->izq);
        }else{
            agregarArbol(a,e->der);
        }
    }
}

QString Arbol::imprimir(Nodo* &raiz, string t, QString acu){
    if(raiz==NULL){
        return "";
    }
    acu=QString("%2->").arg(raiz->valor);
    //cout<<t<<"->"<<raiz->valor<<"->";
    acu+=imprimir(raiz->izq,"","");
    acu+=imprimir(raiz->der,"","");

    return acu;
}
QString Arbol::imprimir(){
    return imprimir(top,"","");
}

QString Arbol::imprimirInOrden(Nodo *&raiz,QString acu){
    if(!raiz)
        return "";
    else{

        acu +=imprimirInOrden(raiz->izq,"");
        acu +=QString("%1->").arg(raiz->valor);
        acu += imprimirInOrden(raiz->der,"");
        return acu;
    }
}

QString Arbol::printIO(){
    return imprimirInOrden(top,"");
}

QString Arbol::imprimirPostOrden(Nodo *&raiz, QString acu){
    if(!raiz)
        return "";
    else{
        acu+=imprimirPostOrden(raiz->izq,"");
        acu+=imprimirPostOrden(raiz->der,"");
        acu +=QString("%1->").arg(raiz->valor);
        return acu;
    }
}

QString Arbol::printPO(){
    return imprimirPostOrden(top,"");
}


