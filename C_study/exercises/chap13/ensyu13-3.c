#include<stdio.h>
#include<string.h>

void string_inverse(char *ch1, char *ch2)
{
    char ch_t[128];
    strcpy(ch_t, ch1);
    strcpy(ch1, ch2);
    strcpy(ch2, ch_t); 
}

void num_inverse(double *n1, double *n2)
{
    double t=*n1;
    *n1=*n2;
    *n2=t;
}

int main(void)
{
    FILE *fp;

    if((fp = fopen("hw.txt", "r")) == NULL) {
        printf("ファイルを開けませんでした。\n");
    } else {
        int ninzu=0;
        char name[20][100];
        double height[20];
        double weight[20];

        for(int i=0; fscanf(fp, "%s%lf%lf", name[i], &height[i], &weight[i]) == 3; i++) {
            ninzu++;
            for(int j=0; j<i; j++) {
                if(height[j] > height[j+1]) {
                    num_inverse(&height[j], &height[j+1]);
                    num_inverse(&weight[j], &weight[j+1]);
                    string_inverse(name[j], name[j+1]);
                }
            }
        }

        for(int i=0; i<ninzu; i++) {
            printf("%-10s %5.1f %5.1f\n", name[i], height[i], weight[i]);
        }
    }

    return 0;
}