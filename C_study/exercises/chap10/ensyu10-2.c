#include<stdio.h>

void decrement_date(int *y, int *m, int *d)
{
    //³‚µ‚¢“ü—Í‚ª‚³‚ê‚Ä‚¢‚é‚Æ‰¼’è
    if(*d <= 27) {
        d++;
    } else if(d == 28) {
        if((*y%100 == 0) && (*y%400 != 0)) {

        }
    }
}

//‚¢‚¢•û–@‚ğv‚¢‚Â‚­‚Ü‚Å•Û—¯