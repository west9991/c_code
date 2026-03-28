//4人の学生3科目

#include<stdio.h>

#define TEST1 1
#define TEST2 2

void mat_ass(const int x[4][3], int c[2][4][3],int test_no)
{
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            c[test_no][i][j]=x[i][j];
        }
    }
}

void mat_add(int d[4][3], const int c[2][4][3])
{
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            d[i][j]=c[1][i][j]+c[2][i][j];
        }
    }
}

void mat_print(int d[4][3])
{
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            printf("%4d",d[i][j]);
        }
        putchar('\n');
    }
}

int main(void)
{
    int test1[4][3]={{91,63,78},{67,72,46},{89,34,53},{32,54,34}};
    int test2[4][3]={{97,67,82},{73,43,46},{97,56,21},{85,46,35}};
    int test_mat[2][4][3]={0};
    int test_addition[4][3]={0};

    mat_ass(test1,test_mat,TEST1);
    mat_ass(test2,test_mat,TEST2);

    mat_add(test_addition,test_mat);
    puts("-----一回目----");mat_print(test1);
    puts("-----二回目----");mat_print(test2);
    puts("-----合計点----");mat_print(test_addition);

    return 0;
}