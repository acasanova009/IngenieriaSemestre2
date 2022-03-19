#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "filaCircular.h"
#include "myString.h"
void llenarLaFilaConUsuario(FilaCircular *fila);
void * menuParaPasarHaciaDerecha(FilaCircular *fila);

int main(int argc, char const *argv[])
{
    FilaCircular *fila = newFilaCircular();

    filaCircularPushEnd(fila, "Chicharito");
    filaCircularPushEnd(fila, "Hirving");
    filaCircularPushEnd(fila, "Ochoa");
    filaCircularPushEnd(fila, "Alexis");

    // pila
    
    // filaCircularPushEnd(fila, "Chicharito");
    // filaCircularPushEnd(fila, "Hirving");
    // filaCircularPushEnd(fila, "Ochoa");
    // filaCircularPushEnd(fila, "Alexis");

    // printf("Probando");

    // void * valorSeleccionado= NULL;

    // valorSeleccionado = menuParaPasarHaciaDerecha(fila);

    // printf("Su valor seleccionado es: \n");
    // stringDisplay(valorSeleccionado);

    
    

    return 0;
}

void * menuParaPasarHaciaDerecha(FilaCircular *fila){
    QueueNodoCircular * iterador = fila->cabeza;
    int desicionInt =-1;

    printf("Izquierda = 1; Derecha = 2; Seleccionar 0;");

    void* valorQueEligeElUsuario = NULL;

    do
    {       
        
        printf("Valor actual\n");
        iteradorFilaCircularDisplayValue(iterador, stringDisplay);
        printf("Izq, Der o Seleccionar\n");
        scanf("%d",&desicionInt);
        switch (desicionInt)
        {
        case 1:
            iteradorMoverAIzquierda(&iterador);
            break;
        case 2:
            iteradorMoverADerecha(&iterador);
            break;
        case 0:
            valorQueEligeElUsuario = iterador->valor;
            break;
        
        default:
            printf("Escribe 1 para izquierda, 2 para derecha, y 0 para seleccioanr");
            break;
        }

    } while (valorQueEligeElUsuario==NULL);

    return valorQueEligeElUsuario;
    

}
void llenarLaFilaConUsuario(FilaCircular *fila){
    int i = 0;
    // char * stringDelUsuario;
    do
    {   i++;
        printf("Ingresar mas datos\n");
    
        filaCircularPushEnd(fila, getLine());

    } while (i<5);

}


void pruebasExitosas(FilaCircular *fila){
    filaCircularPushEnd(fila, "Chicharito");
    filaCircularPushEnd(fila, "Hirving");
    filaCircularPushEnd(fila, "Ochoa");
    filaCircularPushEnd(fila, "Alexis");
    
    // printf("IterarFromTop:\n");
    // filaCircularIterarFromTop(fila, stringDisplay);
    
    // printf("\nIterarFromEnd:\n");
    // filaCircularIterarFromEnd(fila, stringDisplay);

    // printf("\n Y ahora manualmente\n");

    // QueueNodoCircular *iterador;
    // iterador = fila->cabeza;
    // for (int i = 0; i<6; i++){
    //     iteradorFilaCircularDisplayValue(iterador, stringDisplay);
    //     // iteradorMoverAIzquierda(&iterador);
    //     iteradorMoverADerecha(&iterador);
    // }

}