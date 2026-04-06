#include<stdio.h>

int main(void)
{
    char a[][5] = {"LISP", "C", "Ada"};
    char *p[] = {"PAUL", "X", "MAC"};

    printf("%zu, %zu\n", sizeof(a), sizeof(p));
    printf("%zu\n", sizeof(char *));
    //è„2çsÇÕsizeÇÃé¿å±

    for(int i=0; i<sizeof(a)/5; i++) {
        printf("a[%d] = \"%s\"\n", i, a[i]);
    }

    for(int i=0; i<sizeof(p)/sizeof(char *); i++) {
        printf("p[%d] = \"%s\"\n", i, p[i]);
    }

    return 0;
}