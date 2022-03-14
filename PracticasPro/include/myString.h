#if !defined(MYSTRING_H)
#define MYSTRING_H


char* getLine(void);

void setLine(char **myStringPoiner);

void displayString(void *myMysteryValue);

int compareString(void *mysteryString1, void * mysteryString2);

// char* clienteToString(void *probableCliente){
//     Cliente *clienteActual = (Cliente*)probableCliente;

//     char * clienteEnString;

//     int largeEnoughBufferLen = 40;

//    clienteEnString = (char*)malloc(largeEnoughBufferLen * sizeof(char));

// // sprintf(someStr, "formatted string: %s %s!", "Hello", "world");

//     sprintf(clienteEnString,"Cliente[Op:%s Time:%i]",(char*)opercionToString(clienteActual->operacion), clienteActual->minutosPorTardarse  );

//     return clienteEnString;
// }

#endif // MYSTRING_H