
#if !defined(AUTOR_H)
#define AUTOR_H

#include "fecha.h"


typedef struct{
    char nombre[20];
    char apellidos[50];
    char pais[20];
    Fecha nacimiento;

}Autor;


#endif // AUTOR_H

