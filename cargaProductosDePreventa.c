#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





typedef struct Producto {
int productoId; //Numerado en ciclo iterativo
int cantidad; // entre 1 y 10
char *tipoProducto; // Algún valor del arreglo TiposProductos
float precioUnitario; // entre 10 - 100
}Producto;




typedef struct Cliente {
int clienteId; // Numerado en el ciclo iterativo
char *nombreCliente; // Ingresado por usuario
int cantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}Cliente;

float calcularCostoTotal(Producto *p){
    return ((p->cantidad)*(p->precioUnitario));
}
void mostrarClientes(Cliente *persona, int cantPersonas){// usare un procedimiento para mostrar lo que me piden en el enunciado 3)v)
    printf("\n---------LISTADO DE VENTA---------");
    for (int i = 0; i < cantPersonas; i++)
    {
        float totalFinalCliente=0;
        Cliente *actual=(persona + i);
        printf("=====================================================================");
        printf("\n\nCLIENTE: %s  .  ID: %d", actual->nombreCliente, actual->clienteId);
        for(int j=0;j<actual->cantidadProductosAPedir;j++){
            Producto *pActual=(actual->productos + j);
            float subTotal= calcularCostoTotal(pActual);//empleo la funcion que defini para calcular costos de un producto en especifico
            totalFinalCliente+=subTotal;
            printf("\n PRODUCTO: %s ||| CANTIDAD: %d ||| P.UNITARIO: %.2f ||| SUBTOTAL: %.2f ",pActual->tipoProducto, pActual->cantidad, pActual->precioUnitario, subTotal);
        }
        printf("\n------------------------------------------------------------------------");
        printf("\nTOTAL A PAGAR POR EL CLIENTE:   %.2f",totalFinalCliente);
        printf("\n------------------------------------------------------------------------");

    }
    
}



int main(){
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantidadClientes;
    char *buff=(char *)malloc(100*sizeof(char));
    srand(time(NULL));
    printf("\nIngrese la cantidad de clientes:");
    scanf("%d", &cantidadClientes);
    getchar();
    Cliente *listaClientes=(Cliente *)malloc(cantidadClientes*(sizeof(Cliente)));//reserva meomria en funcion de la cantidad de clientes que tenga
    for(int i=0;i<cantidadClientes;i++){
        (listaClientes + i)->clienteId= i+1;
        printf("\nIngrese el nombre del cliente: ");
        gets(buff);
        (listaClientes + i)->nombreCliente=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy((listaClientes+i)->nombreCliente, buff);
        printf("\nIngrese los productos que pedira: ");
        (listaClientes + i)->cantidadProductosAPedir=((rand()%5)+1);
        (listaClientes + i)->productos=(Producto *)malloc(((listaClientes + i)->cantidadProductosAPedir)*sizeof(Producto));
        for(int j=0;j<(listaClientes + i)->cantidadProductosAPedir;j++){
            Producto *pActual=(listaClientes + i)->productos + j;
            pActual->productoId=j+1;
            pActual->cantidad=(rand()%(10 - 1 + 1))+1;
            pActual->tipoProducto=TiposProductos[rand()%5];
            pActual->precioUnitario=(float)((rand()%(91))+10);
        }


    }
    mostrarClientes(listaClientes, cantidadClientes);// procedimiento que llama a la funcion calcularCostoTotal y me permite mostrar por pantalla toda la info solicitada
    
    //LIBERO MEMORIA
    for(int k=0;k<cantidadClientes;k++){
        free((listaClientes + k)->nombreCliente);
        free((listaClientes + k)->productos);
    }
    free(listaClientes);
    free(buff);



    return 0;
}