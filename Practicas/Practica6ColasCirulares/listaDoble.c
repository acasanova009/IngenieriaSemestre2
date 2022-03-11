#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.c"


typedef void ListaValor;
typedef struct _nodo  ListaNodo;
struct _nodo{
    ListaValor * valor;
    
    ListaNodo *derecha;
    ListaNodo *izquierda;

};

typedef void (*agregar)(void * ls, void*val);

typedef struct {
    ListaNodo * cabeza;
    ListaNodo * rabo;

    int cantidadDeNodos;

    agregar add;



}ListaDoble;




ListaDoble* listaDobleAlloc(){
    return malloc(sizeof(ListaDoble));    
}

ListaDoble* listaDobleInit(ListaDoble *listaDobleOriginal){
    
    listaDobleOriginal->cantidadDeNodos = 0;
    listaDobleOriginal->cabeza =  NULL; 
    listaDobleOriginal->rabo =  NULL; 
    listaDobleOriginal->add =  NULL; 
    
    return listaDobleOriginal;

}
ListaDoble * listaDobleAllocAndInit(){
    ListaDoble * listaNueva = listaDobleInit(listaDobleAlloc());
    return listaNueva;

}

ListaDoble * newListaDoble(){
    return listaDobleAllocAndInit();
}

bool listaDobleEsNull(ListaDoble * listaDoble){
    bool esNull = false;
    if (listaDoble == NULL)
         esNull = true;
    
    return esNull;
}


bool listaDobleEstaVacia(ListaDoble *listaDobleOriginal){
    bool esVacia = false;
    if ((listaDobleOriginal)->cabeza == NULL || (listaDobleOriginal)->rabo==NULL){ 
        esVacia = true;
    }
    return esVacia;
}
void listaDobleAgregarInicio(ListaDoble *listaDobleOriginal, ListaValor *valor){
    if(listaDobleEsNull(listaDobleOriginal))return;
    
    ListaNodo *nodoEnCabeza = (listaDobleOriginal)->cabeza;
    ListaNodo *nodoPorAgregar = malloc(sizeof(ListaNodo));

    nodoPorAgregar->valor = valor;

   
    if (listaDobleEstaVacia(listaDobleOriginal))
    {
        nodoPorAgregar->derecha = NULL;
        nodoPorAgregar->izquierda = NULL;
        
        (listaDobleOriginal)->cabeza =  nodoPorAgregar; 
        (listaDobleOriginal)->rabo =  nodoPorAgregar; 


    }
    // Si tiene al menos 1 elemento.
    else{
        nodoPorAgregar->derecha = nodoEnCabeza;
        nodoPorAgregar->izquierda = NULL;
        nodoEnCabeza->izquierda = nodoPorAgregar;
        (listaDobleOriginal)->cabeza =  nodoPorAgregar; 


    }

    (listaDobleOriginal)->cantidadDeNodos+=1;

}


void listaDobleEliminarInicio(ListaDoble *listaDobleOriginal){

    if((listaDobleOriginal)->cabeza==NULL)
    return;
    ListaNodo *nodoCabeza = (listaDobleOriginal)->cabeza;
    ListaNodo *nodoRabo = (listaDobleOriginal)->rabo;
    if (nodoCabeza == nodoRabo)
    {
        (listaDobleOriginal)->rabo = NULL;
        (listaDobleOriginal)->cabeza = NULL;

    }else
    {
        (listaDobleOriginal)->cabeza = (listaDobleOriginal)->cabeza->derecha;
        (listaDobleOriginal)->cabeza->izquierda = NULL;

    }
    

}

bool listaDobleContiene(ListaDoble *listaDobleOriginal,ListaValor* valor ,COMPARE fCompare){
    if (listaDobleEsNull(listaDobleOriginal))return false;
    
    
    ListaNodo *iterador = (listaDobleOriginal)->cabeza;
    bool contieneAlElemento = false;
    
    if (!listaDobleEstaVacia(listaDobleOriginal))
    {
        while(iterador){
            if(fCompare(iterador->valor, valor)==0){
                contieneAlElemento = true;
                break;
            }
            iterador = iterador->derecha;
        }
    }
    return contieneAlElemento;
}
void listaDobleIterar(ListaDoble *listaDobleOriginal, DISPLAY display){
    ListaNodo *iterador = (listaDobleOriginal)->cabeza;
    
    if (!listaDobleEstaVacia(listaDobleOriginal))
    {
        while(iterador){
            display(iterador->valor);
            iterador = iterador->derecha;
        }
    }
}


void displayListaDoble(ListaDoble *listaDobleOriginal, DISPLAY display){


}
