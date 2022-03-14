#include <stdbool.h>
#include <stdlib.h>
#include "global.h"

typedef void ValorNodo;
typedef struct _queueNodoDoble QueueNodoDoble;


struct _queueNodoDoble{
    ValorNodo *valor;
    QueueNodoDoble *derecha;
    QueueNodoDoble *izquierda;
};
typedef struct{

    QueueNodoDoble *cabeza;
    QueueNodoDoble *rabo;
    int elementos;
    FREE freeFunctionNodeValue;


}QueueDoble;

bool queueDobleEsNull(QueueDoble *queueDobleOriginal){
    bool esNull = false;
    if (queueDobleOriginal==NULL)
        esNull = true;
    return esNull;
}
void queueDobleSetFreeFunctionForNodeValues(QueueDoble *queueDobleOriginal, FREE newFreeFunctionNodeValue){
    if (queueDobleEsNull(queueDobleOriginal)) return;

    queueDobleOriginal->freeFunctionNodeValue = newFreeFunctionNodeValue;
    

}
bool queueDobleEstaVacia(QueueDoble *queueDobleOriginal){
     if (queueDobleEsNull(queueDobleOriginal)) return true;
        
    bool estaVacia = false;
    if (queueDobleOriginal->cabeza==NULL || queueDobleOriginal->rabo==NULL){
        estaVacia = true;
    }
    return estaVacia;
}
// Regresar el valor del nodo.
void * queueDobleRevisarNodo(QueueNodoDoble *queueDobleOriginal, DISPLAY fdisp){
    // if (queueDobleEstaVacia(queueDobleOriginal)) return NULL;

    ValorNodo * valorTemp;
    if (queueDobleOriginal->valor!=NULL)
            valorTemp = queueDobleOriginal->valor;
    
    
    fdisp(valorTemp);
    
    return valorTemp;  
};

QueueDoble* queueDobleAlloc(){
    return malloc(sizeof(QueueDoble));
}
QueueDoble* queueDobleInit(QueueDoble *queueDobleOriginal){
    if (queueDobleEsNull(queueDobleOriginal)) return NULL;

    queueDobleOriginal->cabeza =NULL;
    queueDobleOriginal->rabo =NULL;
    queueDobleOriginal->elementos =0;
    queueDobleOriginal->freeFunctionNodeValue =NULL;
    return queueDobleOriginal;
}
QueueDoble* newQueueDoble(){
    return queueDobleInit(queueDobleAlloc());
}

void queueDoblePushEnd(QueueDoble *queueDobleOriginal,  ValorNodo *valorNuevo){
    if (queueDobleEsNull(queueDobleOriginal)) return;

    QueueNodoDoble *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodoDoble));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->derecha =NULL;
    nuevoNodo->izquierda =NULL;
  
    queueDobleOriginal->elementos++;
    if (queueDobleOriginal->rabo==NULL)
    {
        queueDobleOriginal->rabo = nuevoNodo;
        queueDobleOriginal->cabeza = nuevoNodo;
        
    }else{

        nuevoNodo->izquierda =queueDobleOriginal->rabo;
        queueDobleOriginal->rabo->derecha = nuevoNodo;
        queueDobleOriginal->rabo = nuevoNodo;
        
    }
    
    
    
};
void queueDoblePushTop(QueueDoble *queueDobleOriginal,  ValorNodo *valorNuevo){
    if (queueDobleEsNull(queueDobleOriginal)) return;

    QueueNodoDoble *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodoDoble));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->derecha =NULL;
    nuevoNodo->izquierda =NULL;
  
    queueDobleOriginal->elementos++;
    if (queueDobleOriginal->rabo==NULL)
    {
        queueDobleOriginal->rabo = nuevoNodo;
        queueDobleOriginal->cabeza = nuevoNodo;
        
    }else{

        nuevoNodo->derecha =queueDobleOriginal->cabeza;
        queueDobleOriginal->cabeza->izquierda = nuevoNodo;
        queueDobleOriginal->cabeza = nuevoNodo;
        
    }
    
    
    
};


void *  queueDoblePopTop(QueueDoble *queueDobleOriginal){

    void * valorTemp = NULL;
   if (!queueDobleEstaVacia(queueDobleOriginal)){

    queueDobleOriginal->elementos--;
    valorTemp = queueDobleOriginal->cabeza->valor;

    // SI estan apuntando lo mismo, eliminar.
    if (queueDobleOriginal->rabo == queueDobleOriginal->cabeza)
    {
        queueDobleOriginal->cabeza = queueDobleOriginal->rabo = NULL;
    }
    else{
        queueDobleOriginal->cabeza = queueDobleOriginal->cabeza->derecha;
        queueDobleOriginal->cabeza->izquierda = NULL;   
    }
    
   }
   if(queueDobleOriginal->freeFunctionNodeValue!=NULL){
       queueDobleOriginal->freeFunctionNodeValue(valorTemp);
   }

    return valorTemp;    

};
void *  queueDoblePopEnd(QueueDoble *queueDobleOriginal){

    void * valorTemp = NULL;
   if (!queueDobleEstaVacia(queueDobleOriginal)){

    queueDobleOriginal->elementos--;
    valorTemp = queueDobleOriginal->rabo->valor;

    // SI estan apuntando lo mismo, eliminar.
    if (queueDobleOriginal->rabo == queueDobleOriginal->cabeza)
    {
        queueDobleOriginal->cabeza = queueDobleOriginal->rabo = NULL;
    }
    else{
        queueDobleOriginal->rabo = queueDobleOriginal->rabo->izquierda;
        queueDobleOriginal->rabo->derecha = NULL;   
    }
    
   }
   if(queueDobleOriginal->freeFunctionNodeValue!=NULL){
       queueDobleOriginal->freeFunctionNodeValue(valorTemp);
   }

    return valorTemp;    

};


void queueDobleIterarFromTop(QueueDoble *queueDobleOriginal, DISPLAY fDisplay){
    if((queueDobleOriginal)==NULL) 
        return;

    if(!queueDobleEstaVacia(queueDobleOriginal)) 
    {
        
        QueueNodoDoble * nodoTemporal;
        nodoTemporal = queueDobleOriginal->cabeza;
        
        while (nodoTemporal!=NULL)
        {
            printf("\n");
            queueDobleRevisarNodo(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->derecha;

        }
        
    }
 
    
}
void queueDobleIterarFromEnd(QueueDoble *queueDobleOriginal, DISPLAY fDisplay){
    if((queueDobleOriginal)==NULL) 
        return;

    if(!queueDobleEstaVacia(queueDobleOriginal)) 
    {
        
        QueueNodoDoble * nodoTemporal;
        nodoTemporal = queueDobleOriginal->rabo;
        
        while (nodoTemporal!=NULL)
        {
            printf("\n");
            queueDobleRevisarNodo(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->izquierda;

        }
        
    }
 
    
}