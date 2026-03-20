#include<stdio.h>

int main(void)
{
    int n;

    printf("正の整数を入力せよ¥n");
    scanf("%d",&n);

    int sum=0;
    for(int i=1;i<=n;i++) {
        sum +=i;
    }

    if(n>0) printf("1から%dまでの総和は%dです",n,sum);

    return 0;
}