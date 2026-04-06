#include<stdio.h>

double sqr(int n)
{
    return n*n;
}

double pow4(int x)
{
    return sqr(sqr(x));
}

int main(void)
{
    int n;
    printf("À”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
    scanf("%d",&n);

    printf("“ü—Í‚³‚ê‚½®”‚Ì4æ‚Ì’l‚Í%.2f‚Å‚·B\n",pow4(n));

    return 0;
}