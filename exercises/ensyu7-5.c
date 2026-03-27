#include<stdio.h>
#include<limits.h>

unsigned set_n(unsigned x, int pos, int n);
unsigned reset_n(unsigned x, int pos, int n);
unsigned inverse_n(unsigned x, int pos, int n);

unsigned set_n(unsigned x, int pos, int n)
{
    for(int i=pos;i<pos+n;i++) {
        x = x | 1U << i;
    }
    return x;
}

unsigned lrotate(unsigned x, int n)
{
    return (x << n) | (x >> (sizeof(unsigned) *8 -n));
}

unsigned reset_n(unsigned x, int pos, int n)
{
    for(int i=pos;i<pos+n;i++) {
        x = x & lrotate(~1U,i);
    }
    return x;
}

unsigned inverse_n(unsigned x, int pos, int n)
{
    for(int i=pos;i<pos+n;i++) {
        x = x ^ 1U << i;
    }
    return x;
}

void print_bits(unsigned x)
{
    for (int i = sizeof(unsigned) * CHAR_BIT - 1; i >= 0; i--) {
        putchar(((x>>i) & 1U) ? '1' : '0');
    }
    putchar('\n');
}

int main(void)
{
    unsigned x=10000;
    int pos=4;
    int n=5;

    print_bits(x);
    print_bits(set_n(x,pos,n));
    print_bits(reset_n(x,pos,n));
    print_bits(inverse_n(x,pos,n));

    return 0;
}