#include<stdio.h>

int sumup(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++) {
        sum+=i;
    }

    return sum;
}

int main(void)
{
    int n;
    printf("正の整数を入力¥n");
    scanf("%d",&n);

    printf("1から%dまでのすべての整数の和は%dです",n,sumup(n));

    return 0;
}