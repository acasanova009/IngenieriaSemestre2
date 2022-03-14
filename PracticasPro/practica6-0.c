#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "global.h"
#include "filaDoble.h"


#include "cliente.h"
#include "moduloDeAtencion.h"



#define TotalDeModulos 5

int practica()
{
    // Semillas para randoms
    srand(time(NULL));
    

    FilaDoble * listaDeClientes = newFilaDoble();
    Modulo * modulos[TotalDeModulos];

    // Agregarmos 50 clientes random
    for (size_t i = 0; i < 50; i++)
         filaDoblePushTop(listaDeClientes, newClienteRandom());

    // Revisamos quienes son los clientes
    queueIterar(listaDeClientes,clienteDisplay);
   

    // Iniciamos los modulos.
    for (size_t i = 0; i < TotalDeModulos; i++)
    {
        modulos[i] = newModulo();
        modulos[i]->numeroDeModulo = i+1;
    }
    


    int minutoActual = 0;
    //Mientras haya personas en cola seguir iterando.
    while (!filaDobleEstaVacia(listaDeClientes))
    {
       
        // Revisamos todos los modulos
        for (size_t i = 0; i < TotalDeModulos; i++) 
            if (moduloTieneTiempoParaAtender(modulos[i], minutoActual)){
                Cliente * nuestroClienteActual = filaDoblePopEnd(listaDeClientes);
                moduloRecibirCliente(modulos[i],nuestroClienteActual);
            }
        minutoActual+=1;

    }

    // Finalmente desplegar la informacion final de los modulos.
    for (size_t i = 0; i < TotalDeModulos; i++)
        moduloDisplay(modulos[i]);

    return 0;
}



