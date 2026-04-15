#include<stdio.h>
#include<math.h>

int main(void)
{
    double area;
    double side;

    printf ("input area"); scanf ("%lf",&area);
    side = sqrt(area);

    printf("side long is %f", side);

    return 0;
}