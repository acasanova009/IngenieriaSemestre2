
#include <stdlib.h>
#include "global.c"

typedef void ValorNodo;
typedef struct _pilaNodo PilaNodo;



struct _pilaNodo{
    ValorNodo *valor;
    PilaNodo *ultimo;

};
typedef struct{

    PilaNodo *cabeza;
    PilaNodo *rabo;

}Pila;



void * pilaRevisarNodo(PilaNodo **pilaOriginal, DISPLAY fdisp){
    if(*pilaOriginal==NULL) return NULL;
    void * valorTemp;
    if ((*pilaOriginal)->valor!=NULL)
    {
        valorTemp = (void*)(*pilaOriginal)->valor;
    }
    
    fdisp(valorTemp);
    
    return valorTemp;  
};

void pilaIniciar(Pila **pilaOriginal){
    (*pilaOriginal) =malloc(sizeof(Pila));
    (*pilaOriginal)->cabeza =NULL;
}
void pilaPush(Pila **pilaOriginal,  ValorNodo *valorNuevo){

    PilaNodo *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(PilaNodo));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->ultimo =(*pilaOriginal)->cabeza;
  
    (*pilaOriginal)->cabeza = nuevoNodo;
    if ( (*pilaOriginal)->rabo==NULL)
    {   
         (*pilaOriginal)->rabo = nuevoNodo;
        
    }
    
};


void *  pilaPop(Pila **pilaOriginal){

    
    if((*pilaOriginal)==NULL) 
    {
        printf("Significa que no existe nodo cabeza");
        return NULL;
    }
    if ((*pilaOriginal)->cabeza==NULL)
    { 
        return NULL;
    }

    void * valorTemp;
   
   if ((*pilaOriginal)->cabeza->valor!=NULL)
   {
    valorTemp = (*pilaOriginal)->cabeza->valor;
   
   }
   
    (*pilaOriginal)->cabeza = (*pilaOriginal)->cabeza->ultimo;
   
    
    return valorTemp;    

};

void pilaIterar(Pila **pilaOriginal, DISPLAY fDisplay){
    if((*pilaOriginal)==NULL) 
    {
        printf("Significa que no existe nodo cabeza");
        return;
    }
    if((*pilaOriginal)->cabeza==NULL) 
    {
        printf("Ya estoy en pila vacia");
        return;
    }
 
    
    PilaNodo * nodoTemporal;
    nodoTemporal = (*pilaOriginal)->cabeza;
    
    while (nodoTemporal!=NULL)
    {
        pilaRevisarNodo(&nodoTemporal, fDisplay);
        nodoTemporal = nodoTemporal->ultimo;

    }
}