#include "myRandom.c"
typedef struct{
    int operacion;
    int minutosPorTardarse;
}Cliente;



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

void clienteDisplay(void * mystery){
    Cliente *clienteActual = (Cliente*)mystery;

    printf("Cliente[Op:%s Time:%i]",(char*)opercionToString(clienteActual->operacion), clienteActual->minutosPorTardarse );
}