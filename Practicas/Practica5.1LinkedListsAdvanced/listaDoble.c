#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef void ListaValor;
typedef struct Nodo  ListaNodo;
struct Nodo{
    ListaValor * valorNodo;
    
    ListaNodo *derecha;
    ListaNodo *izquierda;

};

typedef struct {
    ListaNodo * cabeza;
    ListaNodo * cola;
    ListaNodo * iterador;
    int cantidadDeNodos;
}ListaDoble;






void inicializarListaDoble(ListaDoble **listaDoble, ListaValor *valor){
    ListaDoble *listaPrincipalAlocada = malloc(sizeof(ListaDoble));
    ListaNodo *nodoPorAgregar = malloc(sizeof(ListaNodo));
    
    nodoPorAgregar->valorNodo = valor;
    nodoPorAgregar->derecha = NULL;
    nodoPorAgregar->izquierda = NULL;

    (*listaDoble) = listaPrincipalAlocada;
    (*listaDoble)->cantidadDeNodos = 1;

    (*listaDoble)->cabeza =  nodoPorAgregar; 
    (*listaDoble)->cola =  nodoPorAgregar; 

};


void agregarInicio(ListaDoble **listaDoble, ListaValor *valor){
    
    ListaNodo *nodoActual = (*listaDoble)->cabeza;
    ListaNodo *nodoPorAgregar = malloc(sizeof(ListaNodo));
    nodoPorAgregar->valorNodo = valor;
    
    
    nodoPorAgregar->derecha = NULL;
    nodoPorAgregar->izquierda = nodoActual;

    nodoActual->derecha=nodoPorAgregar;

    (*listaDoble)->cabeza =  nodoPorAgregar; 
    (*listaDoble)->cantidadDeNodos+=1;

}

void agregarFinal(ListaDoble **listaDoble, ListaValor *valor){
    
    ListaNodo *nodoActual = (*listaDoble)->cola;
    ListaNodo *nodoPorAgregar = malloc(sizeof(ListaNodo));
    nodoPorAgregar->valorNodo = valor;
    
    
    nodoPorAgregar->derecha = nodoActual;
    nodoPorAgregar->izquierda = NULL;

    nodoActual->izquierda=nodoPorAgregar;

    (*listaDoble)->cola =  nodoPorAgregar; 
    (*listaDoble)->cantidadDeNodos+=1;

}
void eliminarFinal(ListaDoble **listaDoble){

    if(!(*listaDoble)->cola)
    return;
    ListaNodo *nodoActual = (*listaDoble)->cola;
    ListaNodo *nodoAnterior = (*listaDoble)->cola->derecha;
    
    if (!nodoActual)
    {
        (*listaDoble)->cola = NULL;
        (*listaDoble)->cabeza = NULL;
    } else if(!nodoAnterior){

        (*listaDoble)->cola = NULL;
        (*listaDoble)->cabeza = NULL;
        free(nodoAnterior);
        (*listaDoble)->cantidadDeNodos-=1;

    } else {
        
        nodoAnterior->izquierda = NULL;
        (*listaDoble)->cola = nodoAnterior;
    
        (*listaDoble)->cantidadDeNodos-=1;
        free(nodoActual);
    }
}


bool nodoSiguientePorCabeza(ListaNodo **listaNodoIterador){
    bool haySiguiente = false;
    
    if ((*listaNodoIterador)->izquierda!=NULL){
        (*listaNodoIterador) = (*listaNodoIterador)->izquierda;
        haySiguiente = true;

    }

    return haySiguiente;
}
bool nodoSiguientePorCola(ListaNodo **listaNodoIterador){
    bool haySiguiente = false;
    
    if ((*listaNodoIterador)->derecha!=NULL){
        (*listaNodoIterador) = (*listaNodoIterador)->derecha;
        haySiguiente = true;

    }

    return haySiguiente;
}

bool iterarIzquierda(ListaDoble **listaDoble, bool isFirstLoop){
    ListaNodo *ptrIterador = (*listaDoble)->iterador;
    bool canKeepIterating = false;
    if (isFirstLoop){
        
        if((*listaDoble)->cabeza){
            (*listaDoble)->iterador = (*listaDoble)->cabeza;
            canKeepIterating =true;
        }
        
    }else{
        if(ptrIterador->izquierda){
            (*listaDoble)->iterador=ptrIterador->izquierda;
            canKeepIterating = true;
        }
    }

    return canKeepIterating;
}
bool iterarDerecha(ListaDoble **listaDoble, bool isFirstLoop){
    ListaNodo *ptrIterador = (*listaDoble)->iterador;
    bool canKeepIterating = false;
    if (isFirstLoop){
        
        if((*listaDoble)->cola){
            (*listaDoble)->iterador = (*listaDoble)->cola;
            canKeepIterating =true;
        }
        
    }else{
        if(ptrIterador->derecha){
            (*listaDoble)->iterador=ptrIterador->derecha;
            canKeepIterating = true;
        }
    }

    return canKeepIterating;
}


void toString(ListaDoble **listaDoble)){
    for (bool isFirstLoop = true; iterarIzquierda(listaDoble, isFirstLoop); isFirstLoop=false)
        {
            
            
        }

}

