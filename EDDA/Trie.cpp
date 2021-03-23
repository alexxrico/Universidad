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
void insertar(const string &palabra);
void buscar(void);
void eliminar(void);
void autocompletar(void);
nodo *int_buscar(const string&);
size_t letra(char);
nodo *crear(char letra, nodo *padre);

int main(int argc, char const *argv[])
{
	string palabra;
	char opc;
    raiz = new tnodo();
	do{
		system("cls");
		cout<<"1) Ingresar\n2) Buscar\n3) Eliminar 4) Autocompletar\n0) Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		switch(opc){
			case '0':{
				cout<<"Que tenga un buen dia :D"<<endl;
			}
			case '1':{
				cout<<"Ingrese la palabra: ";
				cin>>palabra;
				cin.ignore();
				insertar(palabra);
				// Insertar
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
void insetar(const string &palabra){
	size_t lim;
	tnodo *lim_n = int_buscar(palabra,lim);
	if(lim == palabra.length()){
		lim_n->final = true;
		return;
	}
	for(size_t largo = palabra.length(); lim<largo; ++lim){
		size_t nuevo_hijo = letra(palabra[lim]);
		lim_n->hijos[nuevo_hijo] = crear(palabra[lim],lim_n);
		lim_n = lim_n->hijos[nuevo_hijo];
	}
	lim_n->final = true;
}
nodo *int_buscar(const string &palabra){
	size_t i;
	return int_buscar(palabra,i);
}
nodo *int_buscar(const string &palabra, size_t &limite){
	const size_t largo = palabra.length();
	size_t i=0;
	nodo *siguiente = raiz;
	for(i; i<largo; ++i){
		size_t pos_buscar = palabra[i];
		if(siguiente->hijos[pos_buscar] == NULL){
			break;
		}
		siguiente = siguiente->hijos[pos_buscar];
	}
	limite = i;
	return siguiente;
}
size_t letra(char c){
	return c - 'a';
}
nodo *crear(char letra, nodo *padre){
	nodo *nuevo = new nodo();
	nuevo->padre = padre;
	nuevo->letra = letra;
	return nuevo;
}
