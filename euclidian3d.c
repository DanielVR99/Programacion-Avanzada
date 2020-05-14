#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
    double z;
} punto3D;

double euc(punto3D *p1,punto3D *p2) {
    //return sqrt((x1-x2)^2+(y1-y2)^2+(z1-z2)^2)

    double dif1 = pow(p1->x - p2->x, 2);
    double dif2 = pow(p1->y - p2->y, 2);
    double dif3 = pow(p1->z - p2->z, 2);

    double dist = sqrt(dif1+dif2+dif3);
    return dist;
}

int main(){
    punto3D p1 = {1, 2, 3};
    punto3D p2 = {2, 3, 4};

    double dis = euc(&p1, &p2); //Pasamos dir de mem
    printf("La distancia entre los dos puntos es: %.2f\n",dis);
}