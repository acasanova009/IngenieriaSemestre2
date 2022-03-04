
#include <stdlib.h>
#include "global.c"

typedef void ValorNodo;
typedef struct _pilaNodo PilaNodo;

// void iterarRecursivaInterno(Pila **p );

struct _pilaNodo{
    ValorNodo *valorEspecial;

    PilaNodo *ultimo;

};
typedef struct{

    PilaNodo *cabeza;

}Pila;



void * revisarNodo(PilaNodo **p, DISPLAY fdisp){
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
    (*p)->cabeza =NULL;
}
void push(Pila **p,  ValorNodo *valorNuevo){

    PilaNodo *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(PilaNodo));
    nuevoNodo->valorEspecial = valorNuevo;
    nuevoNodo->ultimo =(*p)->cabeza;
  
    (*p)->cabeza = nuevoNodo;
};


void *  pop(Pila **p){

    
    if((*p)==NULL) 
    {
        printf("Significa que no existe nodo cabeza");
        return NULL;
    }
    if ((*p)->cabeza==NULL)
    { 
        return NULL;
    }

    
        

    void * valorTemp;

   
   if ((*p)->cabeza->valorEspecial!=NULL)
   {
    valorTemp = (*p)->cabeza->valorEspecial;
       /* code */
   }
   
    (*p)->cabeza = (*p)->cabeza->ultimo;
   
    
    return valorTemp;    

};

void iterarPila(Pila **p, DISPLAY fDisplay){
    if((*p)==NULL) 
    {
        printf("Significa que no existe nodo cabeza");
        return;
    }
    if((*p)->cabeza==NULL) 
    {
        printf("Ya estoy en pila vacia");
        return;
    }
 
    
    PilaNodo * nodoTemporal;
    nodoTemporal = (*p)->cabeza;
    
    while (nodoTemporal!=NULL)
    {
        revisarNodo(&nodoTemporal, fDisplay);
        nodoTemporal = nodoTemporal->ultimo;

    }
}

// void iterarRecursiva(Pila **p){
//     Pila * nodoTemporal;
//     nodoTemporal = *p;

//     iterarRecursivaInterno(&nodoTemporal);
// }
// void iterarRecursivaInterno(Pila **p ){

//     if ((*p) ==NULL)
//         return;

//     revisarContenido(&(*p));
//     iterarRecursivaInterno(&(*p)->ultimo);

// }