#include<stdio.h>

#define HUMAN 6
#define SUBJ  2
int main(void)
{
    int point[HUMAN][SUBJ];

    printf("6人の2科目の点数を入力して¥n");
    for(int i=0;i<HUMAN;i++) {
        for(int j=0;j<SUBJ;j++) {
            printf("%d人目%d科目目：",i+1,j+1);
            scanf("%d",&point[i][j]);
        }
    }

    int subj_sum[SUBJ]={0};

    for(int j=0;j<SUBJ;j++) {
        for(int i=0;i<HUMAN;i++) {
            subj_sum[j] +=point[i][j];
        }
    }

    int human_sum[HUMAN]={0};

    for(int i=0;i<HUMAN;i++) {
        for(int j=0;j<SUBJ;j++) {
            human_sum[i] += point[i][j];
        }
    }
    
    for(int i=0;i<SUBJ;i++) {
        printf("%d科目目の合計点は%3d点、平均点は%.2f点です¥n",i+1,subj_sum[i],(double)subj_sum[i]/HUMAN);
    }

    for(int i=0;i<HUMAN;i++) {
        printf("%d人目の2科目の合計点は%3d点、平均点は%.2f点です¥n",i+1,human_sum[i],(double)human_sum[i]/SUBJ);
    }

    return 0;
}