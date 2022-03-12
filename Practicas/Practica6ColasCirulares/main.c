#include <stdio.h>

#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "global.h"
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
    Pila * miPila = newPila();

    pilaPush(miPila,newFecha(01,1,2001));
    pilaPush(miPila,newFecha(02,2,2002));
    pilaPush(miPila,newFecha(03,3,2003));

    
    fechaDisplay(pilaPop(miPila));
    printf("\n");
    fechaDisplay(pilaPop(miPila));
    printf("\n");




    return 0;
}



