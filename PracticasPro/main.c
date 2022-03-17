#include "filaDoble.h"
#include "myString.h"


int main(int argc, char const *argv[])
{
    FilaDoble *fila = newFilaDoble();
    filaDoblePushTop(fila, "hola");
    filaDoblePushTop(fila, "hola");
    filaDoblePushTop(fila, "hola");
    filaDoblePushTop(fila, "adios");

    filaDobleIterarFromTop(fila, stringDisplay);

    
    return 0;
}


