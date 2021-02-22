/*
	...Estructuras de datos avanzadas...
	Tema: Arboles binarios de busqueda
	Autor: David Alejandro Perez Rico
	Matricula: 320753
    Fecha de creacion: 12/02/2021
	....................................
*/
#include<iostream>
using namespace std;

#define N 100
#define VACIO 9999

int arreglo[N];
int tam=0;

int izq(int i);
int der(int i);
int papa(int i);

void insertar (int x);
void eliminar(void);
int minimo(void);
void heapify(int x);
void muestra(void);

int main(){
    char opc;
    int cual;
    do{
        system("cls");
        cout<<"1) Insertar\n2) Eliminar\n3) Minimo\n4) Mostrar\n0) Salir"<<endl;
        cin>>opc;
        switch(opc){
            case '0':{
                cout<<"Que tenga buen dia :D"<<endl;
            }
            case '1':{
                cout<<"Valor a insertar: ";
                cin>>cual;
            }
            case '2':{

            }
            case '3':{
                cout<<"El minimo es: "<<minimo()<<endl;
            }
            case '4':{
                muestra();
            }
            default:{
                cout<<"Opcion no valida..."<<endl;
            }
        }
        system("pause");
    }while(opc!='0');

    return 0;
}
int izq(int i){
    int a=-1;
    if((2*i+1)<N){
        a=2*i+1;
    }
    return a;
}
int der(int i){
    int a=-1;
    if((2*i+2)<N){
        a=2*i+2;
    }
    return a;
}
int papa(int i){
    int x=-1;
    if(i!=0){
        x=(i-1)/2;
    }
    return x;
}
int minimo(void){
    int x=999;
    if(tam>0){
        x=arreglo[0];
    }
    return x;
}
void insertar(int x){
    if(tam<N){
        arreglo[tam]=x;
        tam++;
        heapify(tam-1);
    }
}
// TODO: Implementar la funcion de eliminar
void eliminar(void){

}
void heapify(int x){
    int p, aux;
    p=papa(x);
    if(arreglo[p]>arreglo[x]){
        aux=arreglo[p];
        arreglo[p]=arreglo[x];
        arreglo[x]=aux;
        heapify(p);
    }
}
void muestra(void){
    int i;
    for(i=0; i<tam; i++){
        cout<<" "<<arreglo[i];
    }
}








