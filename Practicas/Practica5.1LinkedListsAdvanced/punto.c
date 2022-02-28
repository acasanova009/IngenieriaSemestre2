#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "global.c"

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
DISPLAY displayPunto(Punto *punto){
    printf("(%d,%d,%d)", punto->x, punto->y, punto->z);
}
COMPARE comparePunto(Punto *p1, Punto *p2){
    int arePointsEqual = 0;
    if ((p1->x == p2->x)&& (p1->y == p2->y)&&(p1->z == p2->z))
    {
        arePointsEqual = 1;
    }
    return arePointsEqual;
    
}