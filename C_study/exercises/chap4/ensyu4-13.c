#include<stdio.h>

int main(void)
{
    int n;

    printf("³‚Ì®”‚ğ“ü—Í‚¹‚æ\n");
    scanf("%d",&n);

    int sum=0;
    for(int i=1;i<=n;i++) {
        sum +=i;
    }

    if(n>0) printf("1‚©‚ç%d‚Ü‚Å‚Ì‘˜a‚Í%d‚Å‚·",n,sum);

    return 0;
}