
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


