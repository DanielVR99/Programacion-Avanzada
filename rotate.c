#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t rotate(uint8_t init, int r)
{
    uint8_t mask=init;
    uint8_t result;
    if(r>0)
    {
        init>>=r;
        mask<<=8-r;
        result = init|mask;
    }
    if(r<0)
    {
        init<<=-r;
        mask>>=8+r;
        result = init|mask;
    }
    return result;
}

int main(){
    uint8_t num;
    int r;
    printf("Ingrese un numero decimal menor o igual a 255: ");
    scanf("%d",&num);
    printf("Cuantos bits quiere rotar: ");
    scanf("%d",&r);
    num=rotate(num, r);
    printf("Hex: %x\n Dec: %d",num,num);
}
