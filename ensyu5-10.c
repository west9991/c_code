#include<stdio.h>

int main(void)
{
    int a[4][3];
    int b[3][4];
    int c[4][4] ={0};

    printf("s—ñA‚Ì¬•ª‚ğ“ü—Í(®”)\n");
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            printf("(%d,%d)¬•ª:",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }

    printf("s—ñB‚Ì¬•ª‚ğ“ü—Í(®”)\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            printf("(%d,%d)¬•ª:",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            for(int k=0;k<3;k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("ŒvZŒ‹‰Ê---------------\n");
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            printf("%3d",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}