#include <time.h>
#include "myRandom.h"

int randomNumberBetween(int a, int b){
    return (rand() % (++b - a)) + a;
    // return (rand() % ++b)+a;
}