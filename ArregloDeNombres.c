#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarPersonas(char *vector[],int tamanio){
    printf("-----PERSONAS-----\n");
    for(int i=0; i<tamanio; i++){
        printf("\n\n%d)%s",(i+1),*(vector+i));
    }
}
int buscarNombrePorPalabra(char *vector[],char *pal){// con esta funcion consigo el indice de la palabra la cual imprimire en el main
    for (int i = 0; i < 5; i++)
    {
        if(strstr(*(vector+i),pal)){
            return i;
        }
    }
    return -1;
}


void buscarNombrePorId(char *vector[],int id){// tomo como id del primer nombre 1. id=1 entra a la componente v[0]
    if(id>=1 && id<=5){
        printf("El nombre con el id=%d es: %s",id , *(vector + (id -1)));
    }else{
        printf("No se encontro el valor buscado");
    }
}



int main(){
    char *V[5];
    char *buff;
    int opcion, id_buscar, indice;
    buff=(char *)malloc(100*sizeof(char));
    for(int i=0;i<5;i++){
        printf("\ningrese el %d nombre:", i+1);
        gets(buff);
        *(V + i)=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(*(V +i), buff);
    }
    printf("\n\n-----MENU DE BUSQUEDA");
    printf("\n1)Busqueda por ID");
    printf("\n2)Busqueda por palabra clave");
    printf("\nElija una opcion: ");
    scanf("%d",&opcion);
    getchar();//limpio el buffer
    if(opcion==1){
        printf("\nIngrese el id: ");
        scanf("%d", &id_buscar);
        buscarNombrePorId(V,id_buscar);
    }else if(opcion==2){
        printf("\nIngrese la palabra clave: ");
        gets(buff);
        indice=buscarNombrePorPalabra(V,buff);
        if(indice!=-1){
            printf("\n Nombre encontrado: %s",*(V+indice));
        }else{
            printf("\n -1");//no se encontraron coincidencias
        }
    }else{
        printf("\nOpcion no valida");

    }






    free(buff);
    for (int j = 0; j <5; j++)
    {
        free(*(V+j));
    }
    





    return 0;

}