#include<stdio.h>

int main(void)
{
    int retry;

    do {
        int no;

        printf("整数を入力\n");
        scanf("%d",&no);
        if(no == 0) {
            printf("０です．\n");
        } else if(no > 0) {
            printf("値は正です\n");
        } else {
            printf("値は負です\n");
        }

        printf("続けますか？  はい：０，いいえ：９\n");
        scanf("%d",&retry);
    } while(retry == 0);

    return 0;
}