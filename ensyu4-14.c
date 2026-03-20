#include<stdio.h>

int main(void)
{
    int n;
    printf("正の整数を入力せよ¥n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        printf("%d",i%10);
    }
    if(n>0) printf("¥n");

    return 0;
}