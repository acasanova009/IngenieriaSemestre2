
#include <stdlib.h>
#include <stdio.h>


#include "filaCircular.h"

bool filaCircularEsNull(FilaCircular *filaCircular){
    bool esNull = false;
    if (filaCircular==NULL)
        esNull = true;
    return esNull;
}
void filaCircularSetFreeFunctionForNodeValues(FilaCircular *filaCircular, FREE newFreeFunctionNodeValue){
    if (filaCircularEsNull(filaCircular)) return;

    filaCircular->freeFunctionNodeValue = newFreeFunctionNodeValue;
    
}
bool filaCircularEstaVacia(FilaCircular *filaCircular){
     if (filaCircularEsNull(filaCircular)) return true;
        
    bool estaVacia = false;
    if (filaCircular->cabeza==NULL || filaCircular->rabo==NULL){
        estaVacia = true;
    }
    return estaVacia;
}
// Regresar el valor del nodo.
void * filaCircularRevisarNodo(QueueNodoCircular *filaCircular, DISPLAY fdisp){
    // if (filaDobleEstaVacia(filaCircular)) return NULL;

    ValorNodo * valorTemp;
    if (filaCircular->valor!=NULL)
            valorTemp = filaCircular->valor;
    
    
    fdisp(valorTemp);
    
    return valorTemp;  
};

FilaCircular* filaCircularAlloc(){
    return malloc(sizeof(FilaCircular));
}
FilaCircular* filaCircularInit(FilaCircular *filaCircular){
    if (filaCircularEsNull(filaCircular)) return NULL;

    filaCircular->cabeza =NULL;
    filaCircular->rabo =NULL;
    filaCircular->elementos =0;
    filaCircular->freeFunctionNodeValue =NULL;
    return filaCircular;
}
FilaCircular* newFilaCircular(){
    return filaCircularInit(filaCircularAlloc());
}

void filaCircularPushEnd(FilaCircular *filaCircular,  ValorNodo *valorNuevo){
    if (filaCircularEsNull(filaCircular)) return;

    QueueNodoCircular *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodoCircular));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->derecha =NULL;
    nuevoNodo->izquierda =NULL;
  
    filaCircular->elementos++;
    if (filaCircularEstaVacia(filaCircular))
    {
        filaCircular->rabo = nuevoNodo;
        filaCircular->cabeza = nuevoNodo;

        //Extra por cola circular 

        nuevoNodo->derecha = nuevoNodo;
        nuevoNodo->izquierda = nuevoNodo;

        
    }else{

        nuevoNodo->izquierda =filaCircular->rabo;
        filaCircular->rabo->derecha = nuevoNodo;
        filaCircular->rabo = nuevoNodo;


        // Extra por cola circular
        nuevoNodo->derecha = filaCircular->cabeza;
        filaCircular->cabeza->izquierda = nuevoNodo;


        
    }
    
    
    
};
void filaCircularPushTop(FilaCircular *filaCircular,  ValorNodo *valorNuevo){
    if (filaCircularEsNull(filaCircular)) return;

    QueueNodoCircular *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodoCircular));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->derecha =NULL;
    nuevoNodo->izquierda =NULL;
  
    filaCircular->elementos++;
    if (filaCircular->rabo==NULL)
    {
        filaCircular->rabo = nuevoNodo;
        filaCircular->cabeza = nuevoNodo;

        //Extra por cola circular 

        nuevoNodo->derecha = nuevoNodo;
        nuevoNodo->izquierda = nuevoNodo;
        
    }else{

        nuevoNodo->derecha =filaCircular->cabeza;
        filaCircular->cabeza->izquierda = nuevoNodo;
        filaCircular->cabeza = nuevoNodo;

        // Extra por cola circular
        nuevoNodo->izquierda = filaCircular->rabo;
        filaCircular->rabo->derecha = nuevoNodo;
        
    }
    
    
    
};


void *  filaCircularPopTop(FilaCircular *filaCircular){

    void * valorTemp = NULL;
   if (!filaCircularEstaVacia(filaCircular)){

    filaCircular->elementos--;
    valorTemp = filaCircular->cabeza->valor;

    // SI estan apuntando lo mismo, eliminar.
    if (filaCircular->rabo == filaCircular->cabeza)
    {
        filaCircular->cabeza = filaCircular->rabo = NULL;
    }
    else{
        filaCircular->cabeza = filaCircular->cabeza->derecha;
        filaCircular->cabeza->izquierda = NULL;   
    }
    
   }
   if(filaCircular->freeFunctionNodeValue!=NULL){
       filaCircular->freeFunctionNodeValue(valorTemp);
   }

    return valorTemp;    

};
void *  filaCircularPopEnd(FilaCircular *filaCircular){

    void * valorTemp = NULL;
   if (!filaCircularEstaVacia(filaCircular)){

    filaCircular->elementos--;
    valorTemp = filaCircular->rabo->valor;

    // SI estan apuntando lo mismo, eliminar.
    if (filaCircular->rabo == filaCircular->cabeza)
    {
        filaCircular->cabeza = filaCircular->rabo = NULL;
    }
    else{
        filaCircular->rabo = filaCircular->rabo->izquierda;
        filaCircular->rabo->derecha = NULL;   
    }
    
   }
   if(filaCircular->freeFunctionNodeValue!=NULL){
       filaCircular->freeFunctionNodeValue(valorTemp);
   }

    return valorTemp;    

};


void filaCircularIterarFromTop(FilaCircular *filaCircular, DISPLAY fDisplay){
    if((filaCircular)==NULL) 
        return;

    if(!filaCircularEstaVacia(filaCircular)) 
    {
        
        QueueNodoCircular * nodoTemporal;
        nodoTemporal = filaCircular->cabeza;
        
        while (nodoTemporal!=NULL)
        {
            
            // printf("\n");
            filaCircularRevisarNodo(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->derecha;
            
            if(nodoTemporal==filaCircular->rabo->derecha) return;
        }
        
    }
 
    
}
void filaCircularIterarFromEnd(FilaCircular *filaCircular, DISPLAY fDisplay){
    if((filaCircular)==NULL) 
        return;

    if(!filaCircularEstaVacia(filaCircular)) 
    {
        
        QueueNodoCircular * nodoTemporal;
        nodoTemporal = filaCircular->rabo;
        
        while (nodoTemporal!=NULL)
        {
            printf("\n");
            filaCircularRevisarNodo(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->izquierda;

            if(nodoTemporal==filaCircular->cabeza->izquierda) return;

        }
        
    }
 
    
}