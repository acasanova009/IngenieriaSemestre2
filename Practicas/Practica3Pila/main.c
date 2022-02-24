#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "pila.c"


int main()
{
    Pila* miPila;

    inicializarPila(&miPila,59); 
    

    for (size_t i = 0; i < 10; i++)
    {
        push(&miPila,i);
    }

    iterarPila(&miPila);


    for (size_t i = 0; i < 15; i++)
    {
        pop(&miPila);
    }


     for (size_t i = 500; i < 610; i++)
    {
        push(&miPila,i);
    }


     iterarPila(&miPila);



    
    return 0;
}


