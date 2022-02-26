
#include <stdlib.h>


// typedef struct _ListEntry ListEntry;



typedef void *ListaValor;
typedef struct _Lista * Lista;
struct _Lista{
    ListaValor valorEspecial;
    int valor;
    Lista derecha;
    Lista izquierda;

};

void inicializarLista(Lista *p, int valor){
    Lista b = malloc(sizeof(Lista));
    


    b->valor = valor;
    // b->valorEspecial = valorEspecial;
    b->derecha = NULL;
    b->izquierda = NULL;

    *p = b; 

};

// void agregarElementoInicio(Lista *p, int valor){



//     Lista b;
    
//     b = malloc(sizeof(Pila));
//     b->valor = valor;
//     //  b->valorEspecial = valorEspecial;
//     b->ultimo =*p;
    
    

//     *p = b;
// };


// void agregarValorALista( ListaValor * nuevoValor, Lista lista ){


// }
// void iterarLista(ListaNodo *lista){

// }
