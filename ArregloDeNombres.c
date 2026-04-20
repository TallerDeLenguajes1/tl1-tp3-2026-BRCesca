#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarPersonas(char *vector[],int tamanio){
    printf("-----PERSONAS-----\n");
    for(int i=0; i<tamanio; i++){
        printf("\n\n%d)%s",(i+1),*(vector+i));
    }
}

void buscarNombre(char *vector[],int id){// tomo como id del primer nombre 1. id=1 entra a la componente v[0]
    if(id>=1 && id<=5){
        printf("El nombre con el id=%d es: %s",id , *(vector + (id -1)));
    }else{
        printf("No se encontro el valor buscado");
    }
}



int main(){
    char *V[5];
    char *buff;
    int id_buscar;
    buff=(char *)malloc(100*sizeof(char));
    for(int i=0;i<5;i++){
        printf("\ningrese el %d nombre:", i+1);
        gets(buff);
        *(V + i)=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(*(V +i), buff);
    }
    mostrarPersonas(V,5);
    printf("\n\n Ingrese el id del nombre que desea buscar:");
    scanf("%d", &id_buscar);
    buscarNombre(V,id_buscar);









    free(buff);
    for (int j = 0; j <5; j++)
    {
        free(*(V+j));
    }
    





    return 0;

}