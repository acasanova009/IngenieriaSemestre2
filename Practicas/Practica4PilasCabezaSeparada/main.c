#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// #include "pila.c"
#include "queue.c"
#include "libro.c"

 
void displayString(void *myMysteryValue){
    printf("%s\n",(char*)myMysteryValue);
}

int main(int argc, char const *argv[])
{
    
    char cartas[54][30] = {
        "El gallo","El diablito","La dama","El catrín", "El paraguas",  "La sirena",  "La escalera","La botella",   "El barril","El árbol","El melón","El valiente","El gorrito","La muerte","La pera","La bandera","El bandolón","El violoncello","La garza","El pájaro","La mano","La bota","La luna","El cotorro","El borracho","El negrito","El corazón","La sandía","El tambor","El camarón","Las jaras","El músico","La araña","El soldado","La estrella","El cazo","El mundo","El apache","El nopal","El alacrán","La rosa","La calavera","La campana","El cantarito","El venado","El sol","La corona","La chalupa","El pino","El pescado","La palma","La maceta","El arpa","La rana"};

    Queue *myQueue;

    iniciarQueue(&myQueue);
    push(&myQueue, "hola");
    push(&myQueue, "adios");
    push(&myQueue, "goodbye");

    void * something = pop(&myQueue);
    printf("%s\n", something);
    something = pop(&myQueue);
    printf("%s\n", something);
    something = pop(&myQueue);
    printf("%s\n", something);

    
    // iterarQueue(&myQueue, displayString);



    // pop(&myQueue);
    // pop(&myQueue);
    // pop(&myQueue);

    // push(&myQueue, "goodbye");
    
    // Pila *miPilaDeCartas;

// iniciarPila(&miPilaDeCartas);
   
   
//    iterarPila(&miPilaDeCartas, displayString);
//     printf("Pila llenar con:\n");
//      for (size_t i = 0; i < 54; i++){
//         push(&miPilaDeCartas,*(cartas+i));  
//     }
        
    
//     iterarPila(&miPilaDeCartas, displayString);
//      for (size_t i = 0; i < 500; i++){
//         pop(&miPilaDeCartas);
//     }
//     printf("\n\nPila Vacia\n\n");

//     printf("Pila llenar segunda vez con:\n");
//      for (size_t i = 0; i < 2; i++){
    
//         push(&miPilaDeCartas,*(cartas+i));
        
        
//     }
//     iterarPila(&miPilaDeCartas, displayString);
    


    return 0;
}
