#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    uint32_t num1=0;
    uint32_t num2=0;
    uint32_t num3=0;
    uint32_t num4=0;
    uint32_t num5=0;
    printf("Primera cadena, ingrese un numero decimal menor o igual a 255: ");
    scanf("%d",&num1);
    num1<<=24;
    num5|=num1;
    
    printf("Segunda cadena, ingrese un numero decimal menor o igual a 255: ");
    scanf("%d",&num2);
    num2<<=16;
    num5|=num2;

    printf("Tercera cadena, ingrese un numero decimal menor o igual a 255: ");
    scanf("%d",&num3);
    num3<<=8;
    num5|=num3;
    
    printf("Cuarta cadena, ingrese un numero decimal menor o igual a 255: ");
    scanf("%d",&num4);
    num5|=num4;

    printf("Numero en hexadecimal: %x \n",num5);
    printf("Numero en decimal: %d",num5);

}