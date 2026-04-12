#include<stdio.h>

int main(void)
{
    FILE *fp;
    char fname[FILENAME_MAX];

    printf("ファイル名：");
    scanf("%s", fname);
    
    if((fp=fopen(fname, "r"))== NULL)
        printf("ファイルをオープンできません");
    else {
        int ch;
        int kaigyou=0;
        while((ch= fgetc(fp)) != EOF) {
            if(ch=='\n') kaigyou++;
        }
        printf("改行の個数は%d個です。", kaigyou);

    }

    return 0;
}