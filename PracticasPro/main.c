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

    for (size_t i = 0; i < 20; i++)
    {
        filaPushOrdenadamente(miFila, newInt(randomNumberBetween(1,20)), integerCompare);
        
    }
    

    filaDobleIterarFromTop(miFila, integerDisplay);

    // filaPushOrdenadamente(miFila, "B", fechaDisplay);



    

    
    return 0;
}