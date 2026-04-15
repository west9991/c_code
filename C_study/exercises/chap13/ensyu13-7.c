#include<stdio.h>

void number_count(int s, int cnt[])
{
    if(s>='0' && s<='9')
        cnt[s-'0']++;
}

int main(void)
{
    FILE *fp;
    char fname[FILENAME_MAX];

    printf("ファイル名：");
    scanf("%s", fname);

    if((fp=fopen(fname, "r")) == NULL)
        printf("ファイルをオープンできません");
    else {
        int chnum[10]={0};
        int ch;
        while((ch = fgetc(fp)) != EOF) 
            str_dcount(ch, chnum);

            for(int i=0; i<10; i++) {
                printf("%d : %d\n", i, chnum[i]);
            }
    }

    return 0;
}