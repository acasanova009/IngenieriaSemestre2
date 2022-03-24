
#include "listaDoble.h"


#include <string.h>
#include <stdlib.h>


ListaDoble* listaDobleAlloc(){
    return malloc(sizeof(ListaDoble));    
}

ListaDoble* listaDobleInit(ListaDoble *ld){
    
    ld->longitud = 0;
    ld->cabeza =  NULL; 
    ld->rabo =  NULL; 
    // ld->add =  NULL; 
    
    return ld;

}


ListaDoble * newListaDoble(){
    return listaDobleInit(listaDobleAlloc());
}

bool listaDobleEsNull(ListaDoble * ld){
    bool esNull = false;
    if (ld == NULL)
         esNull = true;
    
    return esNull;
}


bool listaDobleEstaVacia(ListaDoble *ld){
    bool esVacia = false;
    if ((ld)->cabeza == NULL || (ld)->rabo==NULL){ 
        esVacia = true;
    }
    return esVacia;
}
// void listaDobleAgregarFinal()

void listaVaciaAgregar(ListaDoble *ld, Nodo * nodoPorAgregar){
    if(listaDobleEsNull(ld))return;
    if (listaDobleEstaVacia(ld))
    {
        nodoPorAgregar->derecha = NULL;
        nodoPorAgregar->izquierda = NULL;
        
        (ld)->cabeza =  nodoPorAgregar; 
        (ld)->rabo =  nodoPorAgregar; 
    }

    (ld)->longitud+=1;

}
void listaDobleAgregarInicio(ListaDoble *ld, Valor *valor){

    if(listaDobleEsNull(ld))return;
    
    Nodo *nodoPorAgregar = newNodo(valor, NULL, NULL);

    if(listaDobleEstaVacia(ld)){
        listaVaciaAgregar(ld, nodoPorAgregar);
    }
    else{
        nodoPorAgregar->izquierda = NULL;
        nodoPorAgregar->derecha = ld->cabeza;

        ld->cabeza->izquierda = nodoPorAgregar;
        ld->cabeza =  nodoPorAgregar; 
         (ld)->longitud+=1;
    }
    

    return;

}
void listaDobleAgregarFinal(ListaDoble *ld, Valor *valor){
    if(listaDobleEsNull(ld))return;
    
    Nodo *nodoPorAgregar = newNodo(valor, NULL, NULL);

    if(listaDobleEstaVacia(ld)){
        listaVaciaAgregar(ld, nodoPorAgregar);
    }
    else{
        nodoPorAgregar->derecha = NULL;
        nodoPorAgregar->izquierda = ld->rabo;

        ld->rabo->derecha = nodoPorAgregar;
        ld->rabo =  nodoPorAgregar; 
         (ld)->longitud+=1;
    }
    
    return;

}
void* listaDobleDesconectarNodo(ListaDoble *ld, Nodo * nodoPorDesconectar){

    void* valorNodo = nodoPorDesconectar->valor;
    // Caso unitario.
    if (ld->cabeza == ld->rabo)
    {
        (ld)->rabo = NULL;
        (ld)->cabeza = NULL;

    }else if(ld->cabeza == nodoPorDesconectar)
    {
        (ld)->cabeza = (ld)->cabeza->derecha;
        (ld)->cabeza->izquierda = NULL;

    }else if(ld->rabo == nodoPorDesconectar){

        (ld)->rabo = (ld)->rabo->izquierda;
        (ld)->rabo->derecha = NULL;

    }else{
        if(nodoTieneDerecha(nodoPorDesconectar)&&nodoTieneIzquierda(nodoPorDesconectar)){

        nodoPorDesconectar->izquierda->derecha =nodoPorDesconectar->derecha;
        nodoPorDesconectar->derecha->izquierda =nodoPorDesconectar->izquierda;
        }
        
    }
    ld->longitud-=1;

    free(nodoPorDesconectar);

    return valorNodo;
    

}

void* listaDobleEliminarInicio(ListaDoble *ld){
    return listaDobleDesconectarNodo(ld, ld->cabeza);
}
void* listaDobleEliminarFinal(ListaDoble *ld){
    return listaDobleDesconectarNodo(ld, ld->rabo);
}

bool listaDobleContiene(ListaDoble *ld, Valor* valor ,COMPARE fCompare){
    if (listaDobleEsNull(ld))return false;
    
    
    Nodo *iterador = (ld)->cabeza;
    bool contieneAlElemento = false;
    
    if (!listaDobleEstaVacia(ld))
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
void * listaDobleGetValorByIndex(ListaDoble *ld, int index){

    if (listaDobleEsNull(ld))return NULL;
    if (index<0 || index>=ld->longitud)return NULL;

    Nodo *iterador = (ld)->cabeza;
    int contador =0;

    while (contador<index){
         
        nodoMoverADerecha(&iterador);
        contador++;
    }
    return iterador->valor;

}

void listaDobleDisplay(ListaDoble *ld, DISPLAY display){
     if (listaDobleEsNull(ld))return;
    Nodo *iterador = (ld)->cabeza;
    
    if (!listaDobleEstaVacia(ld))
    {
        while(iterador){
            display(iterador->valor);
             nodoMoverADerecha(&iterador);
        }
    }
}



bool listaDobleEliminarValor(ListaDoble *ld, Valor *valor){
    
    if (listaDobleEstaVacia(ld))return false;
    if (valor==NULL)return false;
    


    bool pudoEliminar = false;
    Nodo *iterador = (ld)->cabeza;
    
    while(iterador){
        
        if (iterador->valor == valor)
        {  
            if(listaDobleDesconectarNodo(ld, iterador)!=NULL){
                pudoEliminar = true;
            }
            
           break;
        }
        
        nodoMoverADerecha(&iterador);
         

    }

    return pudoEliminar;
    
}

    
