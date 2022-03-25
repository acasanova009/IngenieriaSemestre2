#include "listaSimple.h"
#include <stdlib.h>
#include <stdio.h>

ListaSimple * newListaSimple(){
    ListaSimple *ls = malloc(sizeof(ListaSimple));

    ls->cabeza = NULL;
    ls->longitud =0;

    return ls;
}
bool listaSimpleEsNull(ListaSimple* ls){
    bool esNull = false;
    if (ls == NULL)
         esNull = true;
    
    return esNull;
}
bool listaSimpleEstaVacia(ListaSimple *ls){
    if(listaSimpleEsNull(ls))return true;
    bool esVacia = false;
    if (ls->cabeza == NULL){ 
        esVacia = true;
    }
    return esVacia;
}

void listaSimpleAgregar(ListaSimple *ls, Valor *valor){

    if(listaSimpleEsNull(ls))return;
    
    Nodo *nuevoNodo = newNodo(valor, NULL, NULL);

    if(listaSimpleEstaVacia(ls)){
        // El nodo izquierdo nunca se modifica en Lista Simple.
        nuevoNodo->derecha = NULL;
        ls->cabeza =  nuevoNodo; 
    }
    else{
        
        nuevoNodo->derecha = ls->cabeza;
        ls->cabeza =  nuevoNodo; 

    }
         (ls)->longitud+=1;
    

    return;

}

bool listaSimpleContiene(ListaSimple *ls, Valor * valor, COMPARE fCompare){
    if (listaSimpleEsNull(ls))return false;
    if (listaSimpleEstaVacia(ls)) return false;
    
    Nodo *iterador = ls->cabeza;
    bool contieneAlElemento = false;
    
    
    for (size_t i = 0; i < ls->longitud; i++)
    {
        // printf("acutal elemento a comparar %s\n",iterador->valor );
        if(fCompare(iterador->valor, valor)==0){
            contieneAlElemento = true;
            break;
        }
            nodoMoverADerecha(&iterador);
    }
    
    return contieneAlElemento;
}

int listaSimpleGetIndexByValue(ListaSimple *ls, Valor * valor, COMPARE fCompare){
     if (listaSimpleEsNull(ls))return -1;
    if (listaSimpleEstaVacia(ls)) return -1;
    
    
    Nodo *iterador = ls->cabeza;
    int index = 0;
    
    for (size_t i = 0; i < ls->longitud; i++)
    {
        // printf("acutal elemento a comparar %s\n",iterador->valor );
        if(fCompare(iterador->valor, valor)==0){
            break;
        }
            nodoMoverADerecha(&iterador);
        index++;
    }
    
    return index;
}

void * listaSimpleGetValueByIndex(ListaSimple *ls, int index, COMPARE fCompare){

     if (listaSimpleEsNull(ls))return NULL;
    if (listaSimpleEstaVacia(ls)) return NULL;
    if (index<0 || index>=ls->longitud)return NULL;

    Nodo *iterador = (ls)->cabeza;
    int contador =0;

    while (contador<index){
         
        nodoMoverADerecha(&iterador);
        contador++;
    }
    return iterador->valor;

}

void listaSimpleEliminarValue(ListaSimple *ls, Valor * valor, COMPARE fCompare){
    if (listaSimpleEsNull(ls))return;
    if (listaSimpleEstaVacia(ls))return;
    if (!listaSimpleContiene(ls, valor, fCompare))return;
    

    
    Nodo *iterador = ls->cabeza;
    Nodo *lastIterador = NULL;
    bool contieneAlElemento = false;
    
    
    while(iterador){
        if(fCompare(iterador->valor, valor)==0){
            if (ls->cabeza == iterador)
            {
                ls->cabeza = iterador->derecha;
            }else{
                lastIterador->derecha = iterador->derecha;

            }
            free(iterador);
            break;
        }
            lastIterador= iterador;
            nodoMoverADerecha(&iterador);
    }
    ls->longitud--;

    return;


}


void listaSimpleDisplay(ListaSimple *ls, DISPLAY display){
     if (listaSimpleEsNull(ls))return;
     if (listaSimpleEstaVacia(ls)) return;
    Nodo *iterador = (ls)->cabeza;

   
    printf("ListaSimple con %d elementos.\n", ls->longitud);
    
    for (size_t i = 0; i < ls->longitud; i++)
    {
        printf("%d: ", i);
        nodoDisplayValor(iterador, display);
        nodoMoverADerecha(&iterador);
        
    }
    
}





