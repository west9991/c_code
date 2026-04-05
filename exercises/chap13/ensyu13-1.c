#include<stdio.h>

int main(void)
{
    char p[128];
    FILE *fp;

    puts("input filename");
    scanf("%s", p);

    fp = fopen(p, "r");

    if(fp == NULL)
        printf("ファイル\"%s\"をオープンできませんでした\n",p);
    else {
        printf("ファイル\"%s\"をオープンできました\n", p);
        fclose(fp);
    }

    return 0;
}