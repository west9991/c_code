#include <stdio.h>

#define NUMBER 7
int main(void)
{
    int x[NUMBER];

    for (int i = 0; i < NUMBER; i++)
    {
        printf("x[%d] :", i);
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < (NUMBER / 2); i++)
    {
        int t = x[i];
        x[i] = x[NUMBER-1 - i];
        x[NUMBER-1 - i] = t;
    }

    puts("”½“]‚µ‚Ü‚µ‚½");
    for (int i = 0; i < NUMBER;i++) {
        printf("x[%d] = %d\n", i , x[i]);
    }

    return 0;
}