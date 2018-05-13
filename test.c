#include<stdio.h>

int j = 0x123456;

int main()
{
    printf("the address of j is 0x%x\n",&j);
    while(j);
    printf("program terminated normally!\n");
    return 0;
}