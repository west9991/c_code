#include<stdio.h>

int c_size(const char s[])
{
    int len=0;
    while(s[len]) {
        len++;
    }

    return len;
}

void rev_string(char s[])
{
    int char_size;

    char_size = c_size(s);
    for(int i=0; i<char_size/2; i++) 
    {
        int t=s[i];
        s[i]=s[char_size-1-i];
        s[char_size-1-i]=t;
    }
}

int main(void)
{
    char s[100];

    puts("input string");scanf("%s", s);

    rev_string(s);

    printf("%s", s);

    return 0;
}