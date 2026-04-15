#include<stdio.h>

int main(void)
{
    char str[] = "ABC\0DEF";

    printf("•¶š—ñstr‚Í\"%s\"‚Å‚·B\n", str);
    printf("%d", str[0]);//add

    return 0;
}