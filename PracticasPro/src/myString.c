#include "myString.h"
#include "myNumbers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



char* getLine(void) {
    const size_t sizeIncrement = 10;
    char* buffer = malloc(sizeIncrement);
    char* currentPosition = buffer;
    size_t maximumLength = sizeIncrement;
    size_t length = 0;
    int character;
    if(currentPosition == NULL) { return NULL; }
    while(1) {
        character = fgetc(stdin);
        if(character == '\n') { break; }
                if(++length >= maximumLength) {
                char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);
                if(newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;
        }
        *currentPosition++ = character;
    }
    *currentPosition = '\0';
    return buffer;
}

void setLine(char **myStringPoiner){
 *myStringPoiner = getLine();
}

void stringDisplay(void *self){
    printf("%s\n",(char*)self);
}

int stringCompare(void *mysteryString1, void * mysteryString2){

    int review = 0;
    char * string1 = (char*)mysteryString1;
    char * string2 = (char*)mysteryString2;
    review  = strcmp(string1,string2);
    return review;
}

void charDisplay(void *self){
    printf("%c\n",*((char*)self)); //
}

int charCompare(void *self, void * anotherSelf){

    int review = 0;
    char a = *((char*)self);
    char b = *((char*)anotherSelf);
    if(a>b){review = 1;}
    if(a<b){review = -1;}
    return review;

}

void intDisplay(void *self){
    printf("%i\n",*((int*)self)); //
}
int intCompare(void *self, void * anotherSelf){

    int review = 0;
    int a = *((int*)self);
    int b = *((int*)anotherSelf);
    if(a>b){review = 1;}
    if(a<b){review = -1;}
    return review;

}
// char getRandomChar(){
//     int random = 97 + randomNumberBetween(0,25);
//     char myNewChar = 97+'0';
//     return myNewChar;
// 
// }

// int integerCompare(void* i, void * j){
//     int *a = (int*)(i);
//     int *b = (int*)(j);

//     int result = 0;
//     if(*a < *b){result =-1;}else{result = 1;}

//     return result;
// }


// void integerDisplay(void * i){
//     int* temp = (int*)(i);
//     printf("%d\n", *temp);
// }


// int * newChar(int in){
//     int* memoryOfInt = (int*)malloc(sizeof(int));
//     *memoryOfInt = in;
//     return memoryOfInt;

// }
// char * getRandomString(){
//     int random = 97 + randomNumberBetween(0,25);
//     char myNewChar = (char)(97+'0');
//     char myString[1] ={myNewChar};

//     return myString;

// }

// char* clienteToString(void *probableCliente){
//     Cliente *clienteActual = (Cliente*)probableCliente;

//     char * clienteEnString;

//     int largeEnoughBufferLen = 40;

//    clienteEnString = (char*)malloc(largeEnoughBufferLen * sizeof(char));

// // sprintf(someStr, "formatted string: %s %s!", "Hello", "world");

//     sprintf(clienteEnString,"Cliente[Op:%s Time:%i]",(char*)opercionToString(clienteActual->operacion), clienteActual->minutosPorTardarse  );

//     return clienteEnString;
// }