
#include <stdlib.h>
#include <stdio.h>


#include "filaDoble.h"

bool filaDobleEsNull(FilaDoble *filaDobleOriginal){
    bool esNull = false;
    if (filaDobleOriginal==NULL)
        esNull = true;
    return esNull;
}
void filaDobleSetFreeFunctionForNodeValues(FilaDoble *filaDobleOriginal, FREE newFreeFunctionNodeValue){
    if (filaDobleEsNull(filaDobleOriginal)) return;

    filaDobleOriginal->freeFunctionNodeValue = newFreeFunctionNodeValue;
    

}
bool filaDobleEstaVacia(FilaDoble *filaDobleOriginal){
     if (filaDobleEsNull(filaDobleOriginal)) return true;
        
    bool estaVacia = false;
    if (filaDobleOriginal->cabeza==NULL || filaDobleOriginal->rabo==NULL){
        estaVacia = true;
    }
    return estaVacia;
}
// Regresar el valor del nodo.
void * filaDobleRevisarNodo(QueueNodoDoble *filaDobleOriginal, DISPLAY fdisp){
    // if (filaDobleEstaVacia(filaDobleOriginal)) return NULL;

    ValorNodo * valorTemp;
    if (filaDobleOriginal->valor!=NULL)
            valorTemp = filaDobleOriginal->valor;
    
    
    fdisp(valorTemp);
    
    return valorTemp;  
};

FilaDoble* filaDobleAlloc(){
    return malloc(sizeof(FilaDoble));
}
FilaDoble* filaDobleInit(FilaDoble *filaDobleOriginal){
    if (filaDobleEsNull(filaDobleOriginal)) return NULL;

    filaDobleOriginal->cabeza =NULL;
    filaDobleOriginal->rabo =NULL;
    filaDobleOriginal->elementos =0;
    filaDobleOriginal->freeFunctionNodeValue =NULL;
    return filaDobleOriginal;
}
FilaDoble* newFilaDoble(){
    return filaDobleInit(filaDobleAlloc());
}

void filaDoblePushEnd(FilaDoble *filaDobleOriginal,  ValorNodo *valorNuevo){
    if (filaDobleEsNull(filaDobleOriginal)) return;

    QueueNodoDoble *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodoDoble));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->derecha =NULL;
    nuevoNodo->izquierda =NULL;
  
    filaDobleOriginal->elementos++;
    if (filaDobleOriginal->rabo==NULL)
    {
        filaDobleOriginal->rabo = nuevoNodo;
        filaDobleOriginal->cabeza = nuevoNodo;
        
    }else{

        nuevoNodo->izquierda =filaDobleOriginal->rabo;
        filaDobleOriginal->rabo->derecha = nuevoNodo;
        filaDobleOriginal->rabo = nuevoNodo;
        
    }
    
    
    
};
void filaDoblePushTop(FilaDoble *filaDobleOriginal,  ValorNodo *valorNuevo){
    if (filaDobleEsNull(filaDobleOriginal)) return;

    QueueNodoDoble *nuevoNodo;
    
    nuevoNodo = malloc(sizeof(QueueNodoDoble));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->derecha =NULL;
    nuevoNodo->izquierda =NULL;
  
    filaDobleOriginal->elementos++;
    if (filaDobleOriginal->rabo==NULL)
    {
        filaDobleOriginal->rabo = nuevoNodo;
        filaDobleOriginal->cabeza = nuevoNodo;
        
    }else{

        nuevoNodo->derecha =filaDobleOriginal->cabeza;
        filaDobleOriginal->cabeza->izquierda = nuevoNodo;
        filaDobleOriginal->cabeza = nuevoNodo;
        
    }
    
    
    
};
void filaPushOrdenadamente(FilaDoble *filaDobleOriginal, ValorNodo *valorNuevo, COMPARE fCompare){
    

     if (filaDobleEsNull(filaDobleOriginal)) return;

    QueueNodoDoble *nuevoNodo;
    QueueNodoDoble *iteradorNodo = filaDobleOriginal->cabeza;
    
    nuevoNodo = malloc(sizeof(QueueNodoDoble));
    nuevoNodo->valor = valorNuevo;
    nuevoNodo->derecha =NULL;
    nuevoNodo->izquierda =NULL;

  
    filaDobleOriginal->elementos++;
    if (filaDobleOriginal->rabo==NULL)
    {
        filaDobleOriginal->rabo = nuevoNodo;
        filaDobleOriginal->cabeza = nuevoNodo;
        
    }else{

        while (iteradorNodo!=NULL)
        {
            if(fCompare(valorNuevo, iteradorNodo->valor)>0){
                iteradorNodo = iteradorNodo->derecha;
            }
            else{
                break;
            }
        }


        if (iteradorNodo==filaDobleOriginal->cabeza)
        {
            nuevoNodo->derecha = filaDobleOriginal->cabeza;
            filaDobleOriginal->cabeza->izquierda = nuevoNodo;
            filaDobleOriginal->cabeza = nuevoNodo;

        }else if(iteradorNodo==NULL){
            nuevoNodo->izquierda = filaDobleOriginal->rabo;
            filaDobleOriginal->rabo->derecha = nuevoNodo;
            filaDobleOriginal->rabo = nuevoNodo;


        }else {
            nuevoNodo->izquierda = iteradorNodo->izquierda;
            nuevoNodo->derecha = iteradorNodo;

            iteradorNodo->izquierda->derecha = nuevoNodo;
            iteradorNodo->izquierda = nuevoNodo;

        }
        

        
    }

}


void *  filaDoblePopTop(FilaDoble *filaDobleOriginal){

    void * valorTemp = NULL;
   if (!filaDobleEstaVacia(filaDobleOriginal)){

    filaDobleOriginal->elementos--;
    valorTemp = filaDobleOriginal->cabeza->valor;

    // SI estan apuntando lo mismo, eliminar.
    if (filaDobleOriginal->rabo == filaDobleOriginal->cabeza)
    {
        filaDobleOriginal->cabeza = filaDobleOriginal->rabo = NULL;
    }
    else{
        filaDobleOriginal->cabeza = filaDobleOriginal->cabeza->derecha;
        filaDobleOriginal->cabeza->izquierda = NULL;   
    }
    
   }
   if(filaDobleOriginal->freeFunctionNodeValue!=NULL){
       filaDobleOriginal->freeFunctionNodeValue(valorTemp);
   }

    return valorTemp;    

};
void *  filaDoblePopEnd(FilaDoble *filaDobleOriginal){

    void * valorTemp = NULL;
   if (!filaDobleEstaVacia(filaDobleOriginal)){

    filaDobleOriginal->elementos--;
    valorTemp = filaDobleOriginal->rabo->valor;

    // SI estan apuntando lo mismo, eliminar.
    if (filaDobleOriginal->rabo == filaDobleOriginal->cabeza)
    {
        filaDobleOriginal->cabeza = filaDobleOriginal->rabo = NULL;
    }
    else{
        filaDobleOriginal->rabo = filaDobleOriginal->rabo->izquierda;
        filaDobleOriginal->rabo->derecha = NULL;   
    }
    
   }
   if(filaDobleOriginal->freeFunctionNodeValue!=NULL){
       filaDobleOriginal->freeFunctionNodeValue(valorTemp);
   }

    return valorTemp;    

};


void filaDobleIterarFromTop(FilaDoble *filaDobleOriginal, DISPLAY fDisplay){
    if((filaDobleOriginal)==NULL) 
        return;

    if(!filaDobleEstaVacia(filaDobleOriginal)) 
    {
        
        QueueNodoDoble * nodoTemporal;
        nodoTemporal = filaDobleOriginal->cabeza;
        
        while (nodoTemporal!=NULL)
        {
            // printf("\n");
            filaDobleRevisarNodo(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->derecha;

        }
        
    }
 
    
}
void filaDobleIterarFromEnd(FilaDoble *filaDobleOriginal, DISPLAY fDisplay){
    if((filaDobleOriginal)==NULL) 
        return;

    if(!filaDobleEstaVacia(filaDobleOriginal)) 
    {
        
        QueueNodoDoble * nodoTemporal;
        nodoTemporal = filaDobleOriginal->rabo;
        
        while (nodoTemporal!=NULL)
        {
            printf("\n");
            filaDobleRevisarNodo(nodoTemporal, fDisplay);
            nodoTemporal = nodoTemporal->izquierda;

        }
        
    }
 
    
}