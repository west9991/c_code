#include<stdio.h>

int main(void)
{
    int a,b;
    printf("2‚Â‚Ì®”‚ð“ü—Í\n");
    scanf("%d%d",&a,&b);

    if(a-b>=11 || a-b<=-11){
        printf("·‚Í11ˆÈã‚Å‚·D");
    } else {
        printf("·‚Í10ˆÈ‰º‚Å‚·D");
    }
    return 0;
}