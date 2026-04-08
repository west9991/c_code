#include<stdio.h>
#include<time.h>

char data_file[]= "datetime.dat";

void get_data(void)
{
    FILE *fp;

    if((fp = fopen(data_file, "r")) == NULL)
        printf("本プログラムを実行するのは初めてですね。\n");
    else {
        int year, month, day, h, m, s;
        char kibun[100];

        fscanf(fp, "%d%d%d%d%d%d%s", &year, &month, &day, &h, &m, &s, kibun);
        printf("前回は%d年%d月%d日%d時%d分%d秒で、気分は%sでした。", year, month, day, h, m, s, kibun);
    }
}

void put_data(void)
{
    FILE *fp;

    if((fp = fopen(data_file, "w")) == NULL)
        printf("ファイルをオープンできません。\n");
    else {
        time_t current = time(NULL);
        struct tm *timer = localtime(&current);
        char kibun[100];

        printf("現在の気分は：");
        scanf("%s", kibun);
        fprintf(fp, "%d %d %d %d %d %d %s\n",
                timer->tm_year +1900, timer->tm_mon +1, timer->tm_mday, timer->tm_hour, timer->tm_min, timer->tm_sec, kibun);

        fclose(fp);
    }
}

int main(void)
{
    get_data();

    put_data();

    return 0;
}