#include<stdio.h>

int main(void)
{
    double sum_int=0, sum_double=0;

    for(float i=0.0; i<= 1.0; i += 0.01) {
        sum_double += i;
    }

    for(int i=0; i <= 100; i++) {
        double j=(double)i/100;
        sum_int += j;
    }

    printf("sum_double=%f  sum_int=%f\n", sum_double, sum_int);

    return 0;
}