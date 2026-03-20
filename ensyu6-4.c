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
    printf("実数を入力してください¥n");
    scanf("%d",&n);

    printf("入力された整数の4乗の値は%.2fです。¥n",pow4(n));

    return 0;
}