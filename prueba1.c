#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Interes {
	char topic[20];
}Interes;



typedef struct Nomb {
	char nombre[20];
}Nombre;

typedef struct Persona{
	
	char nombre[20];
	char pais[20];
	int edad;
	int num_contact;
	int num_intereces;
	int esYoutuber;
	struct Nomb* Amigos;
	struct Interes* intereses; 
}Persona;

typedef struct Comunidad{
	struct Persona* integrantes;
	int num_integrantes;
	int num_influencers;
	int total;
}Comunidad;


void EliminarElementoArray(int arr[], int size, int elem){
    int i;
    for(i= elem; i<size-1; i+=1){
        arr[i]= arr[i+1];
    }
    size-=1;
}
int main() {
	char *filename = "text.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Error: could not open file %s", filename);
        return 1;
   
    }

    const unsigned MAX_LENGTH = 256;
    int size;
    fscanf(fp, "%d", &size);
    printf("%d\n",size  );

	char buffer[MAX_LENGTH];
	 
    //struct Persona* world = malloc(size*sizeof(*world));
    //printf("%d\n",size  );


 Persona usuarios[size];
    for(int i = 0; i<size; i++){
    	char nombre[20];
    	char pais[20];
    	int edad;
    	int influencer;
    	fscanf(fp, "%s" "%s" "%d" "%d", nombre, pais, &edad, &influencer);
    	strcpy(usuarios[i].nombre , nombre);
    	strcpy(usuarios[i].pais , pais);
    	usuarios[i].edad = edad;
    	usuarios[i].esYoutuber = influencer;

    	fgets(buffer, MAX_LENGTH, fp);

    	int num_contactos;
     	fscanf(fp, "%d", &num_contactos);

     	usuarios[i].num_contact = num_contactos;
     	usuarios[i].Amigos = malloc(num_contactos*sizeof(struct Nomb));
		for(int m = 0; m < num_contactos; m++){
			char nAmix[20];
			fscanf(fp, "%s", nAmix);
			strcpy(usuarios[i].Amigos[m].nombre , nAmix);

		}

		fgets(buffer, MAX_LENGTH, fp);

		int num_inter;
     	fscanf(fp, "%d", &num_inter);

     	usuarios[i].num_intereces = num_inter;
     	usuarios[i].intereses = malloc(num_inter*sizeof(struct Interes));


     	for(int m = 0; m < num_inter; m++){
     		char topic[20];
			fscanf(fp, "%s", topic);
			strcpy(usuarios[i].intereses[m].topic , topic);
		}
		fgets(buffer, MAX_LENGTH, fp);

		printf("Nombre : %s \n", usuarios[i].nombre);
		printf("Pais de origen: %s \n", usuarios[i].pais);
		printf("Edad : %d \n", edad);

		printf("Amigos : ");
		for(int k = 0; k< usuarios[i].num_contact; k++){
			printf("%s ", usuarios[i].Amigos[k].nombre);
		}
		printf("\nInteres : ");
		for(int q = 0; q< usuarios[i].num_intereces; q++){
			printf("%s ", usuarios[i].intereses[q].topic);
		}
		printf("\n");
		free(usuarios[i].intereses);
		free(usuarios[i].Amigos);
		printf("\n");
		printf("\n");


 }

//menu:
int arrPos[size];
int n = 40;
int count=0;
//ver cada critetrio de busqueda para ver qué personas se quedan
printf("Ingrese los criterios de busqueda\n");
//pais:
char country[n];
printf("Ingrese el pais, (si no es importante ingrese -1):\n");
scanf("%s", &country);
if(country!="-1"){
 
    for (int i = 0; i < size; i++)
    {
        if(usuarios[i].pais==country){
            arrPos[count]=i;
            count++;
        }
    }
}
//edad minima:
int min;
printf("Ingrese la edad minima, (si no es importante ingrese 0):\n");
scanf("%d", &min);
if(min!=0){
    for (int i = 0; i < size; i++)
    {
        if(usuarios[i].edad=min){
            for (int a = 0; a < count; a++)
            {
                if(arrPos[a]!=i){
                    arrPos[count]=i;
                    count++;
                }
            }
            
        }
    }
}
//edad maxima:
int max;
printf("Ingrese la edad maxima, (si no es importante ingrese 120):\n");
scanf("%d", &max);
if(max!=120){
    if(max!=0){
    for (int i = 0; i < size; i++)
    {
        if(usuarios[i].edad=max){
            for (int a = 0; a < count; a++)
            {
                if(arrPos[a]!=i){
                    arrPos[count]=i;
                    count++;
                }
            }
            
        }
    }

    }
}
//interes:
char hobby[n];
printf("Ingrese el interes, (si no es importante ingrese -1):\n");
scanf("%s", &hobby);
if(hobby!="-1"){
    for (int i = 0; i < size; i++){
        for (int a = 0; a < usuarios[i].num_intereces; a++)
        {
            if(usuarios[i].intereses[a].topic==hobby){
                arrPos[count]=i;
                count++;
            }        
        }
    }
}

int x;
scanf("%d", &x);

return(0);
}