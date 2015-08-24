#include "arreglo.h"

Arreglo::Arreglo()
{
    disponible= new Lista("Disponible");
    disponible->inicio=0;
    ls.push_back(disponible);
    arr[0]= new Nodo(1);
    arr[1]= new Nodo(2);
    arr[2]= new Nodo(3);
    arr[3]= new Nodo(4);
    arr[4]= new Nodo(5);
    arr[5]= new Nodo(6);
    arr[6]= new Nodo(7);
    arr[7]= new Nodo(8);
    arr[8]= new Nodo(9);
    arr[9]= new Nodo(-1);

}

int Arreglo::buscarUltimo(Lista* l){
    int x = l->inicio;
    int ultimo=0;
    Nodo* temp=NULL;
    while(x>=0){
        temp= arr[x];
        ultimo=x;
        x=temp->sig;
    }
    return ultimo;
}


void Arreglo::agregar(char valor, string name){
    Lista *lista =seekList(name);
    if(lista->inicio==-1){
        int nextfree = disponible->inicio;
        disponible->inicio=arr[disponible->inicio]->sig;
        arr[nextfree]->valor=valor;
        arr[nextfree]->sig=-1;
        lista->inicio=nextfree;
    }else{
        int nextfree = disponible->inicio;
        int ultimo = buscarUltimo(lista);
        disponible->inicio=arr[disponible->inicio]->sig;
        arr[ultimo]->sig=nextfree;
        arr[nextfree]->valor=valor;
        arr[nextfree]->sig=-1;
    }
}
void Arreglo::insertar(string name,int pos, char valor){
    Lista *l = seekList(name);
    if(pos>contarNodos(l->inicio)){
        agregar(valor,l->name);
    }else{
        int rpos= getPosicion(l,pos);
        int pos_a = buscarAnterior(l->inicio,arr[rpos]->valor);
        int nextfree= disponible->inicio;
        disponible->inicio=arr[disponible->inicio]->sig;
        arr[nextfree]->valor=valor;
        arr[nextfree]->sig=rpos;
        if(l->inicio==rpos){
            l->inicio=nextfree;
        }else{
            arr[pos_a]->sig=nextfree;
        }
    }
}

int Arreglo::getPosicion(Lista*l,int p){
    int i=l->inicio;
    int cont=1;
    if(cont == p){
        return l->inicio;
    }else{
        Nodo* r = arr[i];
        int x = r->sig;
        while(x!=-1){
            cont++;
            if(cont==p){
                break;
            }else{
                r = arr[r->sig];
                x=r->sig;
            }
        }
        return x;
    }
    return -1;
}

int Arreglo::buscar(int l, char valor){
    Nodo *r = arr[l];
    if(r->valor==valor){
        return l;
    }else{
        return buscar(r->sig,valor);
    }
    return -1;
}
int Arreglo::buscarAnterior(int l,char valor){
    int temp = arr[l]->sig;
    if(arr[l]->valor==valor){
        return -1;
    }else{
        int anterior = l;
        while(arr[temp]->valor!=valor){
            anterior = temp;
            temp=arr[temp]->sig;
        }
        return anterior;
    }
}

void Arreglo::eliminar(string name, char valor){
    Lista *l = seekList(name);
    int pos = buscar(l->inicio,valor);
    int pos_ant=buscarAnterior(l->inicio,valor);
    if(pos_ant!=-1){
        int sig = arr[pos]->sig;
        arr[pos]->valor='-';
        arr[pos_ant]->sig=sig;
        int temp = disponible->inicio;
        arr[pos]->sig=temp;
        disponible->inicio=pos;
    }else{
        int sig = arr[pos]->sig;
        arr[pos]->valor='-';
        l->inicio=sig;
        int temp = disponible->inicio;
        arr[pos]->sig=temp;
        disponible->inicio=pos;
    }
}

void Arreglo::addList(string name){
    ls.push_back(new Lista(name));
}

bool Arreglo::buscar(char c)
{
    Nodo *temp = arr[0];
    int cont=0;
    while(cont<10){
        if(temp->valor==c){
            return true;
        }
        cont++;
        temp=arr[cont];
    }
    return false;
}

Lista* Arreglo::seekList(string name){
    int size=ls.size();
    int x=0;
    Lista* temp=NULL;
    while(x<size){
        temp=ls[x];
        if(temp->name==name){
            return temp;
        }
        x++;
    }
    return NULL;
}

QString Arreglo::imprimirLista(string name){
    Lista* l = seekList(name);
    QString c="";
    if(l){
        if(l->inicio!=-1){
            int x = l->inicio;
            while(x>=0){
                c+=QString("%1").arg(arr[x]->valor);
                c+="->";
                x=arr[x]->sig;
            }
            c+="NULL";
        }else{
            c+="NULL";
        }
    }else{
        c+="No existe";
    }
    return c;
}

int Arreglo::contarNodos(int l){
    int x = l;
    int cont=0;
    while(x>=0){
        x=arr[x]->sig;
        cont++;
    }
    return cont;
}
QString Arreglo::printArr(){
    QString c="";
    for(int x =0;x<10;x++){
        c+= QString("%1  %2 |%3\n").arg(x).arg(arr[x]->valor).arg(arr[x]->sig);
    }
    return c;
}

