#include<stdio.h>

int main(void)
{
    int ch;
    int n=0;

    while((ch = getchar()) != EOF) {
        if (ch == '\n') n++;
    }

    printf("‰üs‚Í%dŒÂ", n);
}