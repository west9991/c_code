#include<stdio.h>

int main(void)
{
    char fname[128];
    FILE *fp;

    puts("input filename");
    scanf("%s", fname);

    fp = fopen(fname, "w");

    return 0;
}