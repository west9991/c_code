#include<stdio.h>

int main(void)
{
    int a,b;
    printf("2つの整数を入力¥n");
    scanf("%d%d",&a,&b);

    if(a-b>=11 || a-b<=-11){
        printf("差は11以上です．");
    } else {
        printf("差は10以下です．");
    }
    return 0;
}