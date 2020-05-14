#include <stdio.h>
#include <stdlib.h>
 
typedef struct list{ //list es el nombre de la estructura
    int val;
    struct list *next; //El puntero siguiente para recorrer la lista enlazada
}pList; //pList es el tipo de dato para declarar la estructura
 
typedef pList *pPointer; //Puntero al tipo de dato pList para no utilizar punteros de punteros
 
void insertarEnLista (pPointer *initial, int e){
    pPointer nuevo; //Creamos un nuevo nodo
    nuevo = malloc(sizeof(pList)); //Utilizamos malloc para reservar memoria para ese nodo
    nuevo->val = e; //Le ponemos el val ingresado por pantalla a ese nodo
    nuevo->next = *initial; //Le ponemos al next el val de initial
    *initial = nuevo; //initial pasa a ser el ultimo nodo agregado
}
 
void imprimirLista(pPointer initial){
    while(initial != NULL){ //Mientras initial no sea NULL
        printf("%4d",initial->val); //Imprimimos el val del nodo
        initial = initial->next; //Pasamos al next nodo
    }
}
 
void borrarLista(pPointer *initial){ 
    pPointer actual; //Puntero auxiliar para eliminar correctamente la lista
    actual = *initial; //Actual toma el val de initial
    *initial = (*initial)->next; //initial avanza 1 posicion en la lista
    free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y initial queda apuntando al que ahora es el primero

}

int main(){
    int e;
    pPointer initial; //Indica la initial de la lista enlazada, si la perdemos no podremos acceder a la lista
    initial = NULL; //Se inicializa la initial como NULL ya que no hay ningun nodo cargado en la lista
    int op=0;
    while (op<4)
    {
        printf("1.- Ingresar elementos a la lista.\n");
        printf("2.- Eliminar elementos de la lista.\n");
        printf("3.- Ver elementos de la lista.\n");
        printf("4.- Salir\n");
        scanf("%d",&op);
        if (op==1)
        {
            system("cls");
            printf("Ingresar elementos a la Lista (-1 para terminar): ");
            scanf("%d",&e);
            
            while(e!=-1){
                insertarEnLista (&initial, e);
                printf ("Ingresado correctamente");
                printf ("\n");
                printf("Ingrese elementos, -1 para terminar: ");
                scanf("%d",&e);
            }
            printf ("\nLista: ");
            imprimirLista (initial);
            system ("PAUSE");
            system("cls");
        }

        if(op==2)
        {
            system("cls");
            printf ("\nBorrando el ultimo elemento ingresado\n");
            borrarLista (&initial);
            
            printf ("\nImprimir lista: ");
            imprimirLista (initial);
            printf ("\n");
            system ("PAUSE");
            system("cls");
        }
        if(op==3)
        {
            system("cls");
            printf ("\nImprimir lista: \n");
            imprimirLista (initial);
            printf ("\n");
            system ("PAUSE");
            system("cls");
        }
    }
     
return 0;
}
 
 
