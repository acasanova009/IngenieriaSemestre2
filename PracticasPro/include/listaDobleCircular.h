#if !defined(LISTADOBLECIRCULAR_H)
#define LISTADOBLECIRCULAR_H


#include <stdbool.h>


#include "global.h"
#include "nodo.h"
#include "listaDoble.h"

typedef ListaDoble ListaDobleCircular;

ListaDobleCircular* ListaDobleCircularAlloc();


ListaDobleCircular * newListaDobleCircular();

bool ListaDobleCircularEsNull(ListaDobleCircular * ld);

bool ListaDobleCircularEstaVacia(ListaDobleCircular *ld);

void ListaDobleCircularAgregarInicio(ListaDobleCircular *ld, Valor *valor);
void ListaDobleCircularAgregarFinal(ListaDobleCircular *ld, Valor *valor);
void * ListaDobleCircularEliminarInicio(ListaDobleCircular *ld);
void * ListaDobleCircularEliminarFinal(ListaDobleCircular *ld);

bool ListaDobleCircularContiene(ListaDobleCircular *ld, Valor* valor ,COMPARE fCompare);
void * ListaDobleCircularGetValorByIndex(ListaDobleCircular *ld, int index);
bool ListaDobleCircularEliminarValor(ListaDobleCircular *ld, Valor *valor);

void listaDobleCircularDisplay(ListaDobleCircular *ld, DISPLAY display);




#endif // FILADOBLE_H