#include<stdio.h>

int main(void)
{
    int a,b,c;
    int x,y,z;

    printf("３つの整数を入力¥n");
    scanf("%d%d%d",&a,&b,&c);
    x=a==b;
    y=b==c;

    if(x && y) {printf("すべての値が等しい");}
    else if(x+y==1) {printf("2つの値が等しい");}
    else {printf("3つの値は異なる");}

    return 0;
}