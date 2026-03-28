#include<stdio.h>

int main(void)
{
    for(float i=0.0; i<=1.0; i += 0.01) {
        static int j=0;
        printf("x = %f  x = %f\n", i, (double)j/100);
        j++;
    }

    return 0;
}