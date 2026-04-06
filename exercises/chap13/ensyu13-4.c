#include<stdio.h>
#define NINZU 10
#define CHARLONG 100
int main(void)
{
    

    FILE *fp;

    if((fp = fopen("hito_data.txt", "w")) == NULL)
        printf("ファイルを開くことに失敗しました");
    else {
        int cnt=0;
        char name[NINZU][CHARLONG];
        double height[NINZU];
        double weight[NINZU];

        for(int i=0; i<NINZU; i++) {
            printf("%d人目：(名前、身長、体重) ", i+1);
            scanf("%s%lf%lf", name[i], &height[i], &weight[i]);
            
            int cnt_break=0;
            for(int j=0; j<3; j++) {
                if(name[i][j] == 'X') cnt_break++;
            }
            if(name[i][3] == '\0') cnt_break++;
            
            if(cnt_break == 4) break;
            cnt++;
        }

        for(int i=0; i<cnt; i++) {
            fprintf(fp, "%-10s %5.1f %5.1f\n", name[i], height[i], weight[i]);
        }

        fclose(fp);
    }

    return 0;
}