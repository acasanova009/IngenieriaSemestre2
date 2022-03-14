#if !defined(FILADOBLE_H)
#define FILADOBLE_H


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


}FilaDoble;

bool filaDobleEsNull(FilaDoble *filaDobleOriginal);
void filaDobleSetFreeFunctionForNodeValues(FilaDoble *filaDobleOriginal, FREE newFreeFunctionNodeValue);
bool filaDobleEstaVacia(FilaDoble *filaDobleOriginal);
void * filaDobleRevisarNodo(QueueNodoDoble *filaDobleOriginal, DISPLAY fdisp);

FilaDoble* filaDobleAlloc();
FilaDoble* filaDobleInit(FilaDoble *filaDobleOriginal);
FilaDoble* newFilaDoble();

void filaDoblePushEnd(FilaDoble *filaDobleOriginal,  ValorNodo *valorNuevo);
void filaDoblePushTop(FilaDoble *filaDobleOriginal,  ValorNodo *valorNuevo);

void *  filaDoblePopTop(FilaDoble *filaDobleOriginal);
void *  filaDoblePopEnd(FilaDoble *filaDobleOriginal);

void filaDobleIterarFromTop(FilaDoble *filaDobleOriginal, DISPLAY fDisplay);
void filaDobleIterarFromEnd(FilaDoble *filaDobleOriginal, DISPLAY fDisplay);

#endif // FILADOBLE_H