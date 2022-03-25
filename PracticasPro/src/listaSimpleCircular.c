#include "listaSimpleCircular.h"
#include <stdlib.h>
#include <stdio.h>



// bool listaSimpleEsNull(ListaSimple* ls){
//     bool esNull = false;
//     if (ls == NULL)
//          esNull = true;
    
//     return esNull;
// }
// bool listaSimpleEstaVacia(ListaSimple *ls){
//     if(listaSimpleEsNull(ls))return true;
//     bool esVacia = false;
//     if (ls->cabeza == NULL){ 
//         esVacia = true;
//     }
//     return esVacia;
// }

void listaSimpleCircularAgregar(ListaSimpleCircular *ls, Valor *valor){

    if(listaSimpleEsNull(ls))return;
    
    Nodo *nuevoNodo = newNodo(valor, NULL, NULL);

    if(listaSimpleEstaVacia(ls)){
        // El nodo izquierdo nunca se modifica en Lista Simple.
        nuevoNodo->derecha = nuevoNodo;
        ls->cabeza =  nuevoNodo; 
    }
    else{
        Nodo *iterador = ls->cabeza;

        while (iterador->derecha!=ls->cabeza)
        {
            nodoMoverADerecha(&iterador);
        }
        iterador->derecha = nuevoNodo;

        
        nuevoNodo->derecha = ls->cabeza;
        ls->cabeza =  nuevoNodo; 

    }
         (ls)->longitud+=1;
    

    return;

}

// bool listaSimpleContiene(ListaSimple *ls, Valor * valor, COMPARE fCompare){
//     if (listaSimpleEsNull(ls))return false;
    
    
//     Nodo *iterador = ls->cabeza;
//     bool contieneAlElemento = false;
    
//     if (!listaSimpleEstaVacia(ls))
//     {
//         while(iterador){
//             if(fCompare(iterador->valor, valor)==0){
//                 contieneAlElemento = true;
//                 break;
//             }
//              nodoMoverADerecha(&iterador);
//         }
//     }
//     return contieneAlElemento;
// }

// int listaSimpleGetIndexByValue(ListaSimple *ls, Valor * valor, COMPARE fCompare){
//     if (listaSimpleEsNull(ls))return false;
    
    
//     Nodo *iterador = ls->cabeza;
//     int index = 0;
    
//     if (!listaSimpleEstaVacia(ls))
//     {
//         while(iterador){
//             if(fCompare(iterador->valor, valor)==0){
//                 break;
//             }
//              nodoMoverADerecha(&iterador);
//             index++;
//         }
//     }
//     return index;
// }

// void * listaSimpleGetValueByIndex(ListaSimple *ls, int index, COMPARE fCompare){

//     if (listaSimpleEsNull(ls))return NULL;
//     if (index<0 || index>=ls->longitud)return NULL;

//     Nodo *iterador = (ls)->cabeza;
//     int contador =0;

//     while (contador<index){
         
//         nodoMoverADerecha(&iterador);
//         contador++;
//     }
//     return iterador->valor;

// }


void listaSimpleCircularEliminarValue(ListaSimpleCircular *ls, Valor * valor, COMPARE fCompare);


// void listaSimpleEliminarValue(ListaSimple *ls, Valor * valor, COMPARE fCompare){
//     if (listaSimpleEsNull(ls))return;
//     if (listaSimpleEstaVacia(ls))return;
//     if (!listaSimpleContiene(ls, valor, fCompare))return;
    

    
//     Nodo *iterador = ls->cabeza;
//     Nodo *lastIterador = NULL;
//     bool contieneAlElemento = false;
    
    
//     while(iterador){
//         if(fCompare(iterador->valor, valor)==0){
//             if (ls->cabeza == iterador)
//             {
//                 ls->cabeza = iterador->derecha;
//             }else{
//                 lastIterador->derecha = iterador->derecha;

//             }
//             free(iterador);
//             break;
//         }
//             lastIterador= iterador;
//             nodoMoverADerecha(&iterador);
//     }
//     ls->longitud--;

//     return;


// }


// void listaSimpleCircularDisplay(ListaSimpleCircular *ls, DISPLAY display){
//      if (listaSimpleEsNull(ls))return;
//      if (listaSimpleEstaVacia(ls))return;

//     Nodo *iterador = (ls)->cabeza;

//     int temporalIndex = 0;
//     printf("ListaSimple con %d elementos.\n", ls->longitud);
    

//     while(true){
//         printf("%d: ", temporalIndex++);
//             nodoDisplayValor(iterador,display);
//             nodoMoverADerecha(&iterador);
//         if(iterador==ls->cabeza){
//             break;
//         }
//     }
    
// }