#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// typedef struct punto Punto;
typedef struct{
    int x;
    int y;
    int z;
}Punto;

void inicializarPunto(Punto **punto, int x, int y, int z){
    Punto *mipunto  = malloc(sizeof(Punto));
    mipunto->x = x;
    mipunto->y = y;
    mipunto->z = z;
    *punto = mipunto;

}