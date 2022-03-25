#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "filaDoble.h"
#include "listaDobleCircular.h"
#include "listaSimple.h"
#include "listaSimpleCircular.h"
#include "myString.h"
#include "fecha.h"




int main(int argc, char const *argv[])
{   
        
        srand(time(NULL));
        FilaDoble * ls = newFilaDoble();
        
        for (size_t i = 0; i < 10; i++)
            filaPushOrdenadamente(ls, newFechaRandom(), fechaCompare);
        
        filaDobleIterarFromTop(ls, fechaDisplay);



    
    // ListaSimpleCircular * ls = newListaSimple();
    
    // int a = 5;
    // int c = 6;

    // listaSimpleCircularAgregar(ls, &a);
    // listaSimpleCircularAgregar(ls, &c);
    // // listaSimpleCircularAgregar(ls, "b");
    // // listaSimpleCircularAgregar(ls, "Mango");

    
    

    // printf("Lista acutal:\n");
    // listaSimpleDisplay(ls, intDisplay);
    // printf("\n");

    // Nodo *iterador = (ls)->cabeza;

    // int temporalIndex = 0;
    // printf("ListaSimple con %d elementos.\n", ls->longitud);
    

    // listaSimpleEliminarValue(ls, "Mango", stringCompare);
    // listaSimpleEliminarValue(ls, "Arandanos", stringCompare);
    // listaSimpleEliminarValue(ls, "Pera", stringCompare);
    // listaSimpleEliminarValue(ls, "Naranja", stringCompare);
    // listaSimpleEliminarValue(ls, "Naranja", stringCompare);

    //  listaSimpleAgregar(ls, "Mango");
    //  listaSimpleAgregar(ls, "Mango");
    //  listaSimpleAgregar(ls, "Mango");

    // listaSimpleEliminarValue(ls, "Mango", stringCompare);


    // printf("Despues de eliminar\n");
    // listaSimpleDisplay(ls, stringDisplay);
    // printf("\n");


    
    // printf("\nContiene a Naranja");
    // if (listaSimpleContiene(ls, "Naranja", stringCompare))
    // {   
    //     printf("\n Si Contiene a Naranja con MASYUCULA");
    //     /* code */
    // }
    // printf("\nContiene a platano");
    // if (!listaSimpleContiene(ls, "platano", stringCompare))
    // {   
    //     printf("\n No contiene a platano con MINUSCULA");
    //     /* code */
    // }
    // printf("\nIndice de Naranja ");
    // if (listaSimpleContiene(ls, "Naranja", stringCompare))
    // {   
    //     printf("\n Es: %d", listaSimpleGetIndexByValue(ls, "Naranja", stringCompare));
    //     /* code */
    // }
    // printf("\nValue at index 3");
    // printf("\n Is %s", (char*)listaSimpleGetValueByIndex(ls, 3, stringCompare));
    // printf("\nValue at index 4");
    // printf("\n Is %s", (char*)listaSimpleGetValueByIndex(ls, 4, stringCompare));




    
    return 0;
}