#include<stdio.h>

int count_bits(unsigned x)
{
    int bits = 0;
    while (x) {
        if (x & 1U) bits++; //1Uは、最下位のビットのみが1の符号無し整数（00000...001）
        x >>= 1;
    }
    return bits;
}

int int_bits(void)
{
    return count_bits(~0U);/*0Uはすべてのビットが0である整数0で~をつけることで全ビットを反転させている。
                                                すなわち、~0Uは全ビットが1の整数*/
}

void print_nbits(unsigned x, unsigned n)
{
    int i= int_bits();
    i = (n < i) ? n-1 : i-1;
    for ( ; i >=0; i--)
        putchar(((x >> i) & 1U) ? '1' : '0');
}

int main(void)
{
    for(unsigned i=0; i<= 65U; i++) {
        printf("%5u ", i);
        print_nbits(i, 16);
        printf(" %06o %04X\n", i, i);
    }

    return 0;
}