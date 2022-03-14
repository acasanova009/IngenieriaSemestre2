#include <stdio.h>

#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "fraccion.h"
#include "queue.h"


void matrizPrint(Fraccion *x, Fraccion *y, Fraccion *z){

    printf("------\n");
    printf("1 %s %s a\n", fraccionToString(x), fraccionToString(y));
    printf("%s 2 %s b \n", fraccionToString(x), fraccionToString(z));
    printf("%s %s 1 c\n", fraccionToString(y), fraccionToString(y));
    printf("------\n");
}

int main()
{  

    Fraccion *exis[3] = {newFraccion(-2,1),newFraccion(1,1),newFraccion(4,3)};
    Fraccion *yes[3] = {newFraccion(0,1),newFraccion(1,1),newFraccion(7,3)};
    Fraccion *zetas[3] = {newFraccion(0,1),newFraccion(-1,3),newFraccion(1,1)};

    int matrizNumber = 1;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {   printf("%i", matrizNumber++);
                matrizPrint(exis[i], yes[j], zetas[k]);
            }
            
        }
        
    }

    


    
    
    return 0;
}



