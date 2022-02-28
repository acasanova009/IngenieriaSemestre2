#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "lista.c"

typedef struct{
    int x;
    int y;
    int z;
}Punto;

int main()
{
    Lista *miLista;

    Punto * unPunto;
    unPunto = malloc(sizeof(Punto));
    unPunto->x = 1;
    unPunto->y = 1;
    unPunto->z = 1;
    inicializarLista(&miLista,unPunto);


    unPunto = malloc(sizeof(Punto));
    unPunto->x = 2;
    unPunto->y = 2;
    unPunto->z = 2;
    agregarInicio(&miLista,unPunto); 
    unPunto = malloc(sizeof(Punto));
    unPunto->x = 3;
    unPunto->y = 3;
    unPunto->z = 3;
    
    agregarInicio(&miLista,unPunto); 
    unPunto = malloc(sizeof(Punto));
    unPunto->x = 4;
    unPunto->y = 4;
    unPunto->z = 4;
    
    agregarInicio(&miLista,unPunto); 
    unPunto = malloc(sizeof(Punto));
    unPunto->x = 5;
    unPunto->y = 5;
    unPunto->z = 5;
    agregarInicio(&miLista,unPunto); 

    


    

    Lista *nodoIterador = miLista;
    do {
        Punto *Punto = (Punto*)nodoIterador->valorNodo;
        printf("x:%d y:%d z:%d\n", Punto->x, Punto->y, Punto->z);

    }while(nodoSiguiente(&nodoIterador));
   
    return 0;
}


