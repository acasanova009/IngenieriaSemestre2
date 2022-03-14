#if !defined(FRACCION_H)
#define FRACCION_H




typedef struct{
    int num;
    int denom;
}Fraccion;

Fraccion* newFraccion(int num, int denom);

char * fraccionToString(Fraccion * frac);

#endif // FRACCION_H