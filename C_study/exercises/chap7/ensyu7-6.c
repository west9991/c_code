#include<stdio.h>
#include<limits.h>

int main(void)
{
    int n=5;
    for(int i=0;i<n;i++) {
        unsigned x=UINT_MAX+i;
        printf("%u\n",x);
    }

    return 0;
}