#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarPersonas(char *vector[],int tamanio){
    printf("-----PERSONAS-----\n");
    for(int i=0; i<tamanio; i++){
        printf("\n\n%d)%s",(i+1),*(vector+i));
    }
}

int main(){
    char *V[5];
    char *buff;
    buff=(char *)malloc(100*sizeof(char));
    for(int i=0;i<5;i++){
        printf("\n\ningrese el %d nombre:", i+1);
        gets(buff);
        *(V + i)=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(*(V +i), buff);
    }
    mostrarPersonas(V,5);


    free(buff);
    for (int j = 0; j <5; j++)
    {
        free(*(V+j));
    }
    





    return 0;

}