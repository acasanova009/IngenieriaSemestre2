#if !defined(QUEUE_H)
#define QUEUE_H



#include <stdbool.h>
#include <stdlib.h>
#include "global.h"

typedef void ValorNodo;
typedef struct _queueNodo QueueNodo;


struct _queueNodo{
    ValorNodo *valor;
    QueueNodo *siguiente;
};
typedef struct{

    QueueNodo *cabeza;
    QueueNodo *rabo;
    int elementos;
    FREE freeFunctionNodeValue;


}Queue;

bool queueEsNull(Queue *queueOriginal);
void queueSetFreeFunctionForNodeValues(Queue *queueOriginal, FREE newFreeFunctionNodeValue);
bool queueEstaVacia(Queue *queueOriginal);
// Regresar el valor del nodo.
void * queueRevisarNodo(QueueNodo *queueOriginal, DISPLAY fdisp);
Queue* queueAlloc();
Queue* queueInit(Queue *queueOriginal);
Queue* newQueue();

void queuePush(Queue *queueOriginal,  ValorNodo *valorNuevo);


void *  queuePop(Queue *queueOriginal);


void queueIterar(Queue *queueOriginal, DISPLAY fDisplay);


#endif // QUEUE_H

