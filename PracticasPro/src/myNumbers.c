#include "myNumbers.h"
#include <stdlib.h>
#include <stdio.h>


// srand(time(NULL));
int randomNumberBetween(int a, int b){
    return (rand() % (++b - a)) + a;
    // return (rand() % ++b)+a;
}


int integerCompare(void* i, void * j){
    int *a = (int*)(i);
    int *b = (int*)(j);

    int result = 0;
    if(*a < *b){result =-1;}else{result = 1;}

    return result;
}


void integerDisplay(void * i){
    int* temp = (int*)(i);
    printf("%d\n", *temp);
}


int * newInt(int in){
    int* memoryOfInt = (int*)malloc(sizeof(int));
    *memoryOfInt = in;
    return memoryOfInt;

}
