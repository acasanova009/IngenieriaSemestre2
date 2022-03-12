
#include <stdbool.h>
#include "cliente.h"


typedef struct {
    int numeroDeModulo;
    int minutoDisponible;
    int clientesAtendidos;
    int tiempoTotalDeServicio;

    int operacion1;
    int operacion2;
    int operacion3;
    int operacion4;

}Modulo;

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


void agregarClienteAlModulo(Cliente * cliente, Modulo * modulo){

    if (modulo == NULL || cliente == NULL)
    {
        return;
    }
    
    modulo->minutoDisponible += cliente->minutosPorTardarse+1;
    modulo->clientesAtendidos += 1;
    modulo->tiempoTotalDeServicio += cliente->minutosPorTardarse+1;

}


