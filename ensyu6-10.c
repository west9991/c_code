#include<stdio.h>

#define NUMBER 100
void intary_rcpy(int v1[], const int v2[], int n)
{
    for(int i=0;i<n;i++) {
        int t=v2[i];
        v1[i]=v2[n-1-i];
        v1[n-1-i]=t;       
    }
}

int main(void)
{
    int n;
    int x1[NUMBER];
    int x2[NUMBER];

    printf("—v‘f”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B");
    scanf("%d",&n);

    printf("Œ³”z—ñ‚ÌŠe—v‘f‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢");
    for(int i=0;i<n;i++) {
        printf("%d‚Â–Ú",i+1);
        scanf("%d",&x2[i]);
    }

    intary_rcpy(x1,x2,n);

    printf("”½“]Œã‚Ì”z—ñ‚Í‰º‚Ì‚æ‚¤‚É‚È‚é");
    for(int i=0;i<n;i++) {
        printf("%3d",x1[i]);
    }

    return 0;
}