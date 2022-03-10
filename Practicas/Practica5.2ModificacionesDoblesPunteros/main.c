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



    Queue * myQueue = newQueue();
    
    que(quien, loquesea);
    for (size_t i = 0; i < 5; i++)
        queuePush(myQueue, newFecha(i,i*10,i*1000));
        /* code */
    for (size_t i = 0; i < 10; i++)
        queuePop(myQueue);
    
    
    for (size_t i = 0; i < 5; i++)
        queuePush(myQueue, newFecha(i,i*10,i*1000));

    queueIterar(myQueue,fechaDisplay);
   




    return 0;
}
