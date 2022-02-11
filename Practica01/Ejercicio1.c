#include<stdio.h>
/*
Programa que realiza la implementación de la escitala espartana
Para cifrar y descifrar.
*/
void crearMensaje();
void descifrarMensaje();
int main(){
       //First string

       char texto[100];

       for(int 0; i<100;i++ ){

           

       }

}

void crearMensaje(){
    int ren, col, i, j, k=0;
    printf("Ingresar el tamaño de la escítala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);
    printf("\nColumnas:");
    scanf("%i",&col);

    char escitala[ren][col];
    char texto[ren*col];

    printf("Escriba el texto a cifrar:\n");
    scanf("%s", texto);
    for (i=0 ; i<ren ; i++)
    for (j=0 ; j<col ; j++)
    escitala[i][j] = texto[k++];

    printf("El texto en la tira queda de la siguiente manera:\n");
    for (i=0 ; i<col ; i++)
    for (j=0 ; j<ren ; j++)
    printf("%c", escitala[j][i]);
    printf("\n");
}
    
void descifrarMensaje(){
    int ren, col, i, j, k=0;
    
    printf("Ingresar el tamaño de la escítala:\n");
    printf("\nRenglones:");
    scanf("%i",&ren);
    printf("\nColumnas:");
    scanf("%i",&col);
    char escitala[ren][col];
    char texto[ren*col];

    printf("Escriba el texto a descifrar:\n");
    scanf("%s", texto);
    for (i=0 ; i<col ; i++)
        for (j=0 ; j<ren ; j++)
        escitala[j][i] = texto[k++];

    printf("El texto descifrado es:\n");
    for (i=0 ; i<ren ; i++)
        for (j=0 ; j<col ; j++)
            printf("%c", escitala[i][j]);
}