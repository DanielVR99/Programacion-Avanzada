#include <stdio.h>
#include <stdlib.h>

void myMemsetRange(char *str, char c, int init, int end)
{
    int pos = 0;
    while(*str != 0 && pos <= end)
    {
        if(pos >= init && pos <=end)
        {   
            *str = c;
        }
        str++; //Incrementando al Hexadecimal
        pos++;
    }
}

int main()
{
    char someStr[] = "We love C"; //We love C\0
    myMemsetRange(someStr, '$', 3, 6);
    printf("%s", someStr);
    return 0;
}