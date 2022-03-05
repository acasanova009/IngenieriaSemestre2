#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "global.c"
#include "listaDoble.c"
#include "punto.c"
#include "queue.c"
#include "pila.c"
#include "myString.c"




int main()
{
    ListaDoble * miLista = listaDobleInicializar(miLista);

    
    for (size_t i = 0; i < 10; i++)
        listaDobleAgregarInicio(&miLista, "hola" );
        
    for (size_t i = 0; i < 8; i++)
        listaDobleEliminarInicio(&miLista);
    

    listaDobleIterar(&miLista, displayString);




    return 0;
}
