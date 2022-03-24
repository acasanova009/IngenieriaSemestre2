#include "nodo.h"
#include <stdlib.h>
void* newNodo(Valor *valor,  Nodo *izquierda, Nodo *derecha){
    Nodo *theNewNodo = malloc(sizeof(Nodo));

    theNewNodo->izquierda =izquierda;
    theNewNodo->derecha =derecha;
    theNewNodo->valor =valor;
    
    return theNewNodo;
}

bool nodoEsNull(Nodo *nodo){
    bool esNull = false;
    if(nodo==NULL)
        esNull = true;
    return esNull;
}
bool nodoTieneDerecha(Nodo *nodo){
    bool tieneDerecha = false;
    if (nodoEsNull(nodo)) return false;
    
    if(nodo->derecha!=NULL){
        tieneDerecha = true;
    }
    return tieneDerecha;
}
bool nodoTieneIzquierda(Nodo *nodo){
    bool tieneIzquierda = false;
    if (nodoEsNull(nodo)) return false;
    
    if(nodo->izquierda!=NULL)
        tieneIzquierda = true;
    return tieneIzquierda;
}

bool valorEsNull(Valor * nodo){
    bool esNull = false;
    if(nodo==NULL)
        esNull = true;
    return esNull;
}

bool nodoCompareValueWithAnotherValue(Nodo *nodo, COMPARE fCompare , Valor * valor){
    bool isEqual = false;
    if (nodoEsNull(nodo)) return false;

    if (fCompare(nodo->valor, valor)==0)
        isEqual = true;
    
    return isEqual;
}

void nodoMoverADerecha(Nodo **nodo){
    // if(!nodoTieneDerecha(*nodo)) return;
    (*nodo) = (*nodo)->derecha;
}
void nodoMoverAIzquierda(Nodo **nodo){
    //  if(!nodoTieneIzquierda(*nodo)) return;

    (*nodo) = (*nodo)->izquierda;

}


void nodoDisplayValor(Nodo *nodo, DISPLAY fdisp){
    if (nodoEsNull(nodo)) return;
    void * valorTemp =  nodo->valor;
    fdisp(valorTemp);
    
}
void* nodoGetValor(Nodo *nodo){
    if (nodoEsNull(nodo)) return NULL;
    void * valorTemp =  nodo->valor;
    return valorTemp;

}

