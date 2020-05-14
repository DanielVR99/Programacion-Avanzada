#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int comparador(int ini)
{
    uint8_t num;
    uint8_t mask=0x01;
    printf("Ingrese un numero decimal menor o igual a 255 para comparar numero de 1s: ");
    scanf("%d",&num);
    int contador=0;
    for(int i=0;i<8;i++)
    {
        if(num & mask)
        {
            contador++;
        }
        mask<<=1;
    }
    if(ini>contador)
        return 1;
    if(ini==contador)
        return 0;
    if(ini<contador)
        return -1;
}

int main(){
    uint8_t num;
    uint8_t mask=0x01;
    printf("Ingrese un numero decimal menor o igual a 255: ");
    scanf("%d",&num);

    int contador=0;
    int comp;
    for(int i=0;i<8;i++)
    {
        if(num & mask)
        {
            contador++;
        }
        mask<<=1;
    }
    printf("El numero de unos es: %d\n",contador);

    comp = comparador(contador);
    printf("El resultado de la comparacion es: %d\n",comp);
    system("Pause");
    system("cls");
}