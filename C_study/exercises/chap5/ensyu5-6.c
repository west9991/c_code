#include<stdio.h>
#define DATA 100
int main(void)
{
    int no;

    printf("データ数を入力\n");
    scanf("%d",&no);

    int x[DATA];
    printf("要素を入力\n");
    for(int i=0;i<no;i++) {
        printf("%2d番：",i+1);
        scanf("%d",&x[i]);
    }

    printf("{");
    for(int i=0;i<no-1;i++) {
        printf("%d, ",x[i]);
    }
    printf("%d}",x[no-1]);

    return 0;
}