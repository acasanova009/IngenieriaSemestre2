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

typedef struct {
    ListaNodo * cabeza;
    ListaNodo * rabo;

    int cantidadDeNodos;

}ListaDoble;






ListaDoble* listaDobleInicializar(ListaDoble *listaDobleOriginal){
    ListaDoble *listaNueva = malloc(sizeof(ListaDoble));
    

    (listaDobleOriginal) = listaNueva;
    (listaDobleOriginal)->cantidadDeNodos = 0;
    (listaDobleOriginal)->cabeza =  NULL; 
    (listaDobleOriginal)->rabo =  NULL; 

    return listaNueva;

};

bool listaDobleEstaVacia(ListaDoble **listaDobleOriginal){
    bool esVacia = false;
    if ((*listaDobleOriginal)->cabeza == NULL && (*listaDobleOriginal)->rabo==NULL){ 
        esVacia = true;
    }
    return esVacia;
}
void listaDobleAgregarInicio(ListaDoble **listaDobleOriginal, ListaValor *valor){
    // if((*listaDobleOriginal)->cabeza==NULL)
    // return;
    
    ListaNodo *nodoEnCabeza = (*listaDobleOriginal)->cabeza;
    ListaNodo *nodoPorAgregar = malloc(sizeof(ListaNodo));

    nodoPorAgregar->valor = valor;

   
    if (listaDobleEstaVacia(listaDobleOriginal))
    {
        nodoPorAgregar->derecha = NULL;
        nodoPorAgregar->izquierda = NULL;
        
        (*listaDobleOriginal)->cabeza =  nodoPorAgregar; 
        (*listaDobleOriginal)->rabo =  nodoPorAgregar; 


    }
    // Si tiene al menos 1 elemento.
    else{
        nodoPorAgregar->derecha = nodoEnCabeza;
        nodoPorAgregar->izquierda = NULL;
        nodoEnCabeza->izquierda = nodoPorAgregar;
        (*listaDobleOriginal)->cabeza =  nodoPorAgregar; 


    }

    (*listaDobleOriginal)->cantidadDeNodos+=1;

}

void listaDobleEliminarInicio(ListaDoble **listaDobleOriginal){

    if((*listaDobleOriginal)->cabeza==NULL)
    return;
    ListaNodo *nodoCabeza = (*listaDobleOriginal)->cabeza;
    ListaNodo *nodoRabo = (*listaDobleOriginal)->rabo;
    if (nodoCabeza == nodoRabo)
    {
        //Caso 1
        
        (*listaDobleOriginal)->rabo = NULL;
        (*listaDobleOriginal)->cabeza = NULL;

        // Falta liberar correctamente la memoria del nodo que dejamos de apuntar



    }else
    {
        (*listaDobleOriginal)->cabeza = (*listaDobleOriginal)->cabeza->derecha;
        (*listaDobleOriginal)->cabeza->izquierda = NULL;

    }
    

}

void listaDobleIterar(ListaDoble **listaDobleOriginal, DISPLAY display){
    ListaNodo *iterador = (*listaDobleOriginal)->cabeza;
    
    if (!listaDobleEstaVacia(listaDobleOriginal))
    {
        while(iterador){
            display(iterador->valor);
            iterador = iterador->derecha;
        }
    }
}


void toString(ListaDoble **listaDobleOriginal, DISPLAY display){

    
    

}
