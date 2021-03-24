/*
	...Estructuras de datos avanzadas...
	Tema: Tries
	Autor: David Alejandro Perez Rico
	Matricula: 320753 
    Fecha de creacion: 22/03/2021
	....................................
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAX 28
using namespace std;
typedef struct nodo{
	struct nodo *hijos[MAX];
	bool fin;
}NODO;

NODO *raiz = NULL;

NODO *crear(void);
void Insertar(NODO *raiz, string palabra);
bool Buscar();
NODO *Borrar();

int main(int argc, char const *argv[]){
	string palabra;
	char opc;
    raiz = crear();
	do{
		system("cls");
		cout<<"1) Ingresar\n2) Buscar\n3) Eliminar\n4) Autocompletar\n0) Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case '0':{
				cout<<"Que tenga un buen dia :D"<<endl;
			}
			case '1':{ // Insertar
				cout<<"Ingrese la palabra a insertar: ";
				cin>>palabra;
				Insertar(raiz,palabra);
				break;
			}
			case '2':{
				// Buscar
			}
			case '3':{
				// Eliminar
			}
			case '4':{
				// Autocompletar
			}
			default:{
				cout<<"Esa opcion no es valida..."<<endl;
			}
		}
		system("pause");
	}while(opc!='0');
    return 0;
}
NODO *crear(){
	NODO *nod = new (NODO);
	nod->fin = false;
	for(int i=0; i<MAX; i++){
		nod->hijos[i]=NULL;
	}
	return nod;
}
void Insertar(NODO *raiz, string palabra){
	int indice;
	NODO *nuevo = raiz;
	for(int i=0; i<palabra.length(); i++){
		indice = palabra[i]-'a';
		if(!nuevo->hijos[indice]){
			nuevo->hijos[indice] = crear();
		}
		nuevo = nuevo->hijos[indice];
	}
	nuevo->fin = true;
}
