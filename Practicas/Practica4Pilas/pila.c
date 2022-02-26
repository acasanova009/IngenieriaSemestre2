
#include <stdlib.h>




typedef void ValorNodo;
typedef struct PilaNodo Pila ;

void iterarRecursivaInterno(Pila **p );

struct PilaNodo{
    ValorNodo *valorEspecial;

    int valor;
    // PilaNodo *siguiente;
    Pila *ultimo;

};

void inicializarPila(Pila **p, int valor){
    Pila* b = malloc(sizeof(Pila));
    ValorNodo *vNodo = malloc(sizeof(ValorNodo));


    b->valor = valor;
    // b->valorEspecial = valorEspecial;
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



    Pila *b;
    
    b = malloc(sizeof(Pila));
    b->valor = valor;
    //  b->valorEspecial = valorEspecial;
    b->ultimo =*p;
    
    

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
    Pila * pilaTemp;
    pilaTemp = *p;
    
    while (pilaTemp!=NULL)
    {
        revisar(&pilaTemp);
        pilaTemp = pilaTemp->ultimo;

    }
}

void iterarRecursiva(Pila **p){
    Pila * pilaTemp;
    pilaTemp = *p;

    iterarRecursivaInterno(&pilaTemp);
}
void iterarRecursivaInterno(Pila **p ){

    if ((*p) ==NULL)
        return;

    revisar(&(*p));
    iterarRecursivaInterno(&(*p)->ultimo);

}