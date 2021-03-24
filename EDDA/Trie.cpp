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
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
using namespace std;
typedef struct nodo{
	struct nodo *hijos[MAX];
	bool fin;
}NODO;

NODO *crear(void);
void Insertar(NODO *raiz, string palabra);
bool Buscar(NODO *raiz, string palabra);
NODO *Borrar(NODO *raiz, string palabra, int profundidad);
bool Vacio(NODO *raiz);
int ImpPrefijo(NODO *raiz, string palabra);
bool UltimoNodo(NODO *raiz);
void Prefijos(NODO *raiz, string prefij);

int main(int argc, char const *argv[]){
	string palabra;
	char opc;
	int aux;
    NODO *raiz = crear();
	do{
		system("cls");
		cout<<"1) Ingresar\n2) Buscar\n3) Eliminar\n4) Autocompletar\n0) Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case '0':{
				cout<<"Que tenga un buen dia :D"<<endl;
			}
			case '1':{	// Insertar
				cout<<"Ingrese la palabra a insertar: ";
				cin>>palabra;
				Insertar(raiz,palabra);
				break;
			}
			case '2':{	// Buscar
				cout<<"Palabra a buscar: ";
				cin>>palabra;
				if(Buscar(raiz,palabra)==true){
					cout<<"La palabra fue encontrada!"<<endl;
				}else{
					cout<<"Esa palabra no existe"<<endl;
				}
				break;
			}
			case '3':{	// Eliminar
				cout<<"Palabra por eliminar: ";
				cin>>palabra;
				Borrar(raiz,palabra,0);
				break;
			}
			case '4':{	// Autocompletar
				cout<<"Prfijo de palabra: ";
				cin>>palabra;
				aux=0;
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
bool Buscar(NODO *raiz, string palabra){
	int indice;
	NODO *buscar = raiz;
	for(int i=0; i<palabra.length(); i++){
		indice=palabra[i]-'a';
		if(!buscar->hijos[indice]){
			return false;
		}
		buscar = buscar->hijos[indice];
	}
	return (buscar!=NULL && buscar->fin);
}
NODO *Borrar(NODO *raiz, string palabra, int profundidad){
	int indice;
	if(!raiz){
		return NULL;
	}
	if(profundidad==palabra.size()){
		if(raiz->fin){
			raiz->fin = false;
		}
		if(Vacio(raiz)){
			delete(raiz);
			raiz=NULL;
		}
		return raiz;
	}
	indice=palabra[profundidad]-'a';
	raiz->hijos[indice]=Borrar(raiz->hijos[indice],palabra,profundidad+1);
	if(Vacio(raiz) && raiz->fin==false){
		delete(raiz);
		raiz=NULL;
	}
	return raiz;
}
bool Vacio(NODO *raiz){
	for(int i=0; i<MAX; i++){
		if(raiz->hijos[i]){
			return false;
		}
	}
	return true;
}
int ImpPrefijo(NODO *raiz, string palabra){
	NODO *prefijo = raiz;
	bool pal, ultimo;
	int i, indice, n=palabra.length();
	for(i=0; i<n; i++){
		indice=CHAR_TO_INDEX(palabra[i]);
		if(!prefijo->hijos[indice]){
			return 0;
		}
		prefijo = prefijo->hijos[indice];
	}
	pal = (prefijo->fin==true);
	ultimo = UltimoNodo(prefijo);
	if(pal && ultimo){
		cout<<palabra<<endl;
		return -1;
	}
	if(!ultimo){
		string pref=palabra;
		Prefijos(prefijo, pref);
		return 1;
	}
}
bool UltimoNodo(NODO *raiz){
	for(int i=0; i<MAX; i++){
		if(raiz->hijos[i]){
			return 0;
		}
	}
	return 1;
}
void Prefijos(NODO *raiz, string prefij){
	if(raiz->fin){
		cout<<prefij<<endl;
	}
	if(UltimoNodo(raiz)){
		return;
	}
	for(int i=0; i<MAX; i++){
		if(raiz->hijos[i]){
			prefij.push_back(97+i);
			Prefijos(raiz->hijos[i],prefij);
			prefij.pop_back();
		}
	}
}