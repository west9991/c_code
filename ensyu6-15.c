#include<stdio.h>

#define NUMBER 3

int i;
void put_count(void)
{
    i++;
}

int main(void)
{
    for(int j=0;j<NUMBER;j++) {
        put_count();
        printf("put_count: %d‰ñ–Ú\n",i);
    }

    return 0;
}