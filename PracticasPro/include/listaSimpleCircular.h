#if !defined(LISTASIMPLECIRCULAR_H)
#define LISTASIMPLECIRCULAR_H

#include <stdbool.h>
#include "global.h"


#include "listaSimple.h"
#include "nodo.h"

typedef ListaSimple ListaSimpleCircular;

void listaSimpleCircularAgregar(ListaSimpleCircular *ls, Valor *valor);
void listaSimpleCircularEliminarValue(ListaSimpleCircular *ls, Valor * valor, COMPARE fCompare);
void listaSimpleCircularDisplay(ListaSimpleCircular *ld, DISPLAY display);

// IGUALES
// ListaSimpleCircular * newListaSimpleCircular();
// bool listaSimpleEsNull(ListaSimple* ls);
// bool listaSimpleEstaVacia(ListaSimple *ls);

// bool listaSimpleContiene(ListaSimple *ls, Valor * valor, COMPARE fCompare);
// int listaSimpleGetIndexByValue(ListaSimple *ls, Valor * valor, COMPARE fCompare);
// void * listaSimpleGetValueByIndex(ListaSimple *ls, int index, COMPARE fCompare);








#endif // LISTASIMPLE_H
