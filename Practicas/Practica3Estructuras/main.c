#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "biblioteca.c"


 
void agregarLibrosPorUsuario(Libro *biblioteca[], int arrayIndex){


    //  Libro *nuevoLibro; 
    // crearLibro(&nuevoLibro, "AnotherBook PadrePobre", "Porrua", "Finanzas", 300);

    // biblioteca[arrayIndex]=nuevoLibro;

    

}
void agregarLibroPreestablecidos(Libro *biblioteca[]){

    Autor* nuevoAutor =malloc(sizeof(Autor)*MaximaCantidadAutores);
    crearAutor(&nuevoAutor, "Robert", "Kiyosaki", "USA");
    // crearAutor(&(nuevoAutor+sizeof(Autor)), "Kim", "Kiyosaki", "USA");


    Libro *nuevoLibro; 
    crearLibro(&nuevoLibro, "PadreRico PadrePobre", "Porrua", "Finanzas", 300, nuevoAutor);

    biblioteca[0]=nuevoLibro;
  
    // crearLibro(&nuevoLibro, "Babilonia ", "Pruden", "Dinero", 300);
   
    // biblioteca[1]=nuevoLibro;

}
int main(int argc, char const *argv[])
{
 
    Libro* miBiblioteca[5];
    
    agregarLibroPreestablecidos(miBiblioteca);
    agregarLibrosPorUsuario(miBiblioteca, 2);




    return 0;

}


// void desplegarTitulosDelLibros(Libro libros[], int totalDeLibros){
//     printf("\n\nBiblioteca actual \n");
//     for (size_t i = 0; i < totalDeLibros; i++)
//     {
//         printf("%d) Titulo:%s\n",i+1, libros[i].titulo);  
//     }
// }

// int pedirNumeroDeLibro(int maxLibros){
//     printf("\nPorfavor pedir un libro entre 1 y %d\n", maxLibros);
//     int numeroDeLibro;
//     scanf("%d", &numeroDeLibro);
//     return numeroDeLibro;
// }

// void leerInformacionDesdeUsuario(Libro libros[], int totalDeLibros ){

//     for (size_t i = 0; i < totalDeLibros; i++)
//     {

//         printf("Porfavor ingresa los datos del libro %d\n", i+1);
//             // Suponer que todas las memoria ya están alocadas en la ram.
//         printf("Ingresar el titulo de el libro \n");
//         scanf("%s", libros[i].titulo);
//         printf("Ingresar la editorial de el libro \n");
//         scanf("%s", libros[i].editorial);
//         printf("Ingresar el género de el libro \n");
//         scanf("%s", libros[i].genero);
//         printf("Ingresar el numero de paginas\n");
//         scanf("%d", &(libros[i].paginas));

//         //Se puso maixmo 3 autopes, ya que la esctururas Libro tiene un arreglo con 3 autors.
        

//         // for (size_t j = 0; j < 3; j++)
//         // {   
//         //     printf("Ingresar el nombre del autor de el libro \n");
//         //     scanf("%s", libros[i].autores[j].nombre);

            
//         //     printf("Ingresar el apellidos del autor de el libro \n");
//         //     scanf("%s", libros[i].autores[j].apellidos);
            
//         //     printf("Ingresar el pais del autor de el libro \n");
//         //     scanf("%s", libros[i].autores[j].pais);


//         //     printf("Ingresar el dia de nacimiento \n");
//         //     scanf("%d", &(libros[i].autores[j].nacimiento.dd));
//         //     printf("Ingresar el mes de nacimiento \n");
//         //     scanf("%d", &(libros[i].autores[j].nacimiento.mm));
//         //     printf("Ingresar el anio de nacimiento \n");
//         //     scanf("%d", &(libros[i].autores[j].nacimiento.aaaa));

//         // }

//         printf("Ingresar el dia de publicacion \n");
//         scanf("%d", &libros[i].publicacion.dd);
//         printf("Ingresar el mes de publicacion \n");
//         scanf("%d", &libros[i].publicacion.mm);
//         printf("Ingresar el anio de publicacion \n");
//         scanf("%d", &libros[i].publicacion.aaaa);
//     }
    



// }
// void desplegarInformacionDelLibro(Libro libros[], int numLibro){
//         numLibro--;
//         printf("***************************Los datos del libro %d son los siguientes\n\n\n",numLibro+1);
//             // Suponer que todas las memoria ya están alocadas en la ram.
//         printf("El titulo de el libro ");
//         printf("%s \n\n", libros[numLibro].titulo);
//         printf("La editorial de el libro ");
//         printf("%s \n\n", libros[numLibro].editorial);
//         printf("El género de el libro ");
//         printf("%s \n\n", libros[numLibro].genero);
//         printf("El numero de paginas");
//         printf("%d \n\n", (libros[numLibro].paginas));

//         //Se puso maixmo 3 autopes, ya que la esctururas Libro tiene un arreglo con 3 autors.
//         // for (size_t j = 0; j < 3; j++)
//         // {   
//         //     printf(" -------------------");
//         //     printf("    El nombre del autor de el libro");
//         //     printf("%s\n\n", libros[numLibro].autores[j].nombre);

            
//         //     printf("    El apellidos del autor de el libro");
//         //     printf("%s \n\n", libros[numLibro].autores[j].apellidos);
            
//         //     printf("    El pais del autor de el libro");
//         //     printf("%s \n\n", libros[numLibro].autores[j].pais);


//         //     printf("       El dia de nacimiento ");
//         //     printf("%d \n\n", (libros[numLibro].autores[j].nacimiento.dd));
//         //     printf("       El mes de nacimiento ");
//         //     printf("%d \n\n", (libros[numLibro].autores[j].nacimiento.mm));
//         //     printf("       El anio de nacimiento ");
//         //     printf("%d \n\n", (libros[numLibro].autores[j].nacimiento.aaaa));
//         //     printf(" -------------------");

//         // }

//             printf(" ***********");
//         printf("El dia de publicacion ");
//         printf("%d \n\n", libros[numLibro].publicacion.dd);
//         printf("El mes de publicacion ");
//         printf("%d \n\n", libros[numLibro].publicacion.mm);
//         printf("El anio de publicacion ");
//         printf("%d \n\n", libros[numLibro].publicacion.aaaa);
//             printf(" ***********");


// }
