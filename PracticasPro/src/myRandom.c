#include "myRandom.h"
#include <stdlib.h>


// srand(time(NULL));
int randomNumberBetween(int a, int b){
    return (rand() % (++b - a)) + a;
    // return (rand() % ++b)+a;
}