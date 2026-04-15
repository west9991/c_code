#include<stdio.h>

int main(void)
{
    int a,b,c;

    printf("®”‚ğ3‚Â“ü—Í‚µ‚Ä\n");
    scanf("%d%d%d",&a,&b,&c);

    int max=a;
    max= b>max ? b : max;
    max= c>max ? c : max;

    printf("Å‚à‘å‚«‚¢®”‚Í%d‚Å‚·D",max);
    return 0;
}