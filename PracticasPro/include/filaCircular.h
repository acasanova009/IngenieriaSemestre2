#if !defined(FILACIRCULAR_H)
#define FILACIRCULAR_H


#include <stdbool.h>

#include "global.h"

typedef void ValorNodo;
typedef struct _queueNodoDoble QueueNodoCircular;


struct _queueNodoDoble{
    ValorNodo *valor;
    QueueNodoCircular *derecha;
    QueueNodoCircular *izquierda;
};
typedef struct{

    QueueNodoCircular *cabeza;
    QueueNodoCircular *rabo;
    int elementos;
    FREE freeFunctionNodeValue;


}FilaCircular;

bool iteradorTieneDerecha(QueueNodoCircular *iterador);
bool iteradorTieneIzquierda(QueueNodoCircular *iterador);

void  iteradorMoverADerecha(QueueNodoCircular **iterador);
void iteradorMoverAIzquierda(QueueNodoCircular **iterador);

void * iteradorFilaCircularDisplayValue(QueueNodoCircular *iterador, DISPLAY fdisp);

void * filaCircularRevisarNodo(QueueNodoCircular *filaCircular, DISPLAY fdisp);



bool filaCircularEsNull(FilaCircular *filaCircular);
void filaCircularSetFreeFunctionForNodeValues(FilaCircular *filaCircular, FREE newFreeFunctionNodeValue);
bool filaCircularEstaVacia(FilaCircular *filaCircular);

FilaCircular* filaCircularAlloc();
FilaCircular* filaCircularInit(FilaCircular *filaCircular);
FilaCircular* newFilaCircular();

void filaCircularPushEnd(FilaCircular *filaCircular,  ValorNodo *valorNuevo);
void filaCircularPushTop(FilaCircular *filaCircular,  ValorNodo *valorNuevo);

void *  filaCircularPopTop(FilaCircular *filaCircular);
void *  filaCircularPopEnd(FilaCircular *filaCircular);

void filaCircularIterarFromTop(FilaCircular *filaCircular, DISPLAY fDisplay);
void filaCircularIterarFromEnd(FilaCircular *filaCircular, DISPLAY fDisplay);

#endif // FILADOBLE_H