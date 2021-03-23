/*
	...Estructuras de datos avanzadas...
	Tema: Tries
	Autor: David Alejandro Perez Rico
	Matricula: 320753 
    Fecha de creacion: 22/03/2021
	....................................
*/
#include <iostream>
#include <string>
using namespace std;
constexpr size_t n_letras = 26;
typedef struct nodo{
	nodo *padre=NULL;
	nodo *hijos[n_letras];
	bool final=false;
	char letra='\0';
	~nodo(){
		for(size_t i=0; i<n_letras; i++){
			delete hijos[i];
		}
	}
	size_t cont_h (){
		size_t counter = 0;
		for(size_t i=0; i<n_letras; i++){
			if(hijos[i] != NULL){
				++counter;
			}
		}
		return counter;
	}
}tnodo;

tnodo *raiz;   // Apuntador a la raiz
void insertar(void);
void buscar(void);
void eliminar(void);

int main(int argc, char const *argv[])
{
	char opc;
    raiz = new tnodo();
	do{
		system("cls");
		cout<<"1) Ingresar\n2) Buscar\n3) Eliminar\n0) Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case '0':{
				cout<<"Que tenga un buen dia :D"<<endl;
			}
			case '1':{
				// Insertar
			}
			case '2':{
				// Buscar
			}
			case '3':{
				//Eliminar
			}
			default:{
				cout<<"Esa opcion no es valida..."<<endl;
			}
		}
		system("pause");
	}while(opc!='0');
    return 0;
}
