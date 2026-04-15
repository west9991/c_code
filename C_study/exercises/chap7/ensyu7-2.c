/*bitはint型系やchar型のオブジェクトが内部的に持っている情報であり、ビット系の演算子が周囲に存在するときに
オペランドとしてその機能を発揮する。（常に持っているが示せと言われるまでは示さない）*/

#include<stdio.h>

int mlt_bit(unsigned x, int n)
{
    x <<= n;
    return x;
}

int div_bit(unsigned x, int n)
{
    return x >>= n;
}

int mlt(unsigned x,int n)
{
    for(int i=0;i<n;i++) {
        x *= 2;
    }
    return x;
}

int div(unsigned x,int n)
{
    for(int i=0;i<n;i++) {
        x /=2;
    }
    return x;
}

int main(void)
{
    int n;
    unsigned x;
    printf("非負の整数を入力:");scanf("%d",&x);
    printf("べき乗数を入力:");scanf("%d",&n);
    printf("bit:x*2^n:%d\n",mlt_bit(x,n));
    printf("algebra:x*2^n:%d\n",mlt(x,n));
    printf("bit:x/2^n:%d\n",div_bit(x,n));//ただし、余りは割る度に切り捨てられる
    printf("algebra:x/2^n:%d\n",div(x,n));

    return 0;
}