#include<stdio.h>

void mat_mul(const int a[4][3], const int b[3][4], int c[4][4])
{
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            for(int k=0;k<3;k++) {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main(void)
{
    int a[4][3];
    int b[3][4];
    int c[4][4]={0};

        puts("matrixA‚Ì—v‘f‚ð“ü—Í");
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            printf("[%2d,%2d]",i+1,j+1);scanf("%d",&a[i][j]);
        }
    }

    puts("matrixB‚Ì—v‘f‚ð“ü—Í");
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            printf("[%2d,%2d]",i+1,j+1);scanf("%d",&b[i][j]);
        }
    }

    mat_mul(a,b,c);

    puts("matrixC‚ÌŒ‹‰Ê‚Í");
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            printf("%4d",c[i][j]);
        }
        putchar('\n');
    }

    return 0;
}