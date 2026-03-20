#include<stdio.h>

int main(void)
{
    int a,b,c;

    printf("整数を3つ入力して¥n");
    scanf("%d%d%d",&a,&b,&c);

    int max=a;
    max= b>max ? b : max;
    max= c>max ? c : max;

    printf("最も大きい整数は%dです．",max);
    return 0;
}