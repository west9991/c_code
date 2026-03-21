#include<stdio.h>

int min2(int a,int b)
{
    int min=a;
    if(b<a) {
        min=b;
    }

    return min;
}

int main(void)
{
    int a,b;
    printf("2‚Â‚Ì®”‚ğ“ü—Í‚·‚é\n");
    printf("®”‚PF");scanf("%d",&a);
    printf("®”‚QF");scanf("%d",&b);

    printf("¬‚³‚¢‚Ù‚¤‚Ì®”‚Í%d‚Å‚·B",min2(a,b));

return 0;
}