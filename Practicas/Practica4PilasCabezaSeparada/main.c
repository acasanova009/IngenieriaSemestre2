#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "pila.c"
#include "queue.c"
#include "libro.c"

 
void displayString(void *myMysteryValue){
    printf("%s\n",(char*)myMysteryValue);
}

int main(int argc, char const *argv[])
{
    
    char cartas[54][30] = {
        "El gallo","El diablito","La dama","El catrín", "El paraguas",  "La sirena",  "La escalera","La botella",   "El barril","El árbol","El melón","El valiente","El gorrito","La muerte","La pera","La bandera","El bandolón","El violoncello","La garza","El pájaro","La mano","La bota","La luna","El cotorro","El borracho","El negrito","El corazón","La sandía","El tambor","El camarón","Las jaras","El músico","La araña","El soldado","La estrella","El cazo","El mundo","El apache","El nopal","El alacrán","La rosa","La calavera","La campana","El cantarito","El venado","El sol","La corona","La chalupa","El pino","El pescado","La palma","La maceta","El arpa","La rana"};

    
    
    Pila *miPila;
    pilaIniciar(&miPila);
    for (size_t i = 0; i < 54; i++)
        pilaPush(&miPila, *(cartas+i));

    for (size_t i = 0; i < 500; i++)
        pilaPop(&miPila);
    

    for (size_t i = 0; i < 54; i++)
        pilaPush(&miPila, *(cartas+i));

    printf("Elementos del miPila\n");
    printf("%s\n", pilaPop(&miPila));
    printf("%s\n", pilaPop(&miPila));

    Queue* myQueue;
    queueIniciar(&myQueue);

    for (size_t i = 0; i < 54; i++)
        queuePush(&myQueue, *(cartas+i));

    for (size_t i = 0; i < 500; i++)
        queuePop(&myQueue);

    for (size_t i = 0; i < 54; i++)
        queuePush(&myQueue, *(cartas+i));


    printf("Elementos del queue\n");
    printf("%s\n", queuePop(&myQueue));
    printf("%s\n", queuePop(&myQueue));
       



    return 0;
}
