#include "moduloDeAtencion.h"
#include "cliente.h"

#include <stdlib.h>
#include <stdio.h>

Modulo * moduloAlloc(){
    return malloc(sizeof(Modulo));
}

Modulo * moduloInit(Modulo* modulo){

    modulo->numeroDeModulo = 0;
    modulo->minutoDisponible = 0;
    modulo->clientesAtendidos = 0;
    modulo->tiempoTotalDeServicio = 0;
    modulo->operacion1 = 0;
    modulo->operacion2 = 0;
    modulo->operacion3 = 0;
    modulo->operacion4 = 0;

    return modulo;
}

Modulo * newModulo(){

    return moduloInit(moduloAlloc());
}

void moduloDisplay(void *mysteryModulo){
    Modulo * miModulo = (Modulo*)mysteryModulo;

    printf("\nModulo[#%d MinDisponible:%d ClientesAtendidos:%d TiempoTotalDeServicio: %d ]\n", miModulo->numeroDeModulo, miModulo->minutoDisponible,
    miModulo->clientesAtendidos,
    miModulo->tiempoTotalDeServicio);

    printf("Operaciones: SoporteTec:%d Aclaracion:%d Cotizacion:%d Reparacion:%d \n", miModulo->operacion1,miModulo->operacion2,miModulo->operacion3,miModulo->operacion4);
}

bool moduloTieneTiempoParaAtender(Modulo * modulo, int minutoActual){
    bool tieneTiempoDisponible = false;

    // Magia
    if (modulo->minutoDisponible == minutoActual )
    {
        tieneTiempoDisponible = true;
    }
    

    return tieneTiempoDisponible;
}


void moduloRecibirCliente( Modulo * modulo,Cliente * cliente){

    if (modulo == NULL || cliente == NULL)
    {
        return;
    }
    
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





