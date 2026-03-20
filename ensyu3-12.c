#include<stdio.h>

int main(void)
{
    int n;

    printf("整数を入力¥n");
    scanf("%d",&n);

    switch(n%2) {
        case 1 : puts("奇数です");  break;
        default : puts("偶数です"); break;
    }

    return 0;
}