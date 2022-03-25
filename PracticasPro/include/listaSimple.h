#if !defined(LISTASIMPLE_H)
#define LISTASIMPLE_H

#include <stdbool.h>
#include "global.h"


#include "nodo.h"


typedef struct {
    Nodo * cabeza;
    // Nodo * rabo;

    int longitud;


}ListaSimple;


ListaSimple * newListaSimple();
bool listaSimpleEsNull(ListaSimple* ls);
bool listaSimpleEstaVacia(ListaSimple *ls);

void listaSimpleAgregar(ListaSimple *ls, Valor *valor);

bool listaSimpleContiene(ListaSimple *ls, Valor * valor, COMPARE fCompare);

int listaSimpleGetIndexByValue(ListaSimple *ls, Valor * valor, COMPARE fCompare);

void * listaSimpleGetValueByIndex(ListaSimple *ls, int index, COMPARE fCompare);


void listaSimpleEliminarValue(ListaSimple *ls, Valor * valor, COMPARE fCompare);

void listaSimpleDisplay(ListaSimple *ld, DISPLAY display);


#endif // LISTASIMPLE_H
