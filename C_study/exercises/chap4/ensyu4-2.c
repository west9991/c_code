#include<stdio.h>

int main(void)
{
    int a,b;

    printf("®”‚ğ“ñ‚Â“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
    scanf("%d%d",&a,&b);

    int max,min;
    if(a>b) {
        max=a;min=b;
    } else {
        max=b;min=a;
    }

    int sum=0;
    int cnt=min;
    do {
        sum=sum+cnt;
        cnt=cnt+1;
    } while (cnt<=max);

    printf("%dˆÈã%dˆÈ‰º‚Ì‘S®”‚Ì˜a‚Í%d‚Å‚·D\n",min,max,sum);
    return 0;
}