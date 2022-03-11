#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "global.c"
#include "listaDoble.c"
#include "punto.c"
#include "queue.c"
#include "pila.c"
#include "myString.c"
#include "fecha.c"


#include "cliente.c"
#include "moduloDeAtencion.c"

void agregarClienteAlModulo(Cliente * cliente, Modulo * modulo);



int main()
{
    // Semillas para randoms
    srand(time(NULL));
    

    Queue * listaDeClientes = newQueue();
    Modulo * modulos[4];

    // Agregarmos 50 clientes random
    for (size_t i = 0; i < 50; i++)
         queuePush(listaDeClientes, newClienteRandom());

    // Revisamos quienes son los clientes
    queueIterar(listaDeClientes,clienteDisplay);
   

    // Iniciamos los modulos.
    for (size_t i = 0; i < 4; i++)
    {
        modulos[i] = newModulo();
        modulos[i]->numeroDeModulo = i+1;
    }
    


    int minutoActual = 0;
    //Mientras haya personas en cola seguir iterando.
    while (!queueEstaVacia(listaDeClientes))
    {
       
        // Revisamos todos los modulos
        for (size_t i = 0; i < 4; i++) 
            if (moduloTieneTiempoParaAtender(modulos[i], minutoActual)){
                Cliente * nuestroClienteActual = queuePop(listaDeClientes);
                agregarClienteAlModulo(nuestroClienteActual,modulos[i]);
            }
        minutoActual+=1;

    }

    // Finalmente desplegar la informacion final de los modulos.
    for (size_t i = 0; i < 4; i++)
        moduloDisplay(modulos[i]);

    return 0;
}




void agregarClienteAlModulo(Cliente * cliente, Modulo * modulo){
    modulo->minutoDisponible += cliente->minutosPorTardarse+1;
    modulo->clientesAtendidos += 1;
    modulo->tiempoTotalDeServicio += cliente->minutosPorTardarse+1;
    
    switch (cliente->operacion)
    {
    case 1:
        modulo->operacion1+=1;
        break;
    case 2:
        modulo->operacion2+=1;
        break;
    case 3:
        modulo->operacion3+=1;
        
        break;
    case 4:
        modulo->operacion4+=1;
        break;
    
    default:
        printf("Operacion invalida. Cliente confundido.");
        break;
    }

}


