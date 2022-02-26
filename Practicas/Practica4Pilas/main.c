#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "pila.c"
#include "libro.c"



int main(int argc, char const *argv[])
{
    
    Pila * miPila;

    inicializarPila(&miPila, 15);

    push(&miPila, 16);
    push(&miPila, 17);
    pop(&miPila);
    push(&miPila, 19);

    // iterarPila(&miPila);

    iterarRecursiva(&miPila);

    



    return 0;
}
