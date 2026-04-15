#include<stdio.h>

int str_chnum(const char s[], int c)
{
    int cnt=0;
    int i=0;

    while(s[i]) {
        if (s[i] == c) cnt++;
        i++;
    }

    return cnt;
}

int main(void)
{
    char s[100];
    char c[2];
    int pos;

    puts("文字列を入力");
    scanf("%s", s);
    puts("見つけたい文字を1文字入力");
    scanf("%s", c);

    pos = str_chnum(s, c[0]);

    if(pos == 0) {
        puts("なにも含まれていませんでした");
    } else {
        printf("%d個含まれていました。", pos);
    }

    printf("%zu", sizeof(c));//配列の要素数を超過しても特に何もならない。切り捨てられる。しかし、表示のときは切り捨てられていない。

    return 0;
}