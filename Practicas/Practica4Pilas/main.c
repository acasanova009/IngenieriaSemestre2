#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "pila.c"
#include "libro.c"

 
void displayString(void *myMysteryValue){
    printf("%s\n",(char*)myMysteryValue);
}

int main(int argc, char const *argv[])
{
    
    char cartas[54][30] = {
        "El gallo","El diablito","La dama","El catrín", "El paraguas",  "La sirena",  "La escalera","La botella",   "El barril","El árbol","El melón","El valiente","El gorrito","La muerte","La pera","La bandera","El bandolón","El violoncello","La garza","El pájaro","La mano","La bota","La luna","El cotorro","El borracho","El negrito","El corazón","La sandía","El tambor","El camarón","Las jaras","El músico","La araña","El soldado","La estrella","El cazo","El mundo","El apache","El nopal","El alacrán","La rosa","La calavera","La campana","El cantarito","El venado","El sol","La corona","La chalupa","El pino","El pescado","La palma","La maceta","El arpa","La rana"};
    
    Pila *miPilaDeCartas;

    iniciarPila(&miPilaDeCartas);
   
     for (size_t i = 0; i < 54; i++){
    
        push(&miPilaDeCartas,*(cartas+i));
        
    }
     for (size_t i = 0; i < 5; i++){
        pop(&miPilaDeCartas);
    }
    iterarPila(&miPilaDeCartas, displayString);


    return 0;
}
