#include "arreglo.h"

Arreglo::Arreglo()
{
cont =0;
}

void Arreglo::desplazar(int pos, bool ID){
    if(ID){
        for(int x = cont+1;x>pos;x--){
            arr[x]=arr[x-1];
        }
        arr[pos]=0;
    }else{
        for(int x = pos+1; x<=cont;x++){
            arr[x-1]=arr[x];
            arr[x]=0;
        }
    }
}

void Arreglo::add(int num){
    if(cont<10)
        arr[cont]=num;
        cont++;
}

void Arreglo::print(){
    cout<<cont<<endl;
    for(int x=0;x<10;x++){
        cout<<arr[x]<<"|";
    }
    cout<<endl;
}
QString Arreglo::imprimir(){
    QString temp= QString("%1 | %2 | %3 | %4 | %5 | %6 | %7 | %8 | %9 |%10").arg(arr[0]).arg(arr[1]).arg(arr[2]).arg(arr[3]).arg(arr[4]).arg(arr[5]).arg(arr[6]).arg(arr[7]).arg(arr[8]).arg(arr[9]);

    return temp;
}

void Arreglo::insertar(int pos, int num){
    if(pos<cont){
        if(cont<10){
            desplazar(pos,true);
            arr[pos]=num;
            cont++;
        }
    }else{
        if(cont<10)
            add(num);
    }
}
void Arreglo::eliminar(int num){
    int pos = buscar(num);
    if(pos>=0){
        desplazar(pos,false);
        cont--;
    }
}

int Arreglo::buscar(int num){
   for(int x=0;x<cont;x++){
       if(arr[x]==num){
           return x;
       }
   }
   return -1;
}
