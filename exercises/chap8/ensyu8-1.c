#include<stdio.h>

#define diff(x, y) (x>y) ? (x-y) : (y-x)

int main(void)
{
    int x=5,y=9;
    double a=6.2,b=5.9;

    printf("difference between a and b =%f\n", diff(a,b));
    printf("difference between x and y =%d\n", diff(x,y));

    return 0;
}