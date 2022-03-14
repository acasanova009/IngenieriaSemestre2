#if !defined(LISTADOBLE_H)
#define LISTADOBLE_H


#include <stdbool.h>
#include "global.h"


typedef void ListaValor;
typedef struct _nodo  ListaNodo;
struct _nodo{
    ListaValor * valor;
    
    ListaNodo *derecha;
    ListaNodo *izquierda;

};

typedef void (*agregar)(void * ls, void*val);

typedef struct {
    ListaNodo * cabeza;
    ListaNodo * rabo;

    int cantidadDeNodos;

    agregar add;

}ListaDoble;




ListaDoble* listaDobleAlloc();
ListaDoble* listaDobleInit(ListaDoble *listaDobleOriginal);

ListaDoble * newListaDoble();

bool listaDobleEsNull(ListaDoble * listaDoble);

bool listaDobleEstaVacia(ListaDoble *listaDobleOriginal);

void listaDobleAgregarInicio(ListaDoble *listaDobleOriginal, ListaValor *valor);

void listaDobleEliminarInicio(ListaDoble *listaDobleOriginal);

bool listaDobleContiene(ListaDoble *listaDobleOriginal,ListaValor* valor ,COMPARE fCompare);

void listaDobleIterar(ListaDoble *listaDobleOriginal, DISPLAY display);

void displayListaDoble(ListaDoble *listaDobleOriginal, DISPLAY display);

#endif // LISTADOBLE_H