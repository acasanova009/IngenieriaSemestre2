#include "filaIterador.h"
#include <stdlib.h>
#include "global.h"

bool iteradroEsNull(QueueNodoCircular *iterador){
    bool esNull = false;
    if(iterador==NULL)
        esNull = true;
    return esNull;
}
bool iteradorTieneDerecha(QueueNodoCircular *iterador){
    bool tieneDerecha = false;
    if (iteradroEsNull(iterador)) return false;
    
    if(iterador->derecha!=NULL){
        tieneDerecha = true;
    }
    return tieneDerecha;
}
bool iteradorTieneIzquierda(QueueNodoCircular *iterador){
    bool tieneIzquierda = false;
    if (iteradroEsNull(iterador)) return false;
    
    if(iterador->izquierda!=NULL)
        tieneIzquierda = true;
    return tieneIzquierda;
}

void iteradorMoverADerecha(QueueNodoCircular **iterador){
    if(!iteradorTieneDerecha(iterador)) return;

    (*iterador) = (*iterador)->derecha;
}
void iteradorMoverAIzquierda(QueueNodoCircular **iterador){
     if(!iteradorTieneIzquierda(iterador)) return;

    (*iterador) = (*iterador)->izquierda;

}

void * iteradorMostrarValorActual(QueueNodoCircular *iterador, DISPLAY fdisp){
    if (iteradroEsNull(iterador)) return NULL;
    void * valorTemp =  iterador->valor;

    fdisp(valorTemp);

    return valorTemp;


}