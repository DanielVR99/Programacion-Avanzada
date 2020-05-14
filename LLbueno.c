#include <stdio.h>
#include <stdlib.h>
 
typedef struct list{ 
    int val;
    struct list *next; 
}pList; 
 
typedef pList *pPointer; 
 
void insertarEnLista (pPointer *initial, int e){
    pPointer nuevo; 
    nuevo = malloc(sizeof(pList)); 
    nuevo->val = e;
    nuevo->next = *initial; 
    *initial = nuevo; 
}
 
void imprimirLista(pPointer initial){
    while(initial != NULL){ 
        printf("%4d",initial->val); 
        initial = initial->next; 
    }
}
 
void borrarLista(pPointer *initial){ 
    pPointer actual; 
    actual = *initial;
    *initial = (*initial)->next; 
    free(actual); 
}

int main(){
    int e;
    pPointer initial; 
    initial = NULL;
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
 
 
