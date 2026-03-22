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
}