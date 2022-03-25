
#include <stdlib.h>
#include <stdio.h>


#include "filaCircular.h"

bool iteradorEsNull(QueueNodoCircular *iterador){
    bool esNull = false;
    if(iterador==NULL)
        esNull = true;
    return esNull;
}
bool iteradorTieneDerecha(QueueNodoCircular *iterador){
    bool tieneDerecha = false;
    if (iteradorEsNull(iterador)) return false;
    
    if(iterador->derecha!=NULL){
        tieneDerecha = true;
    }
    return tieneDerecha;
}
bool iteradorTieneIzquierda(QueueNodoCircular *iterador){
    bool tieneIzquierda = false;
    if (iteradorEsNull(iterador)) return false;
    
    if(iterador->izquierda!=NULL)
        tieneIzquierda = true;
    return tieneIzquierda;
}

void iteradorMoverADerecha(QueueNodoCircular **iterador){
    if(!iteradorTieneDerecha(*iterador)) return;

    (*iterador) = (*iterador)->derecha;
}
void iteradorMoverAIzquierda(QueueNodoCircular **iterador){
     if(!iteradorTieneIzquierda(*iterador)) return;

    (*iterador) = (*iterador)->izquierda;

}

void * iteradorFilaCircularDisplayValue(QueueNodoCircular *iterador, DISPLAY fdisp){
    if (iteradorEsNull(iterador)) return NULL;
    void * valorTemp =  iterador->valor;

    fdisp(valorTemp);

    return valorTemp;


}

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
        filaCircular->cabeza = nuevoNodo;
        filaCircular->rabo = nuevoNodo;

        //Extra por cola circular 

        nuevoNodo->derecha = nuevoNodo;
        nuevoNodo->izquierda = nuevoNodo;
        
    }else{

        nuevoNodo->derecha =filaCircular->cabeza;
        nuevoNodo->izquierda = filaCircular->rabo;

        filaCircular->cabeza->izquierda = nuevoNodo;
        filaCircular->rabo->derecha = nuevoNodo;

        
        filaCircular->cabeza = nuevoNodo;
    }
    
    
    
};


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
        nuevoNodo->derecha = filaCircular->cabeza;

        filaCircular->rabo->derecha = nuevoNodo;
        filaCircular->cabeza->izquierda = nuevoNodo;


        filaCircular->rabo = nuevoNodo;

        
    }
    
    
    
};


void *  filaCircularPopTop(FilaCircular *filaCircular){

    QueueNodoCircular * nodoToFree;
    void * valorTemp = NULL;
   if (!filaCircularEstaVacia(filaCircular)){

    filaCircular->elementos--;
    valorTemp = filaCircular->cabeza->valor;
    nodoToFree = filaCircular->cabeza;
    // SI estan apuntando lo mismo, eliminar.
    if (filaCircular->rabo == filaCircular->cabeza)
    {
        
        filaCircular->cabeza = filaCircular->rabo = NULL;
    }
    else{

        filaCircular->cabeza = filaCircular->cabeza->derecha;
        filaCircular->cabeza->izquierda = filaCircular->rabo;   
        filaCircular->rabo->derecha = filaCircular->cabeza;   
        
    }
    


   }

    free(nodoToFree);

    return valorTemp;    

};
void *  filaCircularPopEnd(FilaCircular *filaCircular){
     QueueNodoCircular * nodoToFree;
    void * valorTemp = NULL;
   if (!filaCircularEstaVacia(filaCircular)){

    filaCircular->elementos--;
    valorTemp = filaCircular->rabo->valor;
     nodoToFree = filaCircular->rabo;

    // SI estan apuntando lo mismo, eliminar.
    if (filaCircular->rabo == filaCircular->cabeza)
    {
        filaCircular->cabeza = filaCircular->rabo = NULL;
    }
    else{
        filaCircular->rabo = filaCircular->rabo->izquierda;
        filaCircular->rabo->derecha = filaCircular->cabeza;   
        filaCircular->cabeza->izquierda = filaCircular->rabo;   
    }
    
   }

   free(nodoToFree);
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
            iteradorFilaCircularDisplayValue(nodoTemporal, fDisplay);
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
            // printf("\n");
            iteradorFilaCircularDisplayValue(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->izquierda;

            if(nodoTemporal==filaCircular->cabeza->izquierda) return;

        }
        
    }
 
    
}