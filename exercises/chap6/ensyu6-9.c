#include<stdio.h>

#define NUMBER 100
void rev_intary(int v[], int n)
{
    for(int i=0;i<(n/2);i++) {
        int t=v[i];
        v[i]=v[n-1-i];
        v[n-1-i]=t;
    }
}

int main(void)
{
    int n;
    int x[NUMBER];

    printf("—v‘f”‚ð“ü—Í\n");scanf("%d",&n);
    printf("Še—v‘f‚ð“ü—Í\n");
    for(int i=0;i<n;i++) {
        printf("%2d‚Â–ÚF",i+1);scanf("%d",&x[i]);
    }

    rev_intary(x,n);//”½“]
    printf("”½“]‚µ‚½”z—ñ‚Í‰º‚Ì‚æ‚¤‚É‚È‚è‚Ü‚·\n");
    printf("{");
    for(int i=0;i<n-1;i++) {
        printf("%d, ",x[i]);
    }
    printf("%d}",x[n-1]);

    return 0;
}