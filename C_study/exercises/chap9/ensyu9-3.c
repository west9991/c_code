#include<stdio.h>
#define CHAR_NUM 100
int main(void)
{
    char s[CHAR_NUM][128];
int cnt=0;
    for (int i = 0; i < CHAR_NUM; i++) {
        int cnt_br=0;

        printf("s[%d] : ", i);
        scanf("%s", s[i]);
        for(int j=0;j<5;j++) {
            if (s[i][j] == '$') cnt_br++;
        }
        if (s[i][5] == 0) cnt_br++;

        if (cnt_br == 6) break;

        cnt++;
    }

    for (int i=0; i<cnt; i++) {
        printf("s[%d] = \"%s\"\n", i, s[i]);
    }

return 0;
}