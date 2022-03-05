#include <stdbool.h>
#include <stdlib.h>
#include "global.c"

typedef void ValorNodo;
typedef struct _queueNodo QueueNodo;


struct _queueNodo{
    ValorNodo *valor;
    QueueNodo *siguiente;
};
typedef struct{

    QueueNodo *cabeza;
    QueueNodo *rabo;
    int elementos;

}Queue;


bool queueEstaVacia(Queue **queueOriginal){
    
    bool estaVacia = false;
    if ((*queueOriginal)->cabeza==NULL && (*queueOriginal)->rabo==NULL){
        estaVacia = true;
    }
    return estaVacia;
}
// Regresar el valor del nodo.
void * queueRevisarNodo(QueueNodo **queueOriginal, DISPLAY fdisp){
    if(*queueOriginal==NULL) return NULL;
    void * valorTemp;
    if ((*queueOriginal)->valor!=NULL)
            valorTemp = (void*)(*queueOriginal)->valor;
    
    
    fdisp(valorTemp);
    
    return valorTemp;  
};

void queueIniciar(Queue **queueOriginal){
    (*queueOriginal) =malloc(sizeof(Queue));
    (*queueOriginal)->cabeza =NULL;
    (*queueOriginal)->rabo =NULL;
    (*queueOriginal)->elementos =0;

}
void queuePush(Queue **queueOriginal,  ValorNodo *valorNuevo){
    if(*queueOriginal==NULL) return;

    QueueNodo *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodo));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->siguiente =NULL;
  
    (*queueOriginal)->elementos++;
    if ((*queueOriginal)->rabo==NULL)
    {
        (*queueOriginal)->rabo = nuevoNodo;
        (*queueOriginal)->cabeza = nuevoNodo;
        
    }else{
        (*queueOriginal)->rabo->siguiente = nuevoNodo;
        (*queueOriginal)->rabo = nuevoNodo;
        
    }
    
    
    
};


void *  queuePop(Queue **queueOriginal){

    void * valorTemp = NULL;
   if (!queueEstaVacia(queueOriginal)){

    (*queueOriginal)->elementos--;

    if ((*queueOriginal)->cabeza!=NULL)
    {
        valorTemp = (*queueOriginal)->cabeza->valor;

        // SI estan apuntando lo mismo, eliminar.
        if ((*queueOriginal)->rabo == (*queueOriginal)->cabeza)
        {
            (*queueOriginal)->cabeza = (*queueOriginal)->rabo = NULL;
        }
        else{
            (*queueOriginal)->cabeza = (*queueOriginal)->cabeza->siguiente;
        }
        
        /* code */
    }
   }

    return valorTemp;    

};

void queueIterar(Queue **queueOriginal, DISPLAY fDisplay){
    if((*queueOriginal)==NULL) 
        return;

    if(!queueEstaVacia(queueOriginal)) 
    {
        
        QueueNodo * nodoTemporal;
        nodoTemporal = (*queueOriginal)->cabeza;
        
        while (nodoTemporal!=NULL)
        {
            queueRevisarNodo(&nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->siguiente;

        }
        
    }
 
    
}