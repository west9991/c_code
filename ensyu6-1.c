#include<stdio.h>

int min2(int a,int b)
{
    int min=a;
    if(b<a) {
        min=b;
    }

    return min;
}

int main(void)
{
    int a,b;
    printf("2つの整数を入力する¥n");
    printf("整数１：");scanf("%d",&a);
    printf("整数２：");scanf("%d",&b);

    printf("小さいほうの整数は%dです。",min2(a,b));

return 0;
}