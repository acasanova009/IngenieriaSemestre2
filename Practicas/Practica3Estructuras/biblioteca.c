

#define MaximaCantidadAutores 3
typedef struct{
    int dd;
    int mm;
    int aaaa;
    
}Fecha;


typedef struct{
    char *nombre;
    char *apellidos;
    char *pais;
    Fecha nacimiento;

}Autor;


typedef struct{

    char * titulo;
    char *editorial;
    char *genero;
    int paginas;

    Autor *autores;
    Fecha *publicacion;
    
}Libro;





// Fecha crearFecha(int dia, int mes, int anio);
// Autor crearAutor(char * nombre, char * apellidos, char * pais,Fecha nacimiento);
// Libro crearLibro(char * titulo, char * editorial, char * genero, int paginas);

void crearAutor(Autor **autor,char * nombre , char * apellidos, char * pais){
    Autor *nuevoAutor = malloc(sizeof(Autor)*MaximaCantidadAutores);

    (*autor)= nuevoAutor;
    (*autor)->nombre = nombre;
    (*autor)->apellidos = apellidos;
    (*autor)->pais = pais;


}



void crearLibro(Libro **libro, char *titulo, char *editorial, char *genero, int paginas, Autor *autor){

    Libro* nuevoLibro = malloc(sizeof(Libro));
    
    (*libro)=nuevoLibro;

    (*libro)->titulo = titulo;
    (*libro)->editorial = editorial;
    (*libro)->genero = genero;
    (*libro)->paginas = paginas;
    (*libro)->autores = autor;

    // return *libro;
}

// // char * aStringFecha(Fecha fecha);
// char * aStringAutor(Autor autor);
// char * aStringLibro(Libro libro);
// char * aStringBiblioteca(Biblioteca biblioteca);

// void agregarLibroABiblioteca(Libro libro, Biblioteca *biblioteca);


// Biblioteca *crearBibliotecaConCuantosLibros(int cantidadDeLibros);
// Biblioteca *crearBibliotecaConCuantosLibros(int cantidadDeLibros){
    
//      return malloc(sizeof(Biblioteca)*cantidadDeLibros);
// }




