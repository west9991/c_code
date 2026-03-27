#include<stdio.h>

int main(void)
{
    int n;
    printf("sizeof(1)=%zu\n",sizeof(1));
    printf("sizeof+1=%zu\n",sizeof+1);
    printf("sizeof-1=%zu\n",sizeof-1);
    printf("sizeof(unsigned)-1=%zu\n",sizeof(unsigned)-1);
    printf("sizeof(double)-1=%zu\n",sizeof(double)-1);
    printf("sizeof((double)-1)=%zu\n",sizeof((double)-1));
    printf("sizeof n+2=%zu\n",sizeof n+2);
    printf("sizeof(n+2)=%zu\n",sizeof(n+2));
    printf("sizeof(n+2.0)=%zu\n",sizeof(n+2.0));

    return 0;
}