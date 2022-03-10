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
#include "fecha.c"




int main()
{



    Queue * myQueue;
    Fecha * ptrFecha;
    Fecha * sameFecha;

    ptrFecha = fechaAllocInitWithValues(8,3,1994);
    sameFecha = ptrFecha;

    
    myQueue = queueInit(queueAlloc());
    queuePush(myQueue, ptrFecha);
    queuePush(myQueue, newFecha(25,12,1994));
    queuePush(myQueue, newFecha(03,1,2004));
    
    ptrFecha = fechaAllocInitWithValues(8,3,1000);
    queuePush(myQueue, ptrFecha);
    ptrFecha->aaaa = 2000;

    queueIterar(myQueue, fechaDisplay);
    



    return 0;
}
