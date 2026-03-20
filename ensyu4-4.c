#include<stdio.h>

int main(void)
{
    int no;

    printf("正の整数を入力せよ¥n");
    scanf("%d",&no);

    int no1=no;
    while (no>=1) {
        printf("%d ", no--);
    }
    if(no1>=1) {
        printf("¥n");
    }

    return 0;
}