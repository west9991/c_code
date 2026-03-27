#include<stdio.h>

#define NUMBER 100
int search_idx(const int v[],int idx[], int key, int n)//target:v[n],key:key,->idx,idx_figure
{
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(v[i] == key) {
            idx[cnt++]=i;
        } 
    }

    return cnt;
}

int main(void)
{
    int n;
    int v[NUMBER];
    int idx[NUMBER];
    int key;

    printf("要素数 :");scanf("%d",&n);
    printf("keyを入力 :");scanf("%d",&key);
    printf("配列vの要素\n");
    for(int i=0;i<n;i++) {
        printf("%dつ目",i+1);scanf("%d",&v[i]);
    }

    printf("配列vの内、keyが入っている場所は、");
    for(int i=0;i<search_idx(v,idx,key,n);i++) {
        printf("%2d ",idx[i]+1);
    }
    printf("番目で、その個数は%d個です",search_idx(v,idx,key,n));

    return 0;
}