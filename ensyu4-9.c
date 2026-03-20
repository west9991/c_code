#include<stdio.h>

int main(void)
{
    int no;

    printf("正の整数を入力せよ");
    scanf("%d",&no);
    int conf=no;
    int i=0;
    while(i<no) {
        if(i%2) {
            printf("-");
    } else {
        putchar('+');
    }
    i++;
    }
    if(conf>0) {
        printf("¥n");
    }

    return 0;
}