/*
        -Descripcion:
    Implementacion de una tabla hash con el metodo: abierto - sondeo cuadratico
    David Alejandro Perez Rico - 320753
    Jesica Yamile Salcido Cadena -  329575
*/
#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

typedef struct snodo{
    string nombre;
    int salario;
    char llave[15]; // RFC "PERD9906168B2"
    bool estado=true;
}tnodo;

tnodo arreglo[MAX];

int hashing(char *llave);
void Insertar(char *, int, char*);
int colicion(int pos);
void mostrar();
int buscar(char *rfc);
void eliminar(char *rfc);

int main(){
    char opc, rfc[15], nombre[40];
    int sueldo, pos;
    tnodo *nuevo;
    do{
        system("cls");
        cout<<"1. Insertar.\n2. Buscar.\n3. Eliminar. \n4. Mostrar todo. \n0. Salir."<<endl;
        cout<<"Ingrese una opcion: ";
        fflush(stdin);
        cin>>opc;
        switch (opc){
            case '0':{
                cout<<"\nQue tenga buen dia! :D\nFin del programa...";
                break;
            }
            case '1':{
                cout<<"Ingrese un RFC: ";
                fflush(stdin);
                cin.getline(rfc, 15, '\n');
                cout<<"Ingrese el nombre: ";
                fflush(stdin);
                cin.getline(nombre, 40, '\n');
                cout<<"Ingrese el sueldo: ";
                fflush(stdin);
                cin>>sueldo;
                Insertar(rfc,sueldo,nombre);
                break;
            }
            case '2':{
                cout<<"Ingrese un RFC: ";
                fflush(stdin);
                cin.getline(rfc, 15, '\n');
                pos = buscar(rfc);
                if(pos>=0){
                    if(arreglo[pos].estado==false){
                        cout<<"---------------------------------------"<<endl;
                        cout<<"#"<<pos<<" "<<arreglo[pos].nombre<<"\t->\t"<<arreglo[pos].llave<<"\t->"<<arreglo[pos].salario<<endl;
                        cout<<"---------------------------------------"<<endl;
                    }
                }else{
                    cout<<"No se encontro ningun RFC almacenado. . ."<<endl;
                }
                break;
            }
            case '3':{
                cout<<"Ingrese un RFC: ";
                fflush(stdin);
                cin.getline(rfc, 15, '\n');
                eliminar(rfc);
                break;
            }
            case '4':{
                mostrar();
                break;
            }
            default:{
                cout<<"Opcion no valida. Ingrese de nuevo . . . "<<endl;
            }
        }
        system("pause");
    }while(opc!='0');
    return 0;
}
/* 
    Para sacar el indice hash se saca sacando el valor ASCII
    y multiplicandolo por su valor en la posicion que corresponde
    cada caracter de la llave y sacando el modulo de la cantidad
    maxima de elementos
*/
int hashing(char *llave){
    // Ejemplo: PERD 9906168B2
    int lenght = strlen(llave);
    int indice=0;
    for(int i=0; i<4; i++)
        indice+=(llave[i]*(i+1));
    indice+=(llave[6]*(6));
    indice = indice%MAX;
    return indice;
}
/* 
    Funcion para llenar el indice del arreglo con la informacion
*/
void llenar(char *rfc, int sueldo, char *nombre, int pos){
    arreglo[pos].estado=false;
    strcpy(arreglo[pos].llave, rfc);
    arreglo[pos].nombre=nombre;
    arreglo[pos].salario=sueldo;
}
/*
    Se intenta insertar la informacion en el indice que que proporciono,
    de no suceder, una colicion se maneja de manera abierta - sondeo cuadratico,
    buscando la posicion mediante los intentos que se realizan
*/
void Insertar(char *rfc, int sueldo, char *nombre){
    int intento=1;
    int pos = hashing(rfc);
    int posI = pos;
    bool ban=false;

    if(arreglo[pos].estado==true){
        cout<<"Se Guardo en casilla: "<<pos<<" de Manera exitosa!!"<<endl;
        llenar(rfc, sueldo, nombre, pos);
    }else{
        posI = colicion(pos);
        if(pos<0){
            cout<<"Retorno inadecuado..."<<endl;
        }else{
            llenar(rfc, sueldo, nombre, posI);
        }
    }
}
/*
    Las coliciones se manejan de sondeo cuadratico, tomando en cuanto los intentos,
    cada intento lo elevamos al cuadrado y se lo sumamos a la posiscion original, pero
    se le saca modulo para que no de una posicion mayor a la permitida.
*/
int colicion(int pos){
    int intento=1, posI = pos;
    bool ban=false;
    while(arreglo[pos].estado!=true && pos<MAX){
        intento++;
        pos = posI + ((intento *intento)%MAX);
        if(intento>MAX){
            posI++;
        }
    }
    if(arreglo[pos].estado==true){
        ban=true;
        cout<<"Se Guardo en casilla: "<<pos<<" de Manera exitosa!!"<<endl;
        return pos;
    }
}
/*
    Funcion no esencial, pero se utiliza para ver si se alamcenaron de manera correcta
    los RFC's ingresados, recorre todo el arreglo verificando si el estado esta "false"
    lo que significa que esta ocuapdo.
*/
void mostrar(){
    cout<<"RFC registrados: (Espacio para: "<<MAX<<")"<<endl;
    cout<<"---------------------------------------"<<endl;
    for(int i=0; i<MAX; i++){
        if(arreglo[i].estado==false){
            cout<<"#"<<i<<" "<<arreglo[i].nombre<<"\t->\t"<<arreglo[i].llave<<endl;
            cout<<"---------------------------------------"<<endl;
        }
    }
}
/*
    En la funcion de buscar lo que hace es primero verificar la posicion con la funcion
    "hashing" y compara la llava del arreglo con la dada por el hash, si no es asi manda 
    a llamar las coliciones para buscarla si se le aplico colicon.
*/
int buscar(char *rfc){
    char compp[15];
    int intento=1;
    int pos = hashing(rfc);
    int posI = pos;
    if(strcmp(rfc,arreglo[pos].llave)==0){
        return pos;
    }else{
        do{
            pos = posI + ((intento *intento)%MAX);
            if(strcmp(rfc,arreglo[pos].llave)==0){
                return pos;
            }
            intento++;
        }while(arreglo[pos].estado!=true && pos<MAX);
        cout<<"Ese RFC aun no esta registrado. . ."<<endl;
        return -1;
    }
    return pos;
}
/*
    A la hora de eliminar lo unico que hace es cambair la bandera de estado a "true"
    que significa que esta disponible para ser manipulada
*/
void eliminar(char *rfc){
    int pos=buscar(rfc);
    if(strcmp(rfc,arreglo[pos].llave)==0){
        arreglo[pos].estado==true;
    }else{
        colicion(pos);
        if(strcmp(rfc,arreglo[pos].llave)==0){
            arreglo[pos].estado==true;
        }else{
            cout<<"Ese RFC aun no esta registrado. . ."<<endl;
        }
    }
}
