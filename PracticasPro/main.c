#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "listaDoble.h"
#include "listaDobleCircular.h"
#include "myString.h"
#include "myNumbers.h"

typedef struct{
    int numeroAleatorio;
    char * color;
}Color;

void colorDisplay(void * self){
    Color *co = (Color *)self;
    printf("Numero Aleatorio: %d y Color: %s \n",co->numeroAleatorio,co->color);

}

Color * newColorRandom(){
    Color *c = malloc(sizeof(Color));
    c->numeroAleatorio = randomNumberBetween(1,15);
    int numeroDeColor = randomNumberBetween(1,4);
    char* finalColor = "";
    switch (numeroDeColor)
    {
    case 1:
        finalColor = "Azul";
        break;
    case 2:
        finalColor = "Morado";
        break;
    case 3:
        finalColor = "Gris";
        break;
    case 4:
        finalColor = "Rosa";
        break;
    
    default:
        finalColor = "error en numero de color";
        break;
    }
    c->color = finalColor;

    return c;
}
int menorLongiutd(int i, int j){
    int menor = i;
    if (j<i)
    {   menor = j;
    }
    
    return menor;
}

ListaDobleCircular * mezclar(ListaDoble * ls1, ListaDoble * ls2){

    ListaDobleCircular *ls3 = newListaDobleCircular();

    Nodo *iterador1 = (ls1)->cabeza;
    Nodo *iterador2 = (ls2)->rabo;


    int nodosPorIntercalar = menorLongiutd(ls1->longitud, ls2->longitud);

    printf("Nodos por intercalar son %d \n", nodosPorIntercalar);
    for (size_t i = 0; i < nodosPorIntercalar; i++)
    {
           
            listaDobleCircularAgregarFinal(ls3, iterador1->valor);
            listaDobleCircularAgregarFinal(ls3, iterador2->valor);
            nodoMoverADerecha(&iterador1);
            nodoMoverAIzquierda(&iterador2);

    }
    
    Nodo *iteradorContiniudad = iterador1;
    if (ls1->longitud < ls2->longitud)
    {
        iteradorContiniudad = iterador2;
    }
    
    while (iteradorContiniudad)
    {
        listaDobleCircularAgregarFinal(ls3, iteradorContiniudad->valor);
        if (ls1->longitud < ls2->longitud){

            nodoMoverAIzquierda(&iteradorContiniudad);    
        }
        else{
            nodoMoverADerecha(&iteradorContiniudad);    

        }
        
    }
    
    return ls3;


}


int main(int argc, char const *argv[])
{   
        
    srand(time(NULL));
    
    ListaDoble *ls1 = newListaDoble();
    ListaDoble *ls2 = newListaDoble();

    ListaDobleCircular *ls3 = newListaDobleCircular();

    int a = randomNumberBetween(2,3);
    int b = randomNumberBetween(5,7);


    for (size_t i = 0; i < a; i++)
        listaDobleAgregarFinal(ls1, newColorRandom());

    
    for (size_t i = 0; i < b; i++)
        listaDobleAgregarFinal(ls2, newColorRandom());
    
    
    listaDobleDisplay(ls1, colorDisplay);
    listaDobleDisplay(ls2, colorDisplay);

    ls3 = mezclar(ls1, ls2);
    listaDobleCircularDisplay(ls3, colorDisplay);
    

    
    return 0;
}