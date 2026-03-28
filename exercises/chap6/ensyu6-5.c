#include<stdio.h>

int sumup(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++) {
        sum+=i;
    }

    return sum;
}

int main(void)
{
    int n;
    printf("³‚Ì®”‚ğ“ü—Í\n");
    scanf("%d",&n);

    printf("1‚©‚ç%d‚Ü‚Å‚Ì‚·‚×‚Ä‚Ì®”‚Ì˜a‚Í%d‚Å‚·",n,sumup(n));

    return 0;
}