#include<stdio.h>

unsigned rrotate(unsigned x, int n)
{
    return (x >> n) | (x << (sizeof(unsigned) *8 -n));
}

unsigned lrotate(unsigned x, int n)
{
    return (x << n) | (x >> (sizeof(unsigned) *8 -n));
}

void print_bits(unsigned x);
int main(void)
{
    unsigned x = 100;
    int n = 4;

    print_bits(rrotate(x,n));
    putchar('\n');
    print_bits(lrotate(x,n));
    putchar('\n');
}

void print_bits(unsigned x)
{
    for (int i = sizeof(unsigned)*8 -1; i >= 0; i--)
        putchar(((x >> i) & 1U) ? '1' : '0');
}