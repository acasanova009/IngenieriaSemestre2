#if !defined(QUEUEDOBLE_H)
#define QUEUEDOBLE_H


#include <stdbool.h>

#include "global.h"

typedef void ValorNodo;
typedef struct _queueNodoDoble QueueNodoDoble;


struct _queueNodoDoble{
    ValorNodo *valor;
    QueueNodoDoble *derecha;
    QueueNodoDoble *izquierda;
};
typedef struct{

    QueueNodoDoble *cabeza;
    QueueNodoDoble *rabo;
    int elementos;
    FREE freeFunctionNodeValue;


}QueueDoble;

bool queueDobleEsNull(QueueDoble *queueDobleOriginal);
void queueDobleSetFreeFunctionForNodeValues(QueueDoble *queueDobleOriginal, FREE newFreeFunctionNodeValue);
bool queueDobleEstaVacia(QueueDoble *queueDobleOriginal);
void * queueDobleRevisarNodo(QueueNodoDoble *queueDobleOriginal, DISPLAY fdisp);

QueueDoble* queueDobleAlloc();
QueueDoble* queueDobleInit(QueueDoble *queueDobleOriginal);
QueueDoble* newQueueDoble();

void queueDoblePushEnd(QueueDoble *queueDobleOriginal,  ValorNodo *valorNuevo);
void queueDoblePushTop(QueueDoble *queueDobleOriginal,  ValorNodo *valorNuevo);

void *  queueDoblePopTop(QueueDoble *queueDobleOriginal);
void *  queueDoblePopEnd(QueueDoble *queueDobleOriginal);

void queueDobleIterarFromTop(QueueDoble *queueDobleOriginal, DISPLAY fDisplay);
void queueDobleIterarFromEnd(QueueDoble *queueDobleOriginal, DISPLAY fDisplay);

#endif // QUEUEDOBLE_H