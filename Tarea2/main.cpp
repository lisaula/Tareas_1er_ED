#include <QCoreApplication>
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char* temp="";
    char* arreglo[20];
    arreglo[0]="K";arreglo[5]="A";arreglo[10]="4";arreglo[15]="5";
    arreglo[1]="J";arreglo[6]="1";arreglo[11]="5";arreglo[16]="6";
    arreglo[2]="Q";arreglo[7]="J";arreglo[12]="6";arreglo[17]="8";
    arreglo[3]="1";arreglo[8]="A";arreglo[13]="7";arreglo[18]="A";
    arreglo[4]="2";arreglo[9]="3";arreglo[14]="8";arreglo[19]="2";
    int cont=0;
    for(int x = 0; x<20;x++){
        cout<<"#"<<x+1<<"-"<<arreglo[x]<<endl;
    }
    for(int x=0;x<20;x++){
        for(int j =x+1;j<20;j++){
            if(arreglo[x]!=""){
                if(arreglo[x]==arreglo[j]){
                    cont++;
                    for(int c=j+1;c<20;c++){
                        temp=arreglo[c];
                        arreglo[c-1]=temp;
                    }
                    arreglo[20-cont]="";
                }
            }
        }
    }
    cout<<"Se repitieron: "<<cont<<endl;
    cout<<"Nuevo arreglo"<<endl;
    for(int x = 0; x<20;x++){
        if(arreglo[x]=="")
            break;
        cout<<"#"<<x+1<<"-"<<arreglo[x]<<endl;
    }

    return a.exec();
}
