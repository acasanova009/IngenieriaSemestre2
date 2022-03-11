#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "global.c"
#include "listaDoble.c"
#include "punto.c"
#include "queue.c"
#include "queueDoble.c"
#include "pila.c"
#include "myString.c"
#include "fecha.c"


#include "cliente.c"
#include "moduloDeAtencion.c"






int main()
{
    ListaDoble * miLista = newListaDoble();
    listaDobleAgregarInicio(miLista, "Hola");
    listaDobleAgregarInicio(miLista, "Hola");
    listaDobleAgregarInicio(miLista, "Hola");
    listaDobleAgregarInicio(miLista, "Adios");

    if(listaDobleContiene(miLista, "Adios", compareString )){
        printf("Si contiene\n");
    }


    listaDobleIterar(miLista, displayString);

    return 0;
}



