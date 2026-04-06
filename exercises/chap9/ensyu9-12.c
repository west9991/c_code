#include<stdio.h>

#define STRING_NUMBER 100
#define CHAR_NUMBER   128

void rev_strings(char s[][CHAR_NUMBER], int n)
{
    for (int i=0; i<n; i++) {
        int j=0;
        while(s[i][j]) {
            j++;
        }
        int c_size=j;

        for(int j=0; j<c_size/2; j++) {
            int temp=s[i][j];
            s[i][j] = s[i][c_size-1-j];
            s[i][c_size-1-j] = temp;
        }
    }

    for(int i=0; i<n; i++) {
        printf("s[%d] = \"%s\"\n", i, s[i]);
    }
}

void get_string(char s[][CHAR_NUMBER], int n)
{   
    int i=0;
    for(; i<n; i++) {

        int cnt=0;
        printf("s[%d] = ",i);
        scanf("%s", s[i]);
        
        int j=0;
        while(s[i][j]) {
            if(s[i][j] == '$') cnt++;
            j++;
        }
        if(s[i][5] == 0) cnt++;
        if(cnt == 6) break;
    }
    for(int k=0; k<i; k++) {
        printf("s[%d] =\"%s\"\n", k, s[k]);
    }

}

int main(void)
{
    int n=10;
    char s[STRING_NUMBER][CHAR_NUMBER];

    get_string(s,n);
    rev_strings(s,n);

    return 0;
}