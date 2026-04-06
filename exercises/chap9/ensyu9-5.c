#include<stdio.h>

int str_char(const char s[], int c)
{
    int index=0;
    int i=0;
    while (s[i]) {
        if(s[i] == c) return i;//intŒ^“¯m‚Å”äŠr‰‰Z‚ğ‚µ‚Ä‚¢‚éB
        i++; 
    }

    return -1;
}

int main(void)
{
    char s[100];
    char see[2];

    puts("•¶š—ñ‚ğ“ü—Í");scanf("%s",s);
    puts("Œ©‚Â‚¯‚½‚¢•¶š‚ğ1•¶š“ü—Í");scanf(" %s", see);

    int pos = str_char(s, see[0]);
    if (pos == -1) {
        puts("‚»‚ê‚ÍŠÜ‚Ü‚ê‚Ä‚¢‚Ü‚¹‚ñ");
    } else {
    printf("%d•¶š–Ú‚É‚ ‚è‚Ü‚·B", pos+1);
    }

    return 0;
}