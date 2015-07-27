#include <QCoreApplication>
#include <iostream>
#include <vector>
#include<nodo.h>
using namespace std;

Nodo* getFreeNodo(vector<Nodo*> g){
    for(int x=0;x<g.size();x++){
        if(g[x]->getNumber()==0)
            return g[x];
    }
    return NULL;
}
int grupo=0;

int getNumber(){
    return grupo;
}
int getNextNumber(){
    grupo++;
    return grupo;
}

void printGrafo(vector<Nodo*> grafo){
    int cont=1;
    while(cont<=grupo){
        cout<<"Grupo #"<<cont<<": ";
        for(int x=0;x<grafo.size();x++){
            Nodo *temp=grafo[x];
            if(temp->getNumber()==cont){
                cout<<grafo[x]->getNombre()<<" ";
            }
        }
        cout<<"\n";
        cont++;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<Nodo*>grafo;
    Nodo* AB = new Nodo("AB"),*AC= new Nodo("AC"), *AD= new Nodo("AD"),
        * BA = new Nodo("BA"),*BC= new Nodo("BC"), *BD= new Nodo("BD"),
        * DA = new Nodo("DA"),*DB= new Nodo("DB"), *DC= new Nodo("DC"),
        * EA = new Nodo("EA"),*EB= new Nodo("EB"), *EC= new Nodo("EC"),*ED= new Nodo("ED");
    AB->setAdyacente(BC);AB->setAdyacente(BD);AB->setAdyacente(DA);AB->setAdyacente(EA);
    AC->setAdyacente(BD);AC->setAdyacente(DA);AC->setAdyacente(DB);AC->setAdyacente(EA);AC->setAdyacente(EB);
    AD->setAdyacente(EA);AD->setAdyacente(EB);AD->setAdyacente(EC);
    BC->setAdyacente(DB);BC->setAdyacente(EB);
    BD->setAdyacente(DA);BD->setAdyacente(EB);BD->setAdyacente(EC);
    DA->setAdyacente(EB);DA->setAdyacente(EC);
    DB->setAdyacente(EC);
    bool asignar;

    grafo.push_back(AB);grafo.push_back(AC);grafo.push_back(AD);
    grafo.push_back(BA);grafo.push_back(BC);grafo.push_back(BD);
    grafo.push_back(DA);grafo.push_back(DB);grafo.push_back(DC);
    grafo.push_back(EA);grafo.push_back(EB);grafo.push_back(EC);grafo.push_back(ED);
    while(true){
        Nodo* temp=getFreeNodo(grafo);
        if(temp==NULL){
            break;
        }
        temp->setGrupo(getNextNumber());
        for(int i=0;i<grafo.size();i++){
            asignar=true;
            if(grafo[i]->getNumber()==0){
                for(int j=0;j<grafo[i]->getVector().size();j++){
                    if(grafo[i]->getVector()[j]->getNumber()==getNumber()){
                        asignar=false;
                        break;
                    }
                }
                if(asignar){
                    grafo[i]->setGrupo(getNumber());
                }
            }
        }
    }

    printGrafo(grafo);

    return a.exec();
}


