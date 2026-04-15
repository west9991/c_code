#include<stdio.h>

#define STRING_NUMBER 100
#define CHAR_NUMBER   128

void get_string(char s[][CHAR_NUMBER])
{   
    int i=0;
    for(; i<STRING_NUMBER; i++) {

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
    char s[STRING_NUMBER][CHAR_NUMBER];

    get_string(s);

    return 0;
}