#include<stdio.h>

int main(void)
{
    int start=0,end=0,inc=0;

    printf("開始，終了，増分を入力してください\n");
    scanf("%d%d%d",&start,&end,&inc);

    int height;
    double std_weight;
    for(height=start;height<=end;height+=inc) {
        std_weight=(height-100)*0.9;
        printf("%dcm  %.2fkg\n",height,std_weight);
    }

    return 0;
}