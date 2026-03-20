#include<stdio.h>

int main(void)
{
    int no;

    printf("正の整数を入力せよ．");
    scanf("%d",&no);

    int i=1;
    while(2*i<=no) {
        printf("%d ",i*2);
        i++;
    }
    printf("¥n");

    return 0;
}