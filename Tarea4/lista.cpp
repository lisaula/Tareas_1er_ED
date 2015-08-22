#include "lista.h"

Lista::Lista()
{
    raiz = NULL;
    final=NULL;
}
Nodo* Lista::buscar(int valor, Nodo* raiz){
    if(raiz){
        if(raiz->valor==valor){
            return raiz;
        }else{
            return buscar(valor,raiz->sig);
        }
    }
    return NULL;
}

void Lista::agregar(int valor){
    if(raiz){
        final->sig = new Nodo(valor);
        final = final->sig;
    }else{
        raiz = new Nodo(valor);
        final = raiz;
    }
}
bool Lista::insertar(int valor_pos,int numero){
    if(raiz){
        Nodo * temp = buscar(valor_pos,raiz);
        if(temp){
            Nodo *nuevo = new Nodo(numero);
            nuevo->sig = temp->sig;
            temp->sig=nuevo;
            return true;
        }else
            return false;
    }else{
        agregar(numero);
        return true;
    }
    return false;
}
void Lista::eliminar(int valor){
    if(raiz){
        if(raiz->valor==valor){
            Nodo* temp = raiz;
            raiz = temp->sig;
            delete temp;
        }else{
            Nodo* temp = raiz;
            while(temp){
                if(temp->sig!=NULL && temp->sig->valor==valor){
                    Nodo* t = temp->sig;
                    temp->sig = t->sig;
                    delete t;break;
                }else{
                    temp = temp->sig;
                }
            }
        }
    }
}
void Lista::eliminarRecursiva(int valor, Nodo *&raiz){
    if(raiz){
        if(raiz->valor==valor){
            if(raiz->valor!=final->valor){
                Nodo* temp = raiz;
                raiz = temp->sig;
                delete temp;
            }else{
                Nodo* t = this->raiz;
                this->raiz=NULL;final=NULL;
                //delete t;
            }
        }else if(raiz->sig->valor==valor) {
            Nodo* temp = raiz->sig;
            if(temp->valor!=final->valor){
                raiz->sig= temp->sig;
                delete temp;
            }else{

                raiz->sig=final->sig;
                delete temp;
                final=raiz;
            }
        }else{
            eliminarRecursiva(valor,raiz->sig);
        }
    }
}

void Lista::eliminarRecursiva(int valor){
    eliminarRecursiva(valor,raiz);
}

QString Lista::imprimir(){
    QString texto="";
    Nodo* temp = raiz;
    while(temp){
        texto += QString("%1").arg(temp->valor);
        texto +="->";
        temp = temp->sig;
    }
    texto+="NULL";
    return texto;
}
