#include <stdio.h>
#include <string.h>
#include <time.h>

#define Cua 4

void llenarConAleatorios(int filas, int columnas, int* p);

int main()
{
    
    printf("¿Porfavor ingresa los datos de la matriz 4x4?");
    //Original y simetrica
    int matrizA[Cua][Cua]= { 
            {0,-1,-2,-3},
            {1,0,-1,-2},
            {2,1,0,-1},
            {3,2,1,0}
    };
    //Numeros sin sentido.
    int matrizB[Cua][Cua] = { 
            {0,1,2,3},
            {4,5,2,3},
            {0,1,7,9},
            {0,1,8,3}
    };
    // Matriz nueva.
    int matrizC[Cua][Cua]= { 
            {3,1,2,3},
            {0,5,2,3},
            {0,0,7,9},
            {0,0,0,3}
    };
    int matrizD[Cua][Cua]= { 
            {3,1,2,3},
            {0,5,2,3},
            {0,0,7,9},
            {0,0,0,3}
    };

    int matrizF[Cua][Cua];

    llenarConMismoValor(-5, Cua, Cua, matrizF);
	printf("\n\nMatrizF");
    imprimirMatriz(Cua, Cua, matrizF);

    llenarConAleatorios(Cua, Cua, matrizF);
	printf("\n\nMatrizF");
    imprimirMatriz(Cua, Cua, matrizF);

    llenarConUsuario(Cua, Cua, matrizF);5
	printf("\n\nMatrizF");
    imprimirMatriz(Cua, Cua, matrizF);


    // imprimirMatriz(Cua,Cua, matrizA);
    
    
    // transponerMatrizEnOtra(Cua,Cua, matrizA, matrizB);
    // printf("\n\nMatrizB transpuesta de A");
    // printf("\n");
    // imprimirMatriz(Cua,Cua, matrizB);
    
    // printf("\n\nMatrizA sin modificar");
    // imprimirMatriz(Cua,Cua, matrizA);

    // printf("\n\nTransponer misma matriz");
    // transponerMatriz(Cua,Cua, matrizA);
    // imprimirMatriz(Cua,Cua, matrizA);

    // llenarConAleatorios(Cua, Cua, matrizA);

	// printf("\n\nMatrizA");
    // imprimirMatriz(Cua,Cua, matrizA);


    // printf("\n\nMatrizB");
    // imprimirMatriz(Cua,Cua, matrizB);
    // transponerMatrizEnOtra(Cua, Cua, matrizA, matrizB);

    
    // printf("\n\nMatrizA Transpuesta");
    // imprimirMatriz(Cua,Cua, matrizB);

    // esMatrizSimetrica(Cua,Cua, matrizB);
    // esMatrizAntiSimetrica(Cua,Cua, matrizB);

    // printf("\n\nMatrizC");
    // imprimirMatriz(Cua,Cua, matrizC);
    // esMatrizTriangularSuperior(Cua, Cua, matrizC);

    
    // printf("\n\nMatrizC Transpuesta");
    // transponerMatrizEnOtra(Cua,Cua, matrizC, matrizD);
    // imprimirMatriz(Cua,Cua, matrizD);

    // esMatrizTriangularSuperior(Cua, Cua, matrizD);
    // esMatrizTriangularInferior(Cua, Cua, matrizD);

  

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
            if(j<i || j==i){
                break;
                // esAnti = 0;
                // printf("\n No es simetrica");
                // return esAnti;
            }
            if (*( (p + i * columnas) + j)!=0){
                // return 
                printf("\n No es triangular inferior");
                return;

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
            // int a =*( (p + i * columnas) + j);
            // int b = *( (p + j * columnas) + i) ;
            if(j==i){
                break;
                // esAnti = 0;
                // printf("\n No es simetrica");
                // return esAnti;
            }
            if (*( (p + i * columnas) + j)!=0){
                // return 
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

    int matrizTemp[filas][columnas];
    int *r = matrizTemp;
    
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
            printf("%d ", *( (p + i * columnas) + j));
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
