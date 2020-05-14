#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int a = 0xFD; //1111 1101
    /*                           &
    **                      ~0000 0111 --> 1..1111 1000
    **1111 1000 F8
    */
    a &= ~7;

    printf("%x\n%d",a,a);

    return 0;


}