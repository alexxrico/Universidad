/*
	...Estructuras de datos avanzadas...
	Tema: Heaps
	Autor: David Alejandro Perez Rico
	Matricula: 320753 :D
    Fecha de creacion: 23/02/2021
	....................................
*/
#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;
typedef struct snodo{
    int valor;
    char nombre[50];
}tnodo;
tnodo nodo[MAX];
int tam=0;

void insertar(void);
void heapify(int actual);
void minimo(void);
void atender(void);
void vaciar(int posicion);
void heapifyInv(int pos);
void mostrar(void);
int papa(int actual);
int izq(int papa);
int der(int papa);

int main(){
    char opc;
    int valor;
    do{
        system("cls");
        cout<<"1) Nuevo paciente\n2) Conocer siguiten paciente\n3) Atender proximo paciente\n4) Mostrar pacientes\n0) Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opc;
        switch(opc){
            case '0':{
                cout<<"Que tenga buen dia :D"<<endl;
                break;
            }
            case '1':{
                insertar();
                break;
            }
            case '2':{
                minimo();
                break;
            }
            case '3':{
                atender();
                break;
            }
            case '4':{
                mostrar();
                break;
            }
            default:{
                cout<<"Esa opcion no es valida..."<<endl;
                break;
            }
        }
        system("pause");
    } while (opc!='0');
    return 0;
}
void insertar(void){
    if(tam<MAX){
        cout<<"Nombre del paciente: ";
        fflush(stdin);
        cin.getline(nodo[tam].nombre, 50, '\n');
        cout<<"Prioridad: ";
        cin>>nodo[tam].valor;
        tam++;
        heapify(tam-1);
    }
}
void atender(void){
    tnodo aux;
    if(tam<=0){
        cout<<"No hay pacientes por atender, toma un cafe :D"<<endl;
    }else{
        cout<<"Favor de atender a: "<<nodo[0].nombre<<endl;
        cout<<"Con prioridad #"<<nodo[0].valor<<endl;
        nodo[0]=nodo[tam-1];
        vaciar(tam-1); 
        tam--;
        heapifyInv(0); 
    }
}
void vaciar(int pos){
    char nombre[5];
    nodo[pos].valor=999;
    for(int i=0; i<50; i++){
        nodo[pos].nombre[i]='\0';
    }
}
void heapifyInv(int pos){
    tnodo aux;
    int hi = izq(pos);
    int hd = der(pos);
    int menor;
    cout<<"hi->"<<hi<<"\thd->"<<hd<<endl;
    if(hi<tam && hd<tam){
        if(nodo[hi].valor < nodo[hd].valor){
            menor=hi;
        }else{
            menor=hd;
        }
        cout<<"->"<<nodo[pos].valor<<"\t"<<nodo[menor].valor<<endl;
        if(nodo[pos].valor > nodo[menor].valor){
            aux=nodo[pos];
            nodo[pos]=nodo[menor];
            nodo[menor]=aux;
            heapifyInv(menor);
        }
    }
}
void heapify(int actual){
    int p;
    tnodo aux;
    p=papa(actual);
    if(nodo[p].valor > nodo[actual].valor){
        aux=nodo[p];
        nodo[p]=nodo[actual];
        nodo[actual]=aux;
        heapify(p);
    }
}
void minimo(){
    if(tam>0){
        cout<<"El proximo paciente es:"<<endl;
        cout<<"Nombre-> "<<nodo[0].nombre<<endl;
        cout<<"Urgencia-> "<<nodo[0].valor<<endl;
    }else{
        cout<<"No hay proximos pacientes, puedes descanzar!"<<endl;
    }
}
void mostrar(){
    cout<<"Pacientes registrados:"<<endl;
    cout<<"---------------------------------------"<<endl;
    for(int i=0; i<tam; i++){
        cout<<"#"<<nodo[i].valor<<" "<<nodo[i].nombre<<endl;
        cout<<"---------------------------------------"<<endl;
    }
}

int papa(int actual){
    int x=-1;
    if(actual!=0){
        x=(actual-1)/2;
    }
    return x;
}
int izq(int papa){
    int a=-1;
    if((2*papa+1)<MAX){
        a=2*papa+1;
    }
    return a;
}
int der(int papa){
    int a=-1;
    if((2*papa+2<MAX)){
        a=2*papa+2;
    }
    return a;
}