#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "filaCircular.h"
#include "filaIterador.h"
#include "myString.h"


int main(int argc, char const *argv[])
{
    FilaCircular *fila = newFilaCircular();

    filaCircularPushEnd(fila, "1");
    filaCircularPushEnd(fila, "2");
    filaCircularPushEnd(fila, "3");
    filaCircularPushEnd(fila, "4");
    

    QueueNodoCircular *iterador = fila->cabeza;
    for (int i = 0; i<21; i++){
        iteradorMostrarValorActual(iterador, stringDisplay);
        iteradorMoverAIzquierda(&iterador);
        iteradorMoverADerecha(&iterador);
    }




    return 0;
}


