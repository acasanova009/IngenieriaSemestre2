#include "myRandom.h"
#include "cliente.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Cliente* newCliente(int op, int time){
    Cliente * miNuevoCliente = malloc(sizeof(Cliente));

    miNuevoCliente->operacion = op;
    miNuevoCliente->minutosPorTardarse = time;

    return miNuevoCliente;
}

Cliente* newClienteRandom(){
    Cliente * miNuevoCliente = malloc(sizeof(Cliente));

    miNuevoCliente->operacion = randomNumberBetween(1,4);
    miNuevoCliente->minutosPorTardarse = randomNumberBetween(1,20);

    return miNuevoCliente;
}



char * opercionToString(int operacion){

    char * tipoDeOperacion = NULL;
    switch (operacion)
    {
    case 1:
        tipoDeOperacion = "SoporteTec";
        break;
    case 2:
        tipoDeOperacion = "Aclaracion";
        break;
    case 3:
        tipoDeOperacion = "Cotizacion";
        break;
    case 4:
        tipoDeOperacion = "Reparacion";
        break;
    
    default:

        break;
    }

    return tipoDeOperacion;
}

char* clienteToString(void *probableCliente){
    Cliente *clienteActual = (Cliente*)probableCliente;

    char * clienteEnString;

    int largeEnoughBufferLen = 40;

   clienteEnString = (char*)malloc(largeEnoughBufferLen * sizeof(char));

// sprintf(someStr, "formatted string: %s %s!", "Hello", "world");

    sprintf(clienteEnString,"Cliente[Op:%s Time:%i]",(char*)opercionToString(clienteActual->operacion), clienteActual->minutosPorTardarse  );

    return clienteEnString;
}
void clienteDisplay(void * mystery){

    Cliente *clienteActual = (Cliente*)mystery;
    printf("%s", clienteToString(clienteActual));
    

    // printf("Cliente[Op:%s Time:%i]",(char*)opercionToString(clienteActual->operacion), clienteActual->minutosPorTardarse );
}
