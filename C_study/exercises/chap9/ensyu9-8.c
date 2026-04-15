#include<stdio.h>

void put_stringr(const char s[])
{
    int c_long;
    int i=0;
    while(s[i]) {
        i++;
    }
    c_long = i;
    for(int j=c_long-1; j>=0; j--) {
        putchar(s[j]);
    }
}

int main(void)
{
    char s[100];

    puts("input char");scanf("%s", s);

    put_stringr(s);

    return 0;
}