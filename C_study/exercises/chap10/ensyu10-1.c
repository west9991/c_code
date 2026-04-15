#include<stdio.h>

void adjsut_point(int *n)
{
    if(*n > 100) *n = 100;
    if(*n < 0) *n =0;
}

int main(void)
{
    int x;
    printf("x=");scanf("%d", &x);

    adjsut_point(&x);

    printf("x=%d", x);

    return 0;
}