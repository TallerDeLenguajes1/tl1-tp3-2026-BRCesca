#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarPersonas(char *vector[],int tamanio){
    printf("-----PERSONAS-----\n");
    for(int i=0; i<tamanio; i++){
        printf("\n\n%d)%s",(i+1),*(vector+i));
    }
}
int buscarNombre(char *vector[],char *pal){// con esta funcion consigo el indice de la palabra la cual imprimire en el main
    for (int i = 0; i < 5; i++)
    {
        if(strstr(*(vector+i),pal)){
            return i;
        }
    }
    return -1;
}


int main(){
    char *V[5];
    char *buff;
    int id_del_nombre;
    buff=(char *)malloc(100*sizeof(char));
    for(int i=0;i<5;i++){
        printf("\n\ningrese el %d nombre:", i+1);
        gets(buff);
        *(V + i)=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(*(V +i), buff);
    }
    mostrarPersonas(V,5);
    printf("\nIngrese la palabra clave para buscar:");
    gets(buff);
    id_del_nombre= buscarNombre(V,buff);
    if(id_del_nombre!=-1){
        printf("\nPalabra clave ingresada: %s\nNombre obtenido:%s",buff, *(V+id_del_nombre));
    }else{
        printf("No se encontraron nombres relacionados con la palabra clave ingresada");
    }


    free(buff);
    for (int j = 0; j <5; j++)
    {
        free(*(V+j));
    }
    





    return 0;

}