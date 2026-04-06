#include<stdio.h>

int max(int x, int y)
{
    return (x>y) ? x : y;
}

int min(int x, int y)
{
    return (x<y) ? x : y;
}

int gcd(int x, int y)
{
    int difference;
    int part;
    
    difference = max(x,y) % min(x,y);
    if (difference == 0) {
        part = min(x,y);
    } else {
        part = gcd(min(x,y), difference);
    }

    return part;
}

int main(void)
{
    int x, y, part;

    puts("“ñ‚Â‚Ì³‚Ì®”‚ğ“ü—Í");
    do {
        scanf("%d%d", &x, &y);
    } while(!(x>0 && y>0));

    printf("“ñ‚Â‚Ì®”‚ÌÅ‘åŒö–ñ”‚Í%d‚Å‚·B", gcd(x, y));

    return 0;
}