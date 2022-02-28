#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "listaDoble.c"
#include "punto.c"



int main()
{

    ListaDoble * listaDobleDePuntos;
    ListaDoble * listaDobleDePuntos2;
    Punto * unPunto;

    inicializarPunto(&unPunto, 1, 2, 3);    
    inicializarListaDoble(&listaDobleDePuntos,unPunto);
    inicializarPunto(&unPunto, 1, 2, 3);    
    inicializarListaDoble(&listaDobleDePuntos2,unPunto);


    for (size_t i = 1; i < 50; i++)
    {
        
        inicializarPunto(&unPunto, i, i, i);    
        agregarInicio(&listaDobleDePuntos,unPunto); 
        inicializarPunto(&unPunto, i, i, i);    
        agregarInicio(&listaDobleDePuntos2,unPunto); 
        
        
    }
    

    // for (size_t i = 0; i < 32; i++)
    // {
    //     eliminarFinal(&listaDobleDePuntos);
    // }
    
    
    
    toString(&listaDobleDePuntos, (void*)displayPunto);
    iterar(&listaDobleDePuntos, (void*)displayPunto);

    return 0;
}

