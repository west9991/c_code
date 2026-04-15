/*関数マクロは1文（あるいは1式）で表現されなければならない。
かつ、（内部的に）1行で表現されなければならない。*/

#include<stdio.h>

#define swap(type, a, b) \
do { \
    type t= (a); \
    (a) = (b); \
    (b) = (t); \
} while (0)

int main(void)
{
    int a=10,b=66;
    swap(int,a,b);
    printf("a=%d, b=%d",a,b);

    return 0;
}