#include<stdio.h>

int main(void)
{
    static double x[10];

    for(int i=0;i<10;i++) {
        printf("%4.1f",x[i]);
        putchar('\n');
    }

    return 0;
}