#include<stdio.h>

void put_stringn(const char s[], int n)
{
    int i=0;
    for(int j=0; j<n; j++) {
        while(s[i]) {
            putchar(s[i++]);
        }
        putchar('\n');
        i=0;
    }
}

int main(void)
{
    char s[100];
    int n;

    puts("•¶Žš—ñ‚ð“ü—Í");scanf("%s", s);
    puts("•\Ž¦‚·‚é‰ñ”‚ð“ü—Í");scanf("%d", &n);

    put_stringn(s, n);

    return 0;
}