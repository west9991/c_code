#include<stdio.h>

int combination(int n, int r)
{
    int ncr;
    if(r==0 || r==n) {
        ncr = 1;
    } else if(r==1) {
        ncr = n;
    } else {
        ncr = combination(n-1, r-1) + combination(n-1, r);
    }

    return ncr;
}

int main(void){
    int n,r;
    puts("非負の整数値nとn以下の非負の整数値rを入力");
    do {
        puts("n");scanf("%d", &n);
        puts("r");scanf("%d", &r);
    } while(n <0 || r < 0 || n<r);

    printf("%d個のものから%d個のものを選ぶ場合の数は%d通りです。",\
    n, r, combination(n,r));

return 0;
}