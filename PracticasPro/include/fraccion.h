#if !defined(FRACCION_H)
#define FRACCION_H


#include <stdio.h>

typedef struct{
    int num;
    int denom;
}Fraccion;

Fraccion* newFraccion(int num, int denom){
    Fraccion* fraccion = malloc(sizeof(Fraccion));
    fraccion->num = num;
    fraccion->denom = denom;
    return fraccion;
}
char * fraccionToString(Fraccion * frac){
    Fraccion *fraccion = (Fraccion *)frac;
    char * string;
    int largeEnoughBufferLen = 3;
    string = (char*)malloc(largeEnoughBufferLen * sizeof(char));
    sprintf(string,"%i/%i",frac->num,frac->denom);
    return string;

}

#endif // FRACCION_H