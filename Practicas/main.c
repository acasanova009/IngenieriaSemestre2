       	 
#include <stdio.h>
#include <string.h>

#include <time.h>


#define ok(i, j) *( (p + i* columnas) + j)

#define Cuatro 4

int main()
{
    // int col, filas, menu;
    // time_t t;
    // srand((unsigned) time(&t));
    
    printf("¿Porfavor ingresa los datos de la matriz 4x4?");
    int matrizA[Cuatro][Cuatro];
    int matrizB[Cuatro][Cuatro] = { 
            {0,1,2,3},
            {4,5,2,3},
            {0,1,7,9},
            {0,1,8,3}
    };
    int matrizC[Cuatro][Cuatro];

	int *ptr_MatrizA, *ptr_MatrizB;
	ptr_MatrizA = matrizA;
	ptr_MatrizB = matrizB;
	// columna = 

	// for (int i = 0; i < Cuatro; i++)
	// {
	// 	for (int j = 0; j < Cuatro; j++)
	// 	{
	// 		int temporal = 0;
	// 		// scanf("%d", &temporal);
	// 		matrizA[i][j] = rand() %10;
	// 	}
		
	// }

    imprimir(Cuatro,Cuatro, matrizB);

	// Primer indice es ptr_MatrizA


	for (int i = 0 ; i < Cuatro; i++)
	{
		for (int j  = 0; j < Cuatro; j++)
		{
				// matrizB[j][i]=matrizA[i][j];
				// ()=matrizA[i][j];
                
                asignarValorCorchetes(ptr_MatrizA, j,i, corchetes(ptr_MatrizB, i, j));
				

				

		}
		
	}
	
    imprimir(Cuatro,Cuatro, matrizA);

    return 0;
}
void asignarValorCorchetes(int * p, int i, int j, int valorPorAsignar){
    *((p + i*Cuatro) + j) = valorPorAsignar;

}
int corchetes(int * p, int i, int j)
{
    return *((p + i*Cuatro) + j);
}

void imprimir(int filas, int columnas, int* p)
{
    printf("\n");
    for(int i = 0; i != filas; ++i)
    {   

        for(int j = 0; j != columnas; ++j)
        {

            // printf("%d ", *( (p + i * columnas) + j));
            printf("%d ", ok(i,j));
        }
         printf("\n");
    }   
}

	
