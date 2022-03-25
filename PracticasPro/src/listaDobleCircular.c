
#include <string.h>
#include <stdlib.h>

#include "listaDobleCircular.h"

bool listaDobleCircularEsNull(ListaDobleCircular * ld){
    bool esNull = false;
    if (ld == NULL)
         esNull = true;
    
    return esNull;
}


bool listaDobleCircularEstaVacia(ListaDobleCircular *ld){
    bool esVacia = false;
    if ((ld)->cabeza == NULL || (ld)->rabo==NULL){ 
        esVacia = true;
    }
    return esVacia;
}

ListaDobleCircular* listaDobleCircularAlloc(){
    return malloc(sizeof(ListaDobleCircular));    
}

ListaDobleCircular* listaDobleCircularInit(ListaDobleCircular *ld){
    if(listaDobleCircularEsNull(ld))return NULL;
    
    ld->longitud = 0;
    ld->cabeza =  NULL; 
    ld->rabo =  NULL; 
    
    return ld;

}


ListaDobleCircular * newListaDobleCircular(){
    return listaDobleCircularInit(listaDobleCircularAlloc());
}


// void listaDobleCircularAgregarFinal()

void listaDobleCircularVaciaAgregar(ListaDobleCircular *ld, Nodo * nuevoNodo){
    if(listaDobleCircularEsNull(ld))return;
    if (listaDobleCircularEstaVacia(ld))
    {
        (ld)->cabeza =  nuevoNodo; 
        (ld)->rabo =  nuevoNodo; 

        nuevoNodo->derecha = nuevoNodo;
        nuevoNodo->izquierda = nuevoNodo;
        
    }

    (ld)->longitud+=1;

}
void listaDobleCircularAgregarInicio(ListaDobleCircular *ld, Valor *valor){

    if(listaDobleCircularEsNull(ld))return;
    
    Nodo *nuevoNodo = newNodo(valor, NULL, NULL);

    if(listaDobleCircularEstaVacia(ld)){
        listaDobleCircularVaciaAgregar(ld, nuevoNodo);
    }
    else{
        nuevoNodo->derecha = ld->cabeza;
        nuevoNodo->izquierda = ld->rabo;

        ld->cabeza->izquierda = nuevoNodo;
        ld->rabo->derecha = nuevoNodo;

        ld->cabeza =  nuevoNodo; 
         (ld)->longitud+=1;
    }
    

    return;

}
void ListaDobleCircularAgregarFinal(ListaDobleCircular *ld, Valor *valor){
    if(listaDobleCircularEsNull(ld))return;
    
    Nodo *nuevoNodo = newNodo(valor, NULL, NULL);

    if(listaDobleCircularEstaVacia(ld)){
        listaDobleCircularVaciaAgregar(ld, nuevoNodo);
    }
    else{
        nuevoNodo->izquierda = ld->rabo;
        nuevoNodo->derecha = ld->cabeza;

        ld->rabo->derecha = nuevoNodo;
        ld->cabeza->izquierda = nuevoNodo;

        ld->rabo =  nuevoNodo; 
        (ld)->longitud+=1;
    }
    
    return;

}
void* listaDobleCircularDesconectarNodo(ListaDobleCircular *ld, Nodo * nodoPorDesconectar){

    void* valorNodo = nodoPorDesconectar->valor;
    // Caso unitario. Facil.
    if (ld->cabeza == ld->rabo)
    {
        (ld)->rabo = NULL;
        (ld)->cabeza = NULL;

    }else if(ld->cabeza == nodoPorDesconectar)
    {   
        //Estamos borrando la cabeza
        (ld)->cabeza = (ld)->cabeza->derecha;
        (ld)->cabeza->izquierda = ld->rabo;
        ld->rabo->derecha = ld->cabeza;

    }else if(ld->rabo == nodoPorDesconectar){
        //Estamos desconectando el rabo
        (ld)->rabo = (ld)->rabo->izquierda;
        (ld)->rabo->derecha = ld->cabeza;
        (ld)->cabeza->izquierda = ld->rabo;

    }else{
        // Estamos desconectando a la mitad
        if(nodoTieneDerecha(nodoPorDesconectar)&&nodoTieneIzquierda(nodoPorDesconectar)){

        nodoPorDesconectar->izquierda->derecha =nodoPorDesconectar->derecha;
        nodoPorDesconectar->derecha->izquierda =nodoPorDesconectar->izquierda;
        }
        
    }
    ld->longitud-=1;

    free(nodoPorDesconectar);

    return valorNodo;
    

}

void* listaDobleCircularEliminarInicio(ListaDobleCircular *ld){
    return listaDobleCircularDesconectarNodo(ld, ld->cabeza);
}
void* listaDobleCircularEliminarFinal(ListaDobleCircular *ld){
    return listaDobleCircularDesconectarNodo(ld, ld->rabo);
}

bool listaDobleCircularContiene(ListaDobleCircular *ld, Valor* valor ,COMPARE fCompare){
    if (listaDobleCircularEsNull(ld))return false;
    
    
    Nodo *iterador = (ld)->cabeza;
    bool contieneAlElemento = false;
    
    if (!listaDobleCircularEstaVacia(ld))
    {
        while(iterador){
            if(fCompare(iterador->valor, valor)==0){
                contieneAlElemento = true;
                break;
            }
             nodoMoverADerecha(&iterador);
        }
    }
    return contieneAlElemento;
}
void * listaDobleCircularGetValorByIndex(ListaDobleCircular *ld, int index){

    if (listaDobleCircularEsNull(ld))return NULL;
    if (index<0 || index>=ld->longitud)return NULL;

    Nodo *iterador = (ld)->cabeza;
    int contador =0;

    while (contador<index){
         
        nodoMoverADerecha(&iterador);
        contador++;
    }
    return iterador->valor;

}

void listaDobleCircularDisplay(ListaDobleCircular *ld, DISPLAY display){
     if (listaDobleCircularEsNull(ld))return;
    Nodo *iterador = (ld)->cabeza;
    
    if (!listaDobleCircularEstaVacia(ld))
    {
        while(iterador!=NULL){
              
            nodoDisplayValor(iterador, display);
            nodoMoverADerecha(&iterador);
            if(iterador==ld->rabo->derecha) return;
        }
    }
}



bool listaDobleCircularEliminarValor(ListaDobleCircular *ld, Valor *valor){
    
    if (listaDobleCircularEstaVacia(ld))return false;
    if (valor==NULL)return false;
    


    bool pudoEliminar = false;
    Nodo *iterador = (ld)->cabeza;
    
    while(iterador){
        
        if (iterador->valor == valor)
        {  
            if(listaDobleCircularDesconectarNodo(ld, iterador)!=NULL){
                pudoEliminar = true;
            }
            
           break;
        }
        
        nodoMoverADerecha(&iterador);
         

    }

    return pudoEliminar;
    
}

    
