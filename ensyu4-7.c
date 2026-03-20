#include<stdio.h>

int main(void)
{
    int no;

    printf("正の整数を入力せよ．¥n");
    scanf("%d",&no);

    int max=2;
    while(max<=no) {
        printf("%d ",max);
        max *=2;
    }
    printf("¥n");

    return 0;
}