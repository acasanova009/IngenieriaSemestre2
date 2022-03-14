#if !defined(CLIENTE_H)
#define CLIENTE_H



typedef struct{
    int operacion;
    int minutosPorTardarse;
}Cliente;

void clienteDisplay(void * self);
Cliente* newClienteRandom();

#endif // CLIENTE_H

