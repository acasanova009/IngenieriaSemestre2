#if !defined(CLIENTE_H)
#define CLIENTE_H

typedef struct{
    int operacion;
    int minutosPorTardarse;
}Cliente;



char* clienteToString(void *probableCliente);
char * opercionToString(int operacion);
Cliente* newClienteRandom();
Cliente* newCliente(int op, int time);


#endif // CLIENTE_H
