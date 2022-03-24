#if !defined(NODO_H)
#define NODO_H

#include <stdbool.h>
#include "global.h"

typedef struct _nodo Nodo;
typedef void Valor;



struct _nodo{
    Valor *valor;
    Nodo *derecha;
    Nodo *izquierda;
};

void* newNodo(Valor *valor,  Nodo *izquierda, Nodo *derecha);

bool nodoEsNull(Nodo *nodo);
bool nodoTieneDerecha(Nodo *nodo);
bool nodoTieneIzquierda(Nodo *nodo);
bool nodoCompareValueWithAnotherValue(Nodo *nodo,COMPARE fCompare, Valor * valor);

void nodoMoverADerecha(Nodo **nodo);
void nodoMoverAIzquierda(Nodo **nodo);
void nodoDisplayValor(Nodo *nodo, DISPLAY fdisp);
void *nodoGetValor(Nodo *nodo);





#endif // NODO_H

