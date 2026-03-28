#include<stdio.h>
#include<limits.h>

unsigned set(unsigned x, int pos)
{
    x = x | 1U << pos;
    return x;
}

unsigned lrotate(unsigned x, int n)
{
    return (x << n) | (x >> (sizeof(unsigned) *8 -n));
}

unsigned reset(unsigned x, int pos)
{
    int t=lrotate(~1U,pos);
    x = x & t;
    return x;
}

unsigned inverse(unsigned x, int pos)
{
    x = x ^ 1U << pos;
    return x;
}

void print_bits(unsigned x)
{
    for(int i=sizeof(unsigned)*CHAR_BIT-1;i>=0;i--) {
        putchar(((x>>i) & 1U) ? '1' : '0');
    }
    putchar('\n');
}

int main(void)
{
    unsigned x=1013;
    int pos=3;
    print_bits(x);
    print_bits((set(x,pos)));
    print_bits((reset(x,pos)));
    print_bits((inverse(x,pos)));

    return 0;
}