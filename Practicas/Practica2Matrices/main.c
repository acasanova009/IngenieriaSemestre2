#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define Cua 4

void esMatrizTriangularInferior(int filas, int columnas, int* p);
void esMatrizTriangularSuperior(int filas, int columnas, int* p);
int esMatrizSimetrica(int filas, int columnas, int* p);
int esMatrizAntiSimetrica(int filas, int columnas, int* p);
void transponerMatriz(int filas, int columnas, int* p);
void transponerMatrizEnOtra(int filas, int columnas, int* p, int* q);
void imprimirMatriz(int filas, int columnas, int* p);
void llenarConAleatorios(int filas, int columnas, int* p);
void llenarConUsuario(int filas, int columnas, int* p);
void llenarConMismoValor(int valor, int filas, int columnas, int* p);


int main()
{
    
    
    //Original
    int matrizA[Cua][Cua];
    


    
    int * ptr_matrizA = &matrizA[0][0];
    

    llenarConUsuario(Cua , Cua, ptr_matrizA);

    printf("\n\nMatriz ingresada por usuario \n\nMatriz A");
    imprimirMatriz(Cua, Cua, ptr_matrizA);


    printf("\n\nTransponer la matruz A");
    transponerMatriz(Cua, Cua, ptr_matrizA);
    imprimirMatriz(Cua, Cua, ptr_matrizA);

    esMatrizSimetrica(Cua, Cua, ptr_matrizA);
    esMatrizAntiSimetrica(Cua, Cua, ptr_matrizA);
    esMatrizTriangularSuperior(Cua, Cua, ptr_matrizA);
    esMatrizTriangularInferior(Cua, Cua, ptr_matrizA);
    

    return 0;
}



void esMatrizTriangularInferior(int filas, int columnas, int* p){
    
    // int esAnti = 1;
     for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {   
            // int a =*( (p + i * columnas) + j);
            // int b = *( (p + j * columnas) + i) ;
            if(j>i){

                if (*( (p + i * columnas) + j)!=0){
                    // return 
                    printf("\n No es triangular inferior");
                    return;

                }
            }
            
        }
        
    } 
    printf("\n Si es triangular inferior");
    // return esAnti;
    return;
}

void esMatrizTriangularSuperior(int filas, int columnas, int* p){
    // int esAnti = 1;
     for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {   
            if(j==i){

                break;
            }
            if (*( (p + i * columnas) + j )!=0){
             
                printf("\n No es triangular superior");
                return;

            }
            
        }
        
    } 
    printf("\n Si es triangular superior");
    // return esAnti;
    return;
}

int esMatrizSimetrica(int filas, int columnas, int* p){
    int esSim = 1;
     for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {   
            int a =*( (p + i * columnas) + j);
            int b = *( (p + j * columnas) + i) ;
            if(a!=b){
                esSim = 0;
                printf("\n No es simetrica");
                return esSim;
            }
            
        }
        
    } 
    printf("\n Si es simetrica");
    return esSim;
}
int esMatrizAntiSimetrica(int filas, int columnas, int* p){
    int esAnti = 1;
     for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {   
            int a = -1* (*( (p + i * columnas) + j));
            int b = *( (p + j * columnas) + i) ;
            if(a!=b){
                esAnti = 0;
                printf("\n No es Antisimetrica");
                return esAnti;
            }
            
        }
        
    } 
    printf("\n Si es Antisimetrica");
    return esAnti;
}
void transponerMatriz(int filas, int columnas, int* p){

    int matrizTemp[filas][columnas]; //Va a desaparecer cuando termine esta funcion
    int *r = &matrizTemp[0][0];
    
    for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {
            // *( (q + j * columnas) + i)= *( (p + i * columnas) + j);
        *( (r + j * columnas) + i)= *( (p + i * columnas) + j);
        }
        
    } 

    for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {
            *( (p + i * columnas) + j)= *( (r+ i * columnas) + j);
        }
        
    } 

}
void transponerMatrizEnOtra(int filas, int columnas, int* p, int* q){

    // int matrizTemp[filas][columnas];
    // int *r = matrizTemp;
    
    for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {
            *( (q + j * columnas) + i)= *( (p + i * columnas) + j);
            // *( (r + j * columnas) + i)= *( (p + i * columnas) + j);
        }
        
    } 

    

}
void imprimirMatriz(int filas, int columnas, int* p)
{
    printf("\n");
    for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {
            printf("%d ", *( (p + i * columnas) + j)      );
            // printf("%d ", matrizA[i][j]);

            
        }
         printf("\n");
    }   
}

void llenarConAleatorios(int filas, int columnas, int* p)
{   
    time_t t;
    srand((unsigned) time(&t));
    for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {
            
            *( (p + i * columnas) + j) = (int) rand()%10;

        }
    }   
}

void llenarConUsuario(int filas, int columnas, int* p){
        // int esAnti = 1;

    printf("¿Porfavor ingresa los datos de la matriz 4x4?");

     for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {  
            int a = 0;
            printf("Ingresar dato de matriz");
            scanf("%d", &a);
             
           *( (p + i * columnas) + j) = a;
            
        }
        
    } 
    return;
}

void llenarConMismoValor(int valor, int filas, int columnas, int* p){
        // int esAnti = 1;
     for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {  
           
             
           *( (p + i * columnas) + j) = valor;
            
        }
        
    } 
    return;
}
