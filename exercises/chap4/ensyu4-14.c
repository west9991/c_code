#include<stdio.h>

int main(void)
{
    int n;
    printf("³‚Ì®”‚ğ“ü—Í‚¹‚æ\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++) {
        printf("%d",i%10);
    }
    if(n>0) printf("\n");

    return 0;
}