
#if !defined(FILAITERADOR_H)
#define FILAITERADOR_H


#include "global.h"
#include "filaCircular.h"


// extern QueueNodoCircular *iterador;

bool iteradorTieneDerecha(QueueNodoCircular *iterador);
bool iteradorTieneIzquierda(QueueNodoCircular *iterador);

void  iteradorMoverADerecha(QueueNodoCircular **iterador);
void iteradorMoverAIzquierda(QueueNodoCircular **iterador);

void * iteradorMostrarValorActual(QueueNodoCircular *iterador, DISPLAY fdisp);

#endif // FILAITERADOR_H



