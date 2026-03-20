#include<stdio.h>

int main(void)
{
    int no;

    printf("³‚Ì®”‚ð“ü—Í‚¹‚æ\n");
    scanf("%d",&no);

    int no1=no;
    while (no>=1) {
        printf("%d ", no--);
    }
    if(no1>=1) {
        printf("\n");
    }

    return 0;
}