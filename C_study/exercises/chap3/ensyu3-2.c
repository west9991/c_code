#include<stdio.h>

int main(void)
{
    int no;

    printf("整数を入力せよ。\n");
    scanf("%d",&no);

    if(no == 0)
        puts("その数は０です．");
    else if(no>0)
        puts("その数は正です．");
    else if(no<0)
        puts("その数は負いです．"); 

    return 0;
}