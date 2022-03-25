#include "global.h"
#include <stdlib.h>
#include <stdio.h>

#include "myNumbers.h"



typedef struct{
    int dd;
    int mm;
    int aaaa;
    
}Fecha;

Fecha* fechaAlloc(){
    return malloc(sizeof(Fecha));
}
Fecha* fechaInit(Fecha *fecha){
    if (fecha == NULL) return NULL;

    fecha->dd =0;
    fecha->mm =0;
    fecha->aaaa =0;
    return fecha;
}

Fecha * newFechaRandom(){
    Fecha * newFecha = fechaAlloc();
    newFecha->dd = randomNumberBetween(1, 30);
    newFecha->mm =  randomNumberBetween(1, 12);
    newFecha->aaaa =  randomNumberBetween(1980, 2024);

    return newFecha;
}
Fecha* fechaAllocInitWithValues(int d, int m, int a){
    Fecha * newFecha = fechaAlloc();
    newFecha->dd = d;
    newFecha->mm = m;
    newFecha->aaaa = a;

    return newFecha;
}
Fecha* newFecha(int d, int m, int a){
    Fecha * newFecha = malloc(sizeof(Fecha));
    newFecha->dd = d;
    newFecha->mm = m;
    newFecha->aaaa = a;

    return newFecha;
}

void fechaDisplay(void *mysteryFecha){
    printf("%i/%i/%i\n", ((Fecha *)mysteryFecha)->dd, ((Fecha *)mysteryFecha)->mm, ((Fecha *)mysteryFecha)->aaaa);
} 
int fechaToInt(Fecha * fecha){
    return fecha->dd+fecha->mm*30+fecha->aaaa*365;

}
int fechaCompare(void *self, void *other){
    int result=0;
    int valorFecha1 = fechaToInt((Fecha*)self);
    int valorFecha2 = fechaToInt((Fecha*)other);

    if (valorFecha1 == valorFecha2)
    {
       result = 0;
    }else if(valorFecha1 > valorFecha2){
        result = 1;
    }else{
        result = -1;
    }

    return result;
    
}


void fechaFree(void * mysteryFecha){
    Fecha* f = (Fecha*)mysteryFecha;
    free(f);
}