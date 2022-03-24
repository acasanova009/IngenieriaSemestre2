#if !defined(LISTADOBLE_H)
#define LISTADOBLE_H


#include <stdbool.h>
#include "global.h"


#include "nodo.h"


typedef struct {
    Nodo * cabeza;
    Nodo * rabo;

    int longitud;


}ListaDoble;


ListaDoble* listaDobleAlloc();


ListaDoble * newListaDoble();

bool listaDobleEsNull(ListaDoble * ld);

bool listaDobleEstaVacia(ListaDoble *ld);

void listaDobleAgregarInicio(ListaDoble *ld, Valor *valor);
void listaDobleAgregarFinal(ListaDoble *ld, Valor *valor);
void * listaDobleEliminarInicio(ListaDoble *ld);
void * listaDobleEliminarFinal(ListaDoble *ld);

bool listaDobleContiene(ListaDoble *ld, Valor* valor ,COMPARE fCompare);
void * listaDobleGetValorByIndex(ListaDoble *ld, int index);
bool listaDobleEliminarValor(ListaDoble *ld, Valor *valor);

void listaDobleDisplay(ListaDoble *ld, DISPLAY display);




#endif // LISTADOBLE_H