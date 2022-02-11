#include <stdio.h>
#include <string.h>

int main()
{
	char fraseIngresada[20];
	int cantidadVocales=0;
    
	printf("Ingrese una frase de máximo 20 caracteres\n");
	//_fpurge(stdin);
	fgets(fraseIngresada,20,stdin);
	for(int i=0;i<20;i++){
    	char vocalActual=fraseIngresada[i];
    	switch(vocalActual){
        	case 'a':
            	cantidadVocales++;
            	break;
        	case 'e':
            	cantidadVocales++;
            	break;
        	case 'i':
            	cantidadVocales++;
            	break;
        	case 'o':
            	cantidadVocales++;
            	break;
        	case 'u':
            	cantidadVocales++;
            	break;
        	default:
            	break;
       	 
    	}
   	 
	}
	printf("Cantidad de vocales:%i",cantidadVocales);

	return 0;
}

