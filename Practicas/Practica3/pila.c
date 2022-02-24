
#include <stdlib.h>




typedef void ValorNodo;
typedef struct PilaNodo Pila ;

struct PilaNodo{
    ValorNodo *valorEspecial;

    int valor;
    // PilaNodo *siguiente;
    Pila *ultimo;

};

void inicializarPila(Pila **p, int valor){
    Pila* b = malloc(sizeof(Pila));

    b->valor = valor;
    b->ultimo = NULL;

    *p = b; 

};

int revisar(Pila **p){
    int hayAlgo = -1;
    if (*p!=NULL)
    {
        hayAlgo = (*p)->valor;
    }

    printf("Dato %d\n\n",hayAlgo);
    return hayAlgo;  
};

void push(Pila **p, int valor){

    Pila *b = malloc(sizeof(Pila));

    b->valor = valor;
    b->ultimo = *p;

    *p = b;
};


int pop(Pila **p){

    //Revisar que no este vacio el nodo
    if((*p)==NULL) return -0xFFFFF;

    int enteroRegresar;

    //Guardar la variable para regresarla al usuario
    enteroRegresar = (*p)->valor;


    //Revisar si hay mas nodos hacia abajo en la pila
    if((*p)->ultimo != NULL){
        //Intercambiar el ultimo nodo.
        *p = (*p)->ultimo;
    }


    //Varialbe a entregar
    return enteroRegresar;    

};

void iterarPila(Pila **p){
    Pila * temporal;
    temporal = *p;
    while(temporal->ultimo){
        revisar(&temporal);
        temporal = temporal->ultimo;
        
    }
}