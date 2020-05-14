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
        if(point->x <= pRect->x+pRect->width && point->y <= pRect->y + pRect->height){
            return 1;
        }
    }
    return 0;
}

int main(){
    Rectangle rect={0,0,2,2};
    Point p ={1,3};
    if (ifContained(&rect, &p))
    {
        printf("El punto si esta adentro");
    }
    else
    {
        printf("El punto no rifa");
    }
    return 0;
}