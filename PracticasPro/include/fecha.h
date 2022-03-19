#if !defined(FECHA_H)
#define FECHA_H

typedef struct{
    int dd;
    int mm;
    int aaaa;
    
}Fecha;

Fecha* fechaAlloc();
Fecha* fechaInit(Fecha *fecha);


Fecha* fechaAllocInitWithValues(int d, int m, int a);
Fecha* newFecha(int d, int m, int a);

void fechaDisplay(void *mysteryFecha);
int fechaCompare(void *self, void *other);

void fechaFree(void * mysteryFecha);
#endif // FECHA_H
