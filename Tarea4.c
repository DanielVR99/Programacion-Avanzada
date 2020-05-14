 //Tarea 4
//Daniel Alejandro Villegas Romero A01365286
//Raúl Iván Ávalos Muñoz Ledo A01364940

#include <stdio.h>
#include <stdlib.h>
//Ejercicio 1-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/*
int main(){
    int i,j;
    int filas, colum;
    int **m1;
    int **m2;
    int **m3;
    //Matriz 1
    printf("Introduce el numero de filas: ");
    scanf("%i",&filas);

    printf("Introduce el numero de columnas: ");
    scanf("%i",&colum);

    m1=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m1[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){
            scanf("%i",&m1[i][j]);
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<colum;j++){
            printf("%i ",m1[i][j]);
        }
        printf("\n");
    }
    //Matriz 2
    printf("Ingrese la segunda matriz: ");
    m2=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m2[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){
            scanf("%i",&m2[i][j]);
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<colum;j++){
            printf("%i ",m2[i][j]);
        }
        printf("\n");
    }
    //Matriz 3
    printf("La suma de las matrices: \n");

    m3=(int **)malloc(filas*sizeof(int *));

    for(i=0;i<filas;i++){
        m3[i] =(int *)malloc(colum*sizeof(int));
        for(j=0;j<colum;j++){   
            m3[i][j]=m2[i][j]+ m1[i][j];
            printf("%i ",m3[i][j]);
        }
        printf("\n");
    }

    printf("Dir de matriz 3: %i",&m3);

    return 0;
}*/

//Ejercicio 2-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/*
void sort(int n, int* ptr) 
{ 
    int i, j, t; 

    // Sort the numbers using pointers 
    for (i = 0; i < n; i++) { 

        for (j = i + 1; j < n; j++) { 

            if (*(ptr + j) < *(ptr + i)) { 

                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 

    // print the numbers 
    for (i = 0; i < n; i++) 
        printf("%d ", *(ptr + i)); 
} 
    

int main(){
   
    int n,i;
    int *arr;
    printf("Cuantos numeros va a ingresar: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        scanf("%i",&arr[i]);
    }
    sort(n,arr); 
    return 0; 

}
*/

//Ejercicio 3-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodoQueue
{
    char nombre[20];
    
    struct nodoQueue *next;
    struct nodoQueue *prev;
};


struct nodoQueue *primero=NULL, *actual=NULL, *ultimo=NULL, *anterior=NULL;

void push(char nom[])
{
	//actual = malloc(sizeof(struct nodoQueue));
	actual = (struct nodoQueue*) malloc(sizeof(struct nodoQueue));
	
	strcpy(actual->nombre,nom);
	
	// creacion de nodos tipo struct
    if(primero == NULL)
    {
        primero = actual;
        ultimo  = actual;
        ultimo->next = NULL;
        ultimo->prev = NULL;
        
        printf("\nPrimer Nodo Libro creado...");
    }
    else
    {
        actual->prev = ultimo;
        ultimo->next = actual;
        ultimo = actual;
        ultimo->next = NULL;
        
        printf("\nNuevo Nodo Libro creado...");
    }
}

void consultarQueue()
{
	//int i=1;
    
    if(primero == NULL)
    {
    	printf("LL vacia...");	
	}
	else
    {
        actual = primero;
        
        while(actual != NULL)
        {
            printf("\n%s",actual->nombre);
            
            actual = actual->next;
            //i++;
        }
    }
}

void consultarQueueInversa()
{ 
    if(primero == NULL)
    {
    	printf("LL vacia...");	
	}
	else
    {
        actual = ultimo;
        
        while(actual != NULL)
        {
            printf("\n%s",actual->nombre);
            
            actual = actual->prev;
            //i++;
        }
    }
} 


void opciones()
{
    int opcion;
    char name[20];
    
    do
    {
        printf("\nLL EN C\n");
        printf("1) PUSH\n");
        printf("2) Consultar LL\n");
        printf("3) Consultar LL inversa\n");
        printf("4) Exit\n");
        printf("Opcion = ");
        scanf("%d",&opcion);
        
        if(opcion == 1)
        {
        	printf("Nombre: ");
        	gets(name);
        	gets(name);
        	push(name);
        }

        if(opcion == 2)
        {
        	consultarQueue();
        }
        if(opcion == 3)
        {
        	consultarQueueInversa();
        }
        
    }while(opcion != 4);
}

int main()
{
    opciones();
}*/

//Ejercicio 4 -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
    double width;
    double height;
} Rectangle;

typedef struct{
    double x;
    double y;
} Point;

int ifContained(Rectangle *pRect, Point *point){
    if(point->x >= pRect->x && point->y >= pRect->y){
        if(point->x < pRect->x+pRect->width && point->y < pRect->y + pRect->height){
            return 1;
        }
    }
    return 0;
}

int newRect(Rectangle *pRect, Point *point)
{
    int x,y,alto,ancho;

    x= point->x + pRect->x;
    y=pRect->y;
    ancho = pRect->width - point->x + pRect->x;
    alto  = pRect->height - point->y - pRect->y;
    printf("Las coordenadas del nuevo rectangulo son: {x= %d, y= %d, ancho= %d, alto= %d}",x,y,ancho,alto);
    return 0;
}

int main(){
    double x,y,ancho,alto;
    Rectangle rect={1,1,5,4};
    printf("Rectangulo inicial= x= %.2lf y= %.2lf ancho= %.2lf largo= %.2lf\n",rect);
    printf("Ingresar x: ");
    scanf("%lf",&x);
    printf("Ingresar y: ");
    scanf("%lf",&y);
    printf("Ingresar ancho: ");
    scanf("%lf",&ancho);
    printf("Ingresar alto: ");
    scanf("%lf",&alto);
    double widi=x+ancho;
    printf("%lf widi\n", widi);
    double hiti=y+alto;
    Rectangle rect2= {x,y,ancho,alto};
    Point p1 = {x,y};
    Point p2 = {widi,y};
    Point p3 = {widi,hiti};
    Point p4 = {x,hiti};
    printf("%lf\n",p3);
    if (ifContained(&rect, &p1))
    {
        printf("El rectangulo si esta adentro\n");
        newRect(&rect, &p1);
    }
    if (ifContained(&rect, &p2))
    {
        printf("El rectangulo si esta adentro p2\n");
        newRect(&rect, &p2);
    }
    if (ifContained(&rect, &p3))
    {
        printf("El rectangulo si esta adentro p3\n");
        newRect(&rect, &p3);
    }
    if (ifContained(&rect, &p4))
    {
        printf("El rectangulo si esta adentro p4\n");
        newRect(&rect, &p4);
    }/*
    else
    {
        printf("El rectangulo no rifa");
    }*/
    return 0;
}