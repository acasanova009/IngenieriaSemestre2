
#include <stdlib.h>
#include "global.c"

typedef void ValorNodo;
typedef struct PilaNodo Pila ;

void iterarRecursivaInterno(Pila **p );

struct PilaNodo{
    ValorNodo *valorEspecial;

    Pila *ultimo;

};


void * revisarNodo(Pila **p, DISPLAY fdisp){
    if(*p==NULL) return NULL;
    void * valorTemp;
    if ((*p)->valorEspecial!=NULL)
    {
        valorTemp = (void*)(*p)->valorEspecial;
    }
    // printf("[");
    fdisp(valorTemp);
    // printf("]\n");
    return valorTemp;  
};

void iniciarPila(Pila **p){
    (*p) =malloc(sizeof(Pila));
    (*p)->valorEspecial =NULL;
    (*p)->ultimo =NULL;


}
void push(Pila **p,  ValorNodo *valorNuevo){

    Pila *b;
    
    b = malloc(sizeof(Pila));
    b->valorEspecial = valorNuevo;
    b->ultimo =*p;
  
    *p = b;
};


void *  pop(Pila **p){

    //Revisar que no este vacio el nodo
    if((*p)==NULL) 
    {
        printf("Aqui hay algo raro");
        return NULL;
    }
        

    void * valorTemp;

   
    valorTemp = (*p)->valorEspecial;
    if ((*p)->ultimo!=NULL)
    {
        *p = (*p)->ultimo;
        /* code */
    }
    
    
    return valorTemp;    

};

void iterarPila(Pila **p, DISPLAY fDisplay){
    if (*p ==NULL) return;
 
    
    Pila * pilaTemp;
    pilaTemp = *p;
    
    while (pilaTemp->ultimo!=NULL)
    {
        revisarNodo(&pilaTemp, fDisplay);
        pilaTemp = pilaTemp->ultimo;

    }
}

// void iterarRecursiva(Pila **p){
//     Pila * pilaTemp;
//     pilaTemp = *p;

//     iterarRecursivaInterno(&pilaTemp);
// }
// void iterarRecursivaInterno(Pila **p ){

//     if ((*p) ==NULL)
//         return;

//     revisarContenido(&(*p));
//     iterarRecursivaInterno(&(*p)->ultimo);

// }