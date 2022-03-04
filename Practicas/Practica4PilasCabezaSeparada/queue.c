#include <stdbool.h>
#include <stdlib.h>
#include "global.c"

typedef void ValorNodo;
typedef struct _queueNodo QueueNodo;

// void iterarRecursivaInterno(Pila **p );

struct _queueNodo{
    ValorNodo *valorEspecial;

    QueueNodo *siguiente;

};
typedef struct{

    QueueNodo *cabeza;
    QueueNodo *rabo;
    int elementos;

}Queue;


bool estaVacia(Queue **p){
    bool estaVacia = false;
    if ((*p)->cabeza==NULL && (*p)->rabo==NULL){
        estaVacia = true;
    }
    return estaVacia;
}

void * revisarNodo(QueueNodo **p, DISPLAY fdisp){
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

void iniciarQueue(Queue **q){
    (*q) =malloc(sizeof(Queue));
    (*q)->cabeza =NULL;
    (*q)->rabo =NULL;
    (*q)->elementos =0;

}
void push(Queue **p,  ValorNodo *valorNuevo){

    QueueNodo *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodo));
    nuevoNodo->valorEspecial = valorNuevo;
    nuevoNodo->siguiente =NULL;
  
    (*p)->elementos++;
    if ((*p)->rabo==NULL)
    {
        (*p)->rabo = nuevoNodo;
        (*p)->cabeza = nuevoNodo;
        /* code */
    }else{
        (*p)->rabo->siguiente = nuevoNodo;
        (*p)->rabo = nuevoNodo;
        
    }
    
    
    
};


void *  pop(Queue **q){

    void * valorTemp = NULL;
   if (!estaVacia(q)){

    (*q)->elementos--;

    if ((*q)->cabeza!=NULL)
    {
        valorTemp = (*q)->cabeza->valorEspecial;

        // SI estan apuntando lo mismo, eliminar.
        if ((*q)->rabo == (*q)->cabeza)
        {
            (*q)->cabeza = (*q)->rabo = NULL;
        }
        else{
            (*q)->cabeza = (*q)->cabeza->siguiente;
        }
        
        /* code */
    }
   }

    return valorTemp;    

};

void iterarQueue(Queue **p, DISPLAY fDisplay){
    if((*p)==NULL) 
    {
        printf("No hay nada");
        return;
    }
    if(!estaVacia(p)) 
    {
        
        QueueNodo * nodoTemporal;
        nodoTemporal = (*p)->cabeza;
        
        while (nodoTemporal!=NULL)
        {
            revisarNodo(&nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->siguiente;

        }
        
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
//     iterarRecursivaInterno(&(*p)->siguiente);

// }