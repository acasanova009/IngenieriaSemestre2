#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


typedef struct{
    int dd;
    int mm;
    int aaaa;
    
}Fecha;


typedef struct{
    char nombre[20];
    char apellidos[50];
    char pais[20];
    Fecha nacimiento;

}Autor;


typedef struct{

    char titulo[20];
    char editorial[20];
    char genero[20];
    int paginas;

    Autor autores[3];
    Fecha publicacion;
    
}Libro;


#define TotalDeLibros 3
#define TotalDeAutores 3

void leerInformacionDesdeUsuario(Libro libros[], int totalDeLibros);
void desplegarTitulosDelLibros(Libro libros[], int totalDeLibros);
void desplegarInformacionDelLibro(Libro libros[],int num);
int pedirNumeroDeLibro(int maxLibros);
 

int main()
{

    Libro misLibros[TotalDeLibros];

    leerInformacionDesdeUsuario(misLibros, TotalDeLibros);

    
    while (1)
    {
        desplegarTitulosDelLibros(misLibros, TotalDeLibros);
        printf("Ingrese un numero del menu\n\n");    
        int numeroDeLibro = pedirNumeroDeLibro(TotalDeLibros);
        desplegarInformacionDelLibro(misLibros, numeroDeLibro);
    }
    
  
   
    return 0;
}
void desplegarTitulosDelLibros(Libro libros[], int totalDeLibros){
    printf("\n\nBiblioteca actual \n");
    for (size_t i = 0; i < totalDeLibros; i++)
    {
        printf("%d) Titulo:%s\n",i+1, libros[i].titulo);  
    }
}

int pedirNumeroDeLibro(int maxLibros){
    printf("\nPorfavor pedir un libro entre 1 y %d\n", maxLibros);
    int numeroDeLibro;
    scanf("%d", &numeroDeLibro);
    numeroDeLibro -=1;
    return numeroDeLibro;
}

void leerInformacionDesdeUsuario(Libro libros[], int totalDeLibros ){

    for (size_t i = 0; i < totalDeLibros; i++)
    {

        printf("Porfavor ingresa los datos del libro %d\n", i+1);
            // Suponer que todas las memoria ya están alocadas en la ram.
        printf("Ingresar el titulo de el libro \n");
        scanf("%s", libros[i].titulo);
        printf("Ingresar la editorial de el libro \n");
        scanf("%s", libros[i].editorial);
        printf("Ingresar el género de el libro \n");
        scanf("%s", libros[i].genero);
        printf("Ingresar el numero de paginas\n");
        scanf("%d", &(libros[i].paginas));

        
        

        for (size_t j = 0; j < TotalDeAutores; j++)
        {   
            printf("Ingresar el nombre del autor de el libro \n");
            scanf("%s", libros[i].autores[j].nombre);

            
            printf("Ingresar el apellidos del autor de el libro \n");
            scanf("%s", libros[i].autores[j].apellidos);
            
            printf("Ingresar el pais del autor de el libro \n");
            scanf("%s", libros[i].autores[j].pais);


            printf("Ingresar el dia de nacimiento \n");
            scanf("%d", &(libros[i].autores[j].nacimiento.dd));
            printf("Ingresar el mes de nacimiento \n");
            scanf("%d", &(libros[i].autores[j].nacimiento.mm));
            printf("Ingresar el anio de nacimiento \n");
            scanf("%d", &(libros[i].autores[j].nacimiento.aaaa));

        }

        printf("Ingresar el dia de publicacion \n");
        scanf("%d", &libros[i].publicacion.dd);
        printf("Ingresar el mes de publicacion \n");
        scanf("%d", &libros[i].publicacion.mm);
        printf("Ingresar el anio de publicacion \n");
        scanf("%d", &libros[i].publicacion.aaaa);
    }
    



}
void desplegarInformacionDelLibro(Libro libros[], int numLibro){
        
        printf("Los datos del libro %d son los siguientes\n\n\n",numLibro+1);
            // Suponer que todas las memoria ya están alocadas en la ram.
        printf("El titulo de el libro ");
        printf("%s \n\n", libros[numLibro].titulo);
        printf("La editorial de el libro ");
        printf("%s \n\n", libros[numLibro].editorial);
        printf("El género de el libro ");
        printf("%s \n\n", libros[numLibro].genero);
        printf("El numero de paginas");
        printf("%d \n\n", (libros[numLibro].paginas));

        // Se puso maixmo 3 autopes, ya que la esctururas Libro tiene un arreglo con 3 autors.
        for (size_t j = 0; j < TotalDeAutores; j++)
        {   
            printf(" -------------------");
            printf("    El nombre del autor de el libro");
            printf("%s\n\n", libros[numLibro].autores[j].nombre);

            
            printf("    El apellidos del autor de el libro");
            printf("%s \n\n", libros[numLibro].autores[j].apellidos);
            
            printf("    El pais del autor de el libro");
            printf("%s \n\n", libros[numLibro].autores[j].pais);


            printf("       El dia de nacimiento ");
            printf("%d \n\n", (libros[numLibro].autores[j].nacimiento.dd));
            printf("       El mes de nacimiento ");
            printf("%d \n\n", (libros[numLibro].autores[j].nacimiento.mm));
            printf("       El anio de nacimiento ");
            printf("%d \n\n", (libros[numLibro].autores[j].nacimiento.aaaa));
            printf(" -------------------");

        }

            printf(" ***********");
        printf("El dia de publicacion ");
        printf("%d \n\n", libros[numLibro].publicacion.dd);
        printf("El mes de publicacion ");
        printf("%d \n\n", libros[numLibro].publicacion.mm);
        printf("El anio de publicacion ");
        printf("%d \n\n", libros[numLibro].publicacion.aaaa);
            printf(" ***********");


}

