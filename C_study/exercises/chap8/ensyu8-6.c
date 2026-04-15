#include<stdio.h>

int factorial(int n)
{
    int fact=1;
    if (n > 0) {
        for(int i=1; i <= n;i++) {
            fact *= i;
        }
    } else if(n=0) {
        fact = 1;
    } else {
        puts("負の値が入力されました。");
    }

    return fact;
}

int main(void)
{
    int n;
    puts("非負の整数を入力");scanf("%d", &n);
    printf("%dの階乗値は%dです。", n, factorial(n));

    return 0;
}