#include <stdbool.h>
#include <stdlib.h>
#include "global.h"

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
    FREE freeFunctionNodeValue;


}Queue;

bool queueEsNull(Queue *queueOriginal){
    bool esNull = false;
    if (queueOriginal==NULL)
        esNull = true;
    return esNull;
}
void queueSetFreeFunctionForNodeValues(Queue *queueOriginal, FREE newFreeFunctionNodeValue){
    if (queueEsNull(queueOriginal)) return;

    queueOriginal->freeFunctionNodeValue = newFreeFunctionNodeValue;
    

}
bool queueEstaVacia(Queue *queueOriginal){
     if (queueEsNull(queueOriginal)) return true;
        
    bool estaVacia = false;
    if (queueOriginal->cabeza==NULL || queueOriginal->rabo==NULL){
        estaVacia = true;
    }
    return estaVacia;
}
// Regresar el valor del nodo.
void * queueRevisarNodo(QueueNodo *queueOriginal, DISPLAY fdisp){
    // if (queueEstaVacia(queueOriginal)) return NULL;

    ValorNodo * valorTemp;
    if (queueOriginal->valor!=NULL)
            valorTemp = queueOriginal->valor;
    
    
    fdisp(valorTemp);
    
    return valorTemp;  
};

Queue* queueAlloc(){
    return malloc(sizeof(Queue));
}
Queue* queueInit(Queue *queueOriginal){
    if (queueEsNull(queueOriginal)) return NULL;

    queueOriginal->cabeza =NULL;
    queueOriginal->rabo =NULL;
    queueOriginal->elementos =0;
    queueOriginal->freeFunctionNodeValue =NULL;
    return queueOriginal;
}
Queue* newQueue(){
    return queueInit(queueAlloc());
}

void queuePush(Queue *queueOriginal,  ValorNodo *valorNuevo){
    if (queueEsNull(queueOriginal)) return;

    QueueNodo *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodo));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->siguiente =NULL;
  
    queueOriginal->elementos++;
    if (queueOriginal->rabo==NULL)
    {
        queueOriginal->rabo = nuevoNodo;
        queueOriginal->cabeza = nuevoNodo;
        
    }else{
        queueOriginal->rabo->siguiente = nuevoNodo;
        queueOriginal->rabo = nuevoNodo;
        
    }
    
    
    
};


void *  queuePop(Queue *queueOriginal){

    void * valorTemp = NULL;
   if (!queueEstaVacia(queueOriginal)){

    queueOriginal->elementos--;
    valorTemp = queueOriginal->cabeza->valor;

    // SI estan apuntando lo mismo, eliminar.
    if (queueOriginal->rabo == queueOriginal->cabeza)
    {
        queueOriginal->cabeza = queueOriginal->rabo = NULL;
    }
    else{
        queueOriginal->cabeza = queueOriginal->cabeza->siguiente;
    }
    
   }
   if(queueOriginal->freeFunctionNodeValue!=NULL){
       queueOriginal->freeFunctionNodeValue(valorTemp);
   }

    return valorTemp;    

};


void queueIterar(Queue *queueOriginal, DISPLAY fDisplay){
    if((queueOriginal)==NULL) 
        return;

    if(!queueEstaVacia(queueOriginal)) 
    {
        
        QueueNodo * nodoTemporal;
        nodoTemporal = queueOriginal->cabeza;
        
        while (nodoTemporal!=NULL)
        {
            printf("\n");
            queueRevisarNodo(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->siguiente;

        }
        
    }
 
    
}