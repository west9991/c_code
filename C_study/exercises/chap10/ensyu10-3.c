#include<stdio.h>

void trade(int *x1, int *x2)
{
    int t= *x1;
    *x1 = *x2;
    *x2 = t;
}

void sort3(int *n1, int *n2, int *n3)
{
    if(*n3 < *n2) trade(n2, n3);
    if(*n2 < *n1) trade(n1, n2);
    if(*n3 < *n2) trade(n2, n3);
}

int main(void)
{
    int n1, n2, n3;
    printf("n1,n2,n3‚Ì‡‚É“ü—Í");
    scanf("%d%d%d", &n1, &n2, &n3);

    sort3(&n1, &n2, &n3);
    printf("¸‡‚ÌŒ‹‰Ê‚ÍA%4d,%4d,%4d‚Å‚·B", n1, n2, n3);

    return 0;
}