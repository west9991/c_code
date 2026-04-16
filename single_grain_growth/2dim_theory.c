#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define NX 256
#define NY 256

int main(void)
{
    const int nx = NX;
    const int ny = NY;

//parameter settings//

    const float dx = 1.0E-6;
    const float dy = dx;

    const float gamma = 1.0;
    const float nn = 4.0;
    const float delta = nn*dx;
    const float amobi = 4.0E-12;

    const float ram = 0.1;
    const float bbb = 2.0*logf((1.0+(1.0-2.0*ram))/(1.0-(1.0-2.0*ram)))/2.0;

    const float www = 6.0*gamma*bbb/delta;

    const float beta = 0.5;
    const float df = 2.0*www/(3.0)*beta;

    const int N0 = 10;
    const float r0 = N0*dx;

    //velocity calculation

    float v_th;

    for(int N=N0; N<nx; N++) {
        char fvel[] = "vel_th.dat";
        v_th = amobi*(df-gamma/(dx*N));//二次元界面移動速度の理論式（モデル式）
        FILE *fp_v = fopen(fvel, "a");
        fprintf(fp_v, "%6d %16.7e\n", N, v_th*1.0E6);

        fclose(fp_v);
    }

    return 0;
}