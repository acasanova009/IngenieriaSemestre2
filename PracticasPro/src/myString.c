#include "myString.h"
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

void stringDisplay(void *myMysteryValue){
    printf("%s\n",(char*)myMysteryValue);
}

int compareString(void *mysteryString1, void * mysteryString2){

    
    char * string1 = (char*)mysteryString1;
    char * string2 = (char*)mysteryString2;

    return strcmp(string1,string2);
}

// char* clienteToString(void *probableCliente){
//     Cliente *clienteActual = (Cliente*)probableCliente;

//     char * clienteEnString;

//     int largeEnoughBufferLen = 40;

//    clienteEnString = (char*)malloc(largeEnoughBufferLen * sizeof(char));

// // sprintf(someStr, "formatted string: %s %s!", "Hello", "world");

//     sprintf(clienteEnString,"Cliente[Op:%s Time:%i]",(char*)opercionToString(clienteActual->operacion), clienteActual->minutosPorTardarse  );

//     return clienteEnString;
// }