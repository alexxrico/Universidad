
/*
	...Estructuras de datos avanzadas...
	Tema: Arboles binarios de busqueda
	Autor: David Alejandro Perez Rico
	Matricula: 320753
    Fecha de creacion: 12/02/2021
	....................................
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

typedef struct snodo
{
    int valor;
    struct snodo *izq, *der, *papa;
}tnodo;

tnodo *arbol=NULL, *aux2=NULL;

int insertar(int x);
tnodo * buscar(int x);

tnodo *minimo(void);
tnodo *maximo(void);

int eliminar(int x);
int altura(tnodo *nodo);
int fe(tnodo *actual);
void balanceo(tnodo *actual);
void imprimir(tnodo *x);
void rsi(tnodo *actual);
void rdi(tnodo *actual);
void rsd(tnodo *actual);
void rdd(tnodo *actual);

int main(int argc, const char * argv[]) {
    int x, y,z,opc;
    int n;
    tnodo *xb;
        do{
            printf("\n1) Insertar \n2) Buscar \n3) Eliminar \n4) Minimo \n5) Maximo\n6) Altura\n7) Imprimir \n8) Salir\nOpcion:");
            scanf("%i",&opc);
            switch(opc)
            {
                case 1: printf("\nValor  insertar: "); scanf("%i", &x);
                        if(insertar(x)==1)
                            printf("\nSi se pudo insertar\n");
                        else
                            printf("\nEl numero ya fue agregado\n");
                        break;
                case 2: printf("\nValor  buscar: "); scanf("%i", &x);
                        xb=buscar(x);
                        if(xb==NULL)
                            printf("\nEl valor no existe");
                        else
                            printf("\nSI existe es %i", xb->valor);
                    break;
                case 3: printf("\nValor  eliminar: "); scanf("%i", &x);
                		z = eliminar(x);
                		if(z==1){
                			printf("\nEl numero fue eliminado con exito!");
						}else{
							printf("\nEl numero no existe...");
						}
                    break;
                case 4:
                    xb=minimo();
                    if(xb!=NULL)
                        printf("\nEl minimo es %i", xb->valor);
                    else
                        printf("\nNo hay minimo, esta vacio");
                    break;
                case 5: xb=maximo();
                    if(xb!=NULL)
                        printf("\nEl maximo es %i", xb->valor);
                    else
                        printf("\nNo hay maximo, esta vacio");
                    break;
                case 6:{
                    if(arbol==NULL){
                        printf("El arbol esta vacio!\n");
                    }else{
                        printf("Ingrese un nodo: \n");
                        scanf("%i",&n);
                        xb=buscar(n);
                        if(xb==NULL){
                            printf("El nodo no se encontro\n");
                        }else{
                            x=altura(xb);
                            printf("La altura del nodo es: %i",x-1);
                            printf("\nEl factor de equilibrio del nodo es: %i",fe(xb));
                        }
                    }
                  break;
                }
                case 7:{
                    if(arbol==NULL){
                        printf("\nEl arbol esta vacio...");
                    }else{
                        imprimir(arbol);
                    }
                }
            }
            printf("\n");
            system("pause");
            system("cls");
        }while(opc!=8);
}
int fe(tnodo *actual){ //Factor de equilibrio
    int a=0;
    if(actual!=NULL){
        if(actual->der!=NULL && actual->izq!=NULL){
            a= altura(actual->der)-altura(actual->izq);
        }
        if(actual->der!=NULL && actual->izq==NULL){
            a =altura(actual->der);
        }
        if(actual->der==NULL && actual->izq!=NULL){
            a = 0 - altura(actual->izq);
        }
    }
    return a;
}
int altura(tnodo *actual){ //Altura de un nodo
    int ai=0, ad=0, a=0;
    if(actual!=NULL){
        ai=altura(actual->izq);
        ad=altura(actual->der);
        if(ai>ad){
            a=1+ai;
        }else{
            a=1+ad;
        }
    }
    return a;
}
int insertar(int x){
    tnodo *n1;
    int pude=0;
    n1 = buscar(x);
    if(n1==NULL)
    {
        n1 = (tnodo *)malloc(sizeof(tnodo));
        if(n1!=NULL){
            n1->valor = x;
            n1->der = NULL;
            n1->izq=NULL;
            n1->papa=NULL;
            if(arbol==NULL)
                arbol=n1;
            else if(x < aux2->valor  ){
                aux2->izq = n1;
                n1->papa=aux2;
            }   
            else{
                aux2->der = n1;
                n1->papa=aux2;
            }
            pude = 1;
            balanceo(n1);
        }
    }
    return pude;
}

tnodo * buscar(int x){
    tnodo *aux;
    aux =arbol;
    aux2=NULL;
    while(aux!=NULL)
    {
        aux2=aux;
        if(aux->valor == x)
            break;
        else if(x < aux->valor)
            aux = aux->izq;
        else
            aux = aux->der;
    }
    return aux;
}
tnodo * minimo(void){
    tnodo *aux;
    aux =arbol;
    aux2=NULL;
    while(aux!=NULL)
    {
        aux2= aux;
        aux = aux->izq;
    }
    return aux2;
}
tnodo * maximo(void){
    tnodo *aux;
    aux =arbol;
    aux2=NULL;
    while(aux!=NULL)
    {
        aux2= aux;
        aux = aux->der;
    }
    return aux2;
}
int eliminar(int x){
	tnodo *nElim, *ant, *aux;
	nElim=buscar(x);
	if(nElim==NULL){
		return 0;
	}else{
		aux=nElim;
		if(aux==arbol){
			free(aux);
			arbol==NULL;
		}else{
			aux=aux->izq;
			if(aux!=NULL){
				while(aux->der!=NULL){
					ant=aux;
					aux=aux->der;
				}
				nElim->valor=ant->valor;
				ant->der=NULL;
				free(ant);
			}else{
				free(nElim);
			}
		}
		return 1;
	}
}
void balanceo(tnodo *actual){
    int fe1;
    tnodo *aux;
    aux=actual->papa;
    while(aux!=NULL){
        fe1=fe(aux);
        printf("\nRevisando el valor: %i con FE: %i",aux->valor,fe1);
        if(fe1<=-2 && fe(aux->izq)<0){ // Rotacion simple a la derecha
            rsd(aux);
        }if(fe1<=-2 && fe(aux->izq)>=0){ 
            rdd(aux);
        }if(fe1>=2 && fe(aux->der)>=0){
            rsi(aux);
        }if(fe1>=2 && fe(aux->der)<0){
            rdi(aux);
        }
        aux=aux->papa;
    }
}
void rsi(tnodo *actual){ //Tiene errores al hacer la rotacion
    tnodo *rp, *temp2;
    printf("\nRotacion simple a la izquierda");
    rp=actual->der;
    rp->papa=actual->papa;
    rp->izq=actual;
    actual->der=NULL;
    if(rp->papa==NULL){
        arbol=rp;
    }else{
        actual->papa->der=rp;
        actual->papa=rp;
    }
    printf("\t %i",arbol->valor);
}
void rdi(tnodo *actual){
    printf("\nRotacion doble a la izquierda");
}
void rsd(tnodo *actual){
    printf("\nRotacion simple a la derecha");

}
void rdd(tnodo *actual){
    printf("\nRotacion doble a la derecha");
}
void imprimir(tnodo *x){
    if(x!=NULL){
        printf(" %i ", x->valor);
        printf("Izq: ");
        imprimir(x->izq);
        printf("Derecho: ");
        imprimir(x->der);
    }else{
        printf("---\n");
    }
}




