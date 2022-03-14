

#if !defined(PILA_H)
#define PILA_H


#include <stdbool.h>
#include "global.h"

typedef void ValorNodo;
typedef struct _pilaNodo PilaNodo;



struct _pilaNodo{
    ValorNodo *valor;
    PilaNodo *ultimo;

};
typedef struct{

    PilaNodo *cabeza;
    PilaNodo *rabo;

}Pila;

bool pilaEsNull(Pila *pilaOriginal);
bool pilaEstaVacia(Pila * pilaOriginal);

void * pilaRevisarNodo(PilaNodo *pilaNodo, DISPLAY fdisp);

Pila * pilaAlloc();
Pila * pilaInit(Pila *pilaOriginal);
Pila * newPila();


void pilaPush(Pila *pilaOriginal,  ValorNodo *valorNuevo);
void *  pilaPop(Pila *pilaOriginal);

void pilaIterar(Pila *pilaOriginal, DISPLAY fDisplay);

#endif // PILA_H