
#include <stdlib.h>
#include <stdbool.h>


// typedef struct _ListEntry ListEntry;



typedef void ListaValor;
typedef struct ListaNodo  Lista;
struct ListaNodo{
    ListaValor * valorNodo;
    
    Lista *derecha;
    Lista *izquierda;

};

void inicializarLista(Lista **lista, ListaValor *valor){
    Lista *nodoPorAgregar = malloc(sizeof(Lista));
    


    nodoPorAgregar->valorNodo = valor;
    // lista->valorNodo = valorNodo;
    nodoPorAgregar->derecha = NULL;
    nodoPorAgregar->izquierda = NULL;

    *lista = nodoPorAgregar; 

};


void agregarInicio(Lista **lista, ListaValor *valor){
    
    Lista *nodoActual = *lista;
    Lista *nodoPorAgregar = malloc(sizeof(Lista));
    
    
    nodoPorAgregar->valorNodo = valor;
    nodoPorAgregar->derecha = NULL;
    nodoPorAgregar->izquierda = nodoActual;

    nodoActual->derecha=nodoPorAgregar;

    *lista = nodoPorAgregar;

}



void iterarListaRecursivamenteInterno(Lista **lista ){

    if ((*lista) ==NULL)
        return;

    // reivsarContenido(&(*lista));
    iterarListaRecursivamenteInterno(&(*lista)->izquierda);

}

bool nodoSiguiente(Lista **listaNodoIterador){
    bool haySiguiente = false;
    
    
    if ((*listaNodoIterador)->izquierda!=NULL){
        (*listaNodoIterador) = (*listaNodoIterador)->izquierda;
        haySiguiente = true;

    }

    return haySiguiente;
}

// Lista* nodoSiguiente(Lista **lista){
//     Lista *nodoActual = *lista;
    
//     if (*lista!=NULL)
//         nodoActual = (*lista)->izquierda;

// }
// void iterarListaRecursivamente(Lista **lista){
//     Lista *nodoActual = *lista;

//     iterarListaRecursivamenteInterno(&nodoActual);
// }


// void reivsarContenido(Lista **lista){
//     ListaValor * valorTemporal;
//     if (*lista!=NULL)
//         valorTemporal = (*lista)->valorNodo;
    
//     printf("Dato %d\n\n",valorTemporal);
// }
//     Lista b;
    
//     b = malloc(sizeof(Pila));
//     b->valor = valor;
//     //  b->valorNodo = valorNodo;
//     b->ultimo =*p;
    
    

// };


// void agregarValorALista( ListaValor * nuevoValor, Lista lista ){


// }
// void iterarLista(ListaNodo *lista){

// }
