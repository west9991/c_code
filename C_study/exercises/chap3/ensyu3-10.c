#include<stdio.h>

int main(void)
{
    int a,b,c;
    int x,y,z;

    printf("‚R‚Â‚Ì®”‚ğ“ü—Í\n");
    scanf("%d%d%d",&a,&b,&c);
    x=a==b;
    y=b==c;

    if(x && y) {printf("‚·‚×‚Ä‚Ì’l‚ª“™‚µ‚¢");}
    else if(x+y==1) {printf("2‚Â‚Ì’l‚ª“™‚µ‚¢");}
    else {printf("3‚Â‚Ì’l‚ÍˆÙ‚È‚é");}

    return 0;
}