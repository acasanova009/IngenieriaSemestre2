#if !defined(LISTADOBLECIRCULAR_H)
#define LISTADOBLECIRCULAR_H


#include <stdbool.h>


#include "global.h"
#include "nodo.h"
#include "listaDoble.h"

typedef ListaDoble ListaDobleCircular;

ListaDobleCircular* ListaDobleCircularAlloc();


ListaDobleCircular * newListaDobleCircular();

bool listaDobleCircularEsNull(ListaDobleCircular * ld);

bool listaDobleCircularEstaVacia(ListaDobleCircular *ld);

void listaDobleCircularAgregarInicio(ListaDobleCircular *ld, Valor *valor);
void listaDobleCircularAgregarFinal(ListaDobleCircular *ld, Valor *valor);
void * listaDobleCircularEliminarInicio(ListaDobleCircular *ld);
void * listaDobleCircularEliminarFinal(ListaDobleCircular *ld);

bool listaDobleCircularContiene(ListaDobleCircular *ld, Valor* valor ,COMPARE fCompare);
void * ListaDobleCircularGetValorByIndex(ListaDobleCircular *ld, int index);
bool listaDobleCircularEliminarValor(ListaDobleCircular *ld, Valor *valor);

void listaDobleCircularDisplay(ListaDobleCircular *ld, DISPLAY display);
void listaDobleCircularDisplayIzquierda(ListaDobleCircular *ld, DISPLAY display);




#endif // FILADOBLE_H