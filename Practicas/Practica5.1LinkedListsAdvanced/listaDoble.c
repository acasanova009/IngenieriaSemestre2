#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "global.c"


typedef void ListaValor;
typedef struct _nodo  ListaNodo;
struct _nodo{
    ListaValor * valorNodo;
    
    ListaNodo *derecha;
    ListaNodo *izquierda;

};

typedef struct {
    ListaNodo * cabeza;
    ListaNodo * cola;

    int cantidadDeNodos;

}ListaDoble;






void listaDobleInicializar(ListaDoble **listaDobleOriginal){
    ListaDoble *listaNueva = malloc(sizeof(ListaDoble));
    

    (*listaDobleOriginal) = listaNueva;
    (*listaDobleOriginal)->cantidadDeNodos = 0;
    (*listaDobleOriginal)->cabeza =  NULL; 
    (*listaDobleOriginal)->cola =  NULL; 

};

bool listaDobleEstaVacia(ListaDoble **listaDobleOriginal){
    bool esVacia = false;
    if ((*listaDobleOriginal)->cabeza == NULL && (*listaDobleOriginal)->rabo==NULL){ 
        esVacia = true;
    }
    return esVacia;
}
void listaDobleAgregarInicio(ListaDoble **listaDobleOriginal, ListaValor *valor){
    
    ListaNodo *nodoEnCabeza = (*listaDobleOriginal)->cabeza;
    ListaNodo *nodoPorAgregar = malloc(sizeof(ListaNodo));

    nodoPorAgregar->valorNodo = valor;

    // Si la lista esta vacia
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

void eliminarInicioListaDoble(ListaDoble **listaDobleOriginal){

    if((*listaDobleOriginal)->cabeza==NULL)
    return;
    ListaNodo *nodoCabeza = (*listaDobleOriginal)->cabeza;
    ListaNodo *nodoRabo = (*listaDobleOriginal)->rabo;
    if (nodoCabeza == rabo)
    {
        //Caso 1
        
        (*listaDobleOriginal)->cola = NULL;
        (*listaDobleOriginal)->cabeza = NULL;

        // Falta liberar correctamente la memoria del nodo extaviado



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
            display(&iterador->valor);
            iterador = iterador->derecha;
        }
    }
}


void toString(ListaDoble **listaDobleOriginal, DISPLAY display){
    for (bool isFirstLoop = true; iterarConFor(listaDobleOriginal, isFirstLoop); isFirstLoop=false)
        {
            printf("[");
            display((*listaDobleOriginal)->iterador->valorNodo);
            printf("]\n");
        }

}
