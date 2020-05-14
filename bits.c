#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    uint8_t mask = 8;       //0000 1000
    uint8_t flagBit = 0x59; //0101 1001 :)
    /*                                 &
    **     uint_8=8               ~0000 1000 -->
    **1111 1000 F8
    */
   //mask &= flagBit;

   //Comprobar que el tercer bit es 1 o 0
   if(flagBit & mask)
   {
       printf("El valor del bit es 1\n");
   }
   else
   {
       printf("El valor del bit es 0\n");
   }
      
   //Hacer 0 el tercer bit
   flagBit &= ~mask;
   printf("FlagBit_0: %x\n%d\n",flagBit,flagBit);

   //Hacer 1 el tercer bit
   flagBit |=mask;
   printf("Hacer de nuevo 1 el tercer bit: %x\n%d\n",flagBit,flagBit);

   //Invertir el valor del tercer bit
   flagBit ^= mask;
   printf("Tercer bit negado: %x\n%d\n",flagBit,flagBit);

   return 0;


}