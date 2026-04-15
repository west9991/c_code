#include<stdio.h>
#include<ctype.h>

void del_digit(char s[])
{
    int i=0;
    int count=0;
    while(s[i]) {
        if (toupper(s[i]) != tolower(s[i])) {
            s[count]=s[i];
            count++;
        }
        i++;
    }
    s[count] = 0;
}

int main(void)
{
    char s[100];

    puts("input string");scanf("%s", s);

    del_digit(s);

    printf("%s", s);

    return 0;
}