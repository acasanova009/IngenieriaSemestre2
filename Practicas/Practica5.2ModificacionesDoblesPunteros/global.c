#include <stdbool.h>



typedef void(*DISPLAY)(void*);
typedef int (*COMPARE)(void*, void*);

// #define DISPLAYSTRING
// #ifndef DISPLAYSTRING
// void displayString(void *myMysteryValue){
//     printf("%s\n",(char*)myMysteryValue);
// }
// #endif


// int (*f1)(double); // Passed a double and
// // returns an int
// void (*f2)(char*); // Passed a pointer to char and
// // returns void
// double* (*f3)(int, int); // Passed two integers and
// // returns a pointer to a double

// #define safeFree(p) saferFree((void**)&(p))

// void saferFree(void **pp) {
//     if (pp != NULL && *pp != NULL) {
//     free(*pp);
//     *pp = NULL;
//     }
// }

// The next sequence illustrates the use of this macro:
// int main() {
// int *pi;
// pi = (int*) malloc(sizeof(int));
// *pi = 5;
// printf("Before: %p\n",pi);
// safeFree(pi);
// printf("After: %p\n",pi);
// safeFree(pi);
// return (EXIT_SUCCESS);




// int square(int num) {
    // return num*num;
// }

// int (*fptr1)(int);

// int n = 5;
// fptr1 = square;
// printf("%d squared is %d\n",n, fptr1(n))




// int add(int num1, int num2) {
// return num1 + num2;
// }
// int subtract(int num1, int num2) {
// return num1 - num2;
// }

// typedef int (*fptrOperation)(int,int);

// int compute(fptrOperation operation, int num1, int num2) {

//     return operation(num1, num2);
// }

// fptrOperation select(char opcode) {
//     switch(opcode) {
//         case '+': return add;
//         case '-': return subtract;
//     }
// }

// int evaluate(char opcode, int num1, int num2) {
//     fptrOperation operation = select(opcode);
//     return operation(num1, num2);
// }

