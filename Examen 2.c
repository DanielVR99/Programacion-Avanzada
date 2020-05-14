#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct{
    uint16_t x;
    uint16_t y;
    double ang;
    uint8_t tipo; //00=terminación - 01=división - 10=punto - 11=desconocido
} Minucia;

typedef struct{
    Minucia* arr;
    uint16_t longitud;
} ArregloMinucias;

Minucia* crearMinucia(uint16_t x, uint16_t y, double ang, uint8_t tipo){
    //printf("%d, %d, %lf, %d, %d",x, y, ang, tipo, pos);
    Minucia *minu = (Minucia*)malloc(sizeof(Minucia));
    minu->x=x;
    minu->y=y;
    minu->ang=ang;
    minu->tipo=tipo;
    return minu;
   //printf("Element 0: %d, %d, %lf\n", *((uint16_t*)minuPtr->arr[pos].x),*((uint16_t*)minuPtr->arr[pos].y),*((uint16_t*)minuPtr->arr[pos].ang));//, minuPtr->arr[pos].y, minuPtr->arr[pos].ang);
}

double calcularDistancia(Minucia *p1, Minucia *p2){
    double dif1 = pow(p1->x - p2->x, 2);
    double dif2 = pow(p1->y - p2->y, 2);

    double dist = sqrt(dif1+dif2);
    //printf("\nDistancia: %.2lf\n",dist);
    return dist;
}

Minucia* encontrarCentroide(ArregloMinucias *minuPtr){
    //arr->longitud;
    Minucia *min;
    min=&minuPtr->arr[0];
    double dist=0;
    double mini=99999999999999999;
    for(int i=0;i<minuPtr->longitud;i++){
        for(int j=0;j<minuPtr->longitud;j++){
            dist += calcularDistancia(&minuPtr->arr[i],&minuPtr->arr[j]);
        }
        if(dist<mini){
            mini=dist;
            min=&minuPtr->arr[i];
        }
        dist = 0;
    }
    return min;
}

ArregloMinucias* crearArregloMinucias(int longitud) {
    ArregloMinucias *minuPtr = (ArregloMinucias*)malloc(longitud*sizeof(ArregloMinucias));
    minuPtr->arr = (Minucia*)calloc(100, sizeof(Minucia));
    minuPtr->longitud=longitud;
    /*for(int i=0;i<longitud;i++){
        minuPtr->arr[i].x=0;
        minuPtr->arr[i].y=0;
        minuPtr->arr[i].tipo=0;
        minuPtr->arr[i].ang=0;
    }*/
    printf("\nArreglo creado\n");
    return minuPtr;
}

void liberarArregloMinucias(ArregloMinucias* minuPtr){
    free(minuPtr->arr);
    free(minuPtr);
}

void devolverTipoMinucia(char *str, Minucia *minu){
    //printf("Tipo ini: %d",*((uint8_t*)minu->tipo));
    uint8_t mask=0x03;
    uint8_t tipo=minu->tipo;
    char tipoStr[]="";
    printf("Tipo final: %d\n",tipo);
    
    if((tipo & mask)==0){//terminacion
        str[0]='T';
        str[1]='e';
        str[2]='r';
        str[3]='m';
        str[4]='i';
        str[5]='n';
        str[6]='a';
        str[7]='c';
        str[8]='i';
        str[9]='o';
        str[10]='n';

    }
    if((tipo & mask)==1){ //division
        str[0]='D';
        str[1]='i';
        str[2]='v';
        str[3]='i';
        str[4]='s';
        str[5]='i';
        str[6]='o';
        str[7]='n';
        str[8]=' ';
        str[9]=' ';
        str[10]=' ';
    }
    if((tipo & mask)==2){ //punto
        str[0]='P';
        str[1]='u';
        str[2]='n';
        str[3]='t';
        str[4]='o';
        str[5]=' ';
        str[6]=' ';
        str[7]=' ';
        str[8]=' ';
        str[9]=' ';
        str[10]=' ';

    }
    if((tipo & mask)==3){ //desconocido
        str[0]='D';
        str[1]='e';
        str[2]='s';
        str[3]='c';
        str[4]='o';			
        str[5]='n';
        str[6]='o';
        str[7]='c';
        str[8]='i';
        str[9]='d';
        str[10]='o';
    }
}

int main(){
    int pos=0;
    uint16_t longitud=0;
    uint16_t x, auxx;
    uint16_t y, auxy;
    uint8_t tipo;
    double angulo;
    printf("ingrese el tamano del arreglo: ");
    scanf("%d",&longitud);
    uint16_t aux = longitud;
    ArregloMinucias* minuPtr = crearArregloMinucias(aux);
    for(int i=0;i<aux;i++){
        
        printf("Ingrese los valores de la minucia %d\n",i);
        printf("x= ");
        scanf("%d",&x);
        auxx=x;
        printf("y= ");
        scanf("%d",&y);
        auxy=y;
        printf("tipo= (0=terminacion, 1=division, 2=punto, 3=desconocido)  ");
        scanf("%d",&tipo);
        printf("Angulo= ");
        scanf("%lf",&angulo);
        minuPtr->arr[i].x=crearMinucia(auxx,auxy,angulo,tipo)->x;
        minuPtr->arr[i].y=crearMinucia(auxx,auxy,angulo,tipo)->y;
        minuPtr->arr[i].ang=crearMinucia(auxx,auxy,angulo,tipo)->ang;
        minuPtr->arr[i].tipo=crearMinucia(auxx,auxy,angulo,tipo)->tipo;
        
        /*
        minuPtr = crearMinucia(minuPtr, auxx,auxy,angulo,tipo,i);*/
        //printf("Element 0: %d, %d, %lf\n", *((uint16_t*)minuPtr->arr[i].x),*((uint16_t*)minuPtr->arr[i].y),*((uint16_t*)minuPtr->arr[i].ang));
        //printf("Element 0-1: %d, %d, %lf\n", *((uint16_t*)minuPtr->arr[i-1].x),*((uint16_t*)minuPtr->arr[i-1].y),*((uint16_t*)minuPtr->arr[i-1].ang));
    }

    char tipoMin[]= "";
    /*//devolverTipoMinucia(tipoMin, &minuPtr->arr[0]);
    printf("Element 0: %d, %d, %lf, %d\n", minuPtr->arr[0].x, minuPtr->arr[0].y, minuPtr->arr[0].ang, minuPtr->arr[0].tipo);
    printf("Element 1: %d, %d, %lf, %d\n", minuPtr->arr[1].x, minuPtr->arr[1].y, minuPtr->arr[1].ang, minuPtr->arr[1].tipo);
    printf("Element 2: %d, %d, %lf, %d\n", minuPtr->arr[2].x, minuPtr->arr[2].y, minuPtr->arr[2].ang, minuPtr->arr[2].tipo);
    printf("Element 3: %d, %d, %lf, %d\n", minuPtr->arr[3].x, minuPtr->arr[3].y, minuPtr->arr[3].ang, minuPtr->arr[3].tipo);
    printf("Tipo min: %s",tipoMin);
    //devolverTipoMinucia(tipoMin, &minuPtr->arr[0]);
    printf("Tipo min: %s",tipoMin);*/
    for(int i=0;i<aux;i++){
        printf("\nElement 0: %d, %d, %lf, %d\n", minuPtr->arr[i].x, minuPtr->arr[i].y, minuPtr->arr[i].ang, minuPtr->arr[i].tipo);
        devolverTipoMinucia(tipoMin, &minuPtr->arr[i]);
        printf("Tipo min: %s",tipoMin);
        char tipoMin[]= "";
    }

    Minucia* minCentroide = encontrarCentroide(minuPtr);
    printf("\nElement centroide: %d, %d, %lf, %d\n", minCentroide->x, minCentroide->y, minCentroide->ang, minCentroide->tipo);
    liberarArregloMinucias(minuPtr);
    return 0;
}
