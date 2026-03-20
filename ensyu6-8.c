#include<stdio.h>

#define NUMBER  100
int min_of(const int v[], int n)
{
    int min=v[0];

    for(int i=1;i<n;i++)
    {
        if(v[i]<min) {
            min =v[i];
        }
    }

    return min;
}

int main(void)
{
    int x[NUMBER];
    int n; //—v‘f”
    printf("—v‘f”‚ð“ü—Í\n");scanf("%d",&n);
    printf("Še—v‘f‚ð“ü—Í\n");
    for(int i=0;i<n;i++) {
        printf("%2d‚Â–Ú:",i+1);scanf("%d",&x[i]);
    }

    printf("“ü—Í‚µ‚½”’l‚ÌÅ¬’l‚Í%d‚Å‚·\n",min_of(x,n));

    return 0;
}