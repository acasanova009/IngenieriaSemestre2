#include "global.h"

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
    printf("%i/%i/%i", ((Fecha *)mysteryFecha)->dd, ((Fecha *)mysteryFecha)->mm, ((Fecha *)mysteryFecha)->aaaa);
} 

void fechaFree(void * mysteryFecha){
    Fecha* f = (Fecha*)mysteryFecha;
    free(f);
}