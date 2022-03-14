#if !defined(MODULODEATENCION_H)
#define MODULODEATENCION_H

#include <stdbool.h>

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

Modulo * moduloAlloc();

Modulo * moduloInit(Modulo* modulo);

Modulo * newModulo();

void moduloDisplay(void *mysteryModulo);

bool moduloTieneTiempoParaAtender(Modulo * modulo, int minutoActual);

void moduloRecibirCliente( Modulo * modulo,Cliente * cliente);


#endif // MODULODEATENCION_H

