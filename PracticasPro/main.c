#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "filaDoble.h"
#include "myString.h"
#include "myNumbers.h"
#include "fecha.h"



int main(int argc, char const *argv[])
{   
    srand(time(NULL));

    FilaDoble * miFila = newFilaDoble();

    filaPushOrdenadamente(miFila, "C", stringCompare);
    filaPushOrdenadamente(miFila, "C", stringCompare);
    filaPushOrdenadamente(miFila, "B", stringCompare);
    filaPushOrdenadamente(miFila, "C", stringCompare);
    filaPushOrdenadamente(miFila, "C", stringCompare);
    filaPushOrdenadamente(miFila, "A", stringCompare);
    filaPushOrdenadamente(miFila, "F", stringCompare);
    filaPushOrdenadamente(miFila, "W", stringCompare);
    filaPushOrdenadamente(miFila, "B", stringCompare);
    
    

    filaDobleIterarFromTop(miFila, stringDisplay);




    

    
    return 0;
}