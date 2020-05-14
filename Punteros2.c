#include <stdio.h>
#include <stdlib.h>

typedef struct{
    void* value;
}QueueNode;

typedef struct{
    QueueNode* arr;
} Queue;

Queue* initializeQueue() {
    Queue* queuePtr = (Queue*)malloc(sizeof(Queue));
    queuePtr->arr = (QueueNode*)calloc(100, sizeof(QueueNode));
    return queuePtr;
}

void freeQueue(Queue* queuePtr){
    free(queuePtr->arr);
    free(queuePtr);
}

void ingresarValor(Queue* queuePtr, int val, int pos)
{
    //Queue* queuePtr = initializeQueue();
    /*if(val!=-1)
        queuePtr->arr[pos].value =&val;
    else*/
    queuePtr->arr[pos].value = &val;

    printf("Element %d: %d\n",pos, *((int*)queuePtr->arr[pos].value));
    //printf("Element %d: %d\n",pos-1, *((int*)queuePtr->arr[pos].value));
}

int main(void) {
    int pos=0, val;
    Queue* queuePtr = initializeQueue();
    while(val != -1)
    {
        //int val;
        printf("ingresar valor para la lista: (-1 para salir)");
        scanf("%d",&val); 
        ingresarValor(queuePtr, val, pos);
        pos++;
    }
    
    printf("Element 0: %d\n", *((int*)queuePtr->arr[0].value));
    printf("Element 1: %d\n", *((int*)queuePtr->arr[1].value));
    printf("Element 2: %d\n", *((int*)queuePtr->arr[2].value));
    freeQueue(queuePtr);
}
