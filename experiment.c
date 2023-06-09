#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Interes {
	char topic[20];
}Interes;

typedef struct Persona{
	
	char nombre[20];
	char pais[15];
	int edad;
	int num_contact;
	int num_intereces;
	int esYoutuber;
	char* Amigos;
	struct interes* intereses; 
}Persona;

typedef struct Comunidad{
	struct Persona* integrantes;
	int num_integrantes;
	int num_influencers;
	int total;
}Comunidad;

int main() {
	/*Persona p1;

	snprintf(p1.nombre, sizeof(p1.nombre), "Alberto");
	snprintf(p1.pais, sizeof(p1.pais), "Chile");
	p1.edad = 27;

	printf("Nombre :%s\n",p1.nombre );
	printf("Pais : %s\n", p1.pais );
	printf("Edad : %d\n", p1.edad );

	 while (fgets(buffer, MAX_LENGTH, fp))
	*/

	 char *filename = "text.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }
    //struct comunidad world ;
    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    int size;
    fscanf(fp, "%d", &size);
    struct Persona* world = malloc(size*sizeof(*world));




    printf("%d\n",size  );

    char buffer[MAX_LENGTH];


    for(int i = 0; i<size; i++){

    	Persona auxp;

    	fgets(buffer, MAX_LENGTH, fp);

    	char aux*;

    	int m* = 0;


		for(int m ; m < MAX_LENGTH; m++){
			if (buffer[m] == ' '){
				break;
			}
			else{
				&aux[m]= buffer[m];
			}

		}

		auxp.nombre = aux;
		m = m+1;
		char aux2*;

		for(m; m<MAX_LENGTH; m++){
			if (buffer[m] == ' '){
				break;
			}
			else{
				&aux2[m]= buffer[m];
			}

		}
		auxp.pais = aux2;
		m = m+1;




    }
    fgets(buffer, MAX_LENGTH, fp);
        printf("%s", buffer);

    fgets(buffer, MAX_LENGTH, fp);
        printf("%s", buffer);

    // close the file
    fclose(fp);

    return 0;
		return(0);
}