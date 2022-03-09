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



    Queue * myQueue;
    
    myQueue = queueInit(queueAlloc());

    queuePush(myQueue, "1");
    queuePush(myQueue, "2");
    queuePush(myQueue, "3");

    printf("%s\n", queuePop(myQueue));
    printf("%s\n", queuePop(myQueue));
    printf("%s\n", queuePop(myQueue));

    queueIterar(myQueue, displayString);



    return 0;
}
