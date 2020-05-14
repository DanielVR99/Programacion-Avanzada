//Ejemplo 1
/*
#include <stdio.h>

int main(void)
{
    int *aPtr;
    int a = 10;

    aPtr = &a;

    printf("%p\n", &a); //Imprime dirección de a
    printf("%p\n", aPtr); //Imprime dirección de a
    printf("%p\n", &aPtr); //Imprime dirección del puntero
    printf("%d\n", *aPtr); //Imprime el valor de a
    return 0;
}*/


//Ejemplo 2
/*
#include <stdio.h>

int cubeByValue(int n)
{
    return n*n*n;
}

void cubeByReference(int *nPtr){
    *nPtr = (*nPtr)*(*nPtr)*(*nPtr);
}

int main(void){
    int n=3;
    printf("n al cubo es: %d\n", cubeByValue(n));
    printf("El valor de n es: %d\n\n", n);
    cubeByReference(&n);
    printf("El valor de n es: %d\n", n);
    printf("El valor de n es: %d\n\n", n);
}
*/

//Ejemplo 3
/*
#include "stdio.h"
#include "ctype.h"
void stringToUpperCase(char *sPtr) {
    while(*sPtr !=0) {
        *sPtr = toupper(*sPtr);
        ++sPtr; 
        } 
    }
int main(void) {
    char someString[] = "We all like programming in C.";
    printf("This is the original string: %s\n", someString);
    stringToUpperCase(someString);
    printf("This is the modified string: %s\n", someString); 
    }*/

//Ejemplo 4 Memoria dinámica

#include "stdio.h"
#include "stdlib.h"
typedef struct{
    void* data;
    struct ListNode* next;
    } ListNode;
int main(void) {
    ListNode* nodePtr = malloc(sizeof(ListNode));
    printf ("%p\n", nodePtr->next);
    printf ("%p\n", (*nodePtr).next);
    free(nodePtr); 
    }