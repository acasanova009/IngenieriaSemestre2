#if !defined(MYSTRING_H)
#define MYSTRING_H


char* getLine(void);

void setLine(char **myStringPoiner);

void stringDisplay(void *self);

int stringCompare(void *mysteryString1, void * mysteryString2);
void charDisplay(void *self);
int charCompare(void *self, void * anotherSelf);

void intDisplay(void *self);
int intCompare(void *self, void * anotherSelf);

char getRandomChar();
char * getRandomString();

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