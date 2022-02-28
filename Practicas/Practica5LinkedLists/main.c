#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "lista.c"

typedef struct{
    int x;
    int y;
    int z;
}Point;

int main()
{
    Lista *miLista;

    Point * unPunto;
    unPunto = malloc(sizeof(Point));
    unPunto->x = 1;
    unPunto->y = 1;
    unPunto->z = 1;
    inicializarLista(&miLista,unPunto);


    unPunto = malloc(sizeof(Point));
    unPunto->x = 2;
    unPunto->y = 2;
    unPunto->z = 2;
    agregarInicio(&miLista,unPunto); 
    unPunto = malloc(sizeof(Point));
    unPunto->x = 3;
    unPunto->y = 3;
    unPunto->z = 3;
    agregarInicio(&miLista,unPunto); 
    
    Lista *nodoIterador = miLista;
    
    // Point *point = (Point*)nodoIterador->valorNodo;
    do {
        Point *point = (Point*)nodoIterador->valorNodo;
        printf("x:%d y:%d z:%d\n", point->x, point->y, point->z);

    }while(nodoSiguiente(&nodoIterador));
    // Lista *nodoIterador = miLista;
    
    // Point *point = (Point*)nodoIterador->valorNodo;
    // while(nodoIterador!=NULL) {
    //     Point *point = (Point*)nodoIterador->valorNodo;
    //     printf("x:%d y:%d z:%d\n", point->x, point->y, point->z);
    //     nodoIterador = nodoSiguiente(&nodoIterador);
    // }
   
    return 0;
}


