#define NX 256
#define NY 256
#define NZ 256

#define NEND 3000
#define NOUT 20
#define NVEL 20

#define mgn 1
#define EXT 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int rank = 0;
clock_t start, end;

void swap_f(float **f, float **fn)
{
    float *tmp = *f;
    *f = *fn;
    *fn = tmp;
}

//xyz order//

void BC_3Dxym_zeroflux(float *f, int nx, int ny, int nz, int buf)
{
    int lnx = nx + 2*buf;
    int lny = ny + 2*buf;

    for(int k=0; k<buf; k++){
        for(int i=0; i<lnx; i++){
            for(int j=0; j<lny; j++){
                f[i+lnx*j+(buf-1-k)] = f[i+lnx*j+(buf  +k)];
            }
        }
    }
}

void BC_3Dxyp_zeroflux(float *f, int nx, int ny, int nz, int buf)
{
    int lnx = nx + 2*buf;
    int lny = ny + 2*buf;

    for(int k=0; k<buf; k++){
        for(int i=0; i<lnx; i++){
            for(int j=0; j<lny; j++){
                f[i+lnx*j+lnx*lny*(buf+nz  +k)] = f[i+lnx*j+lnx*lny*(buf+nz-1-k)];
            }
        }
    }
}

void BC_3Dyzm_zeroflux(float *f, int nx, int ny, int nz, int buf)
{
    int lnx = nx + 2*buf;
    int lny = ny + 2*buf;
    int lnz = nz + 2*buf;

    for(int i=0; i<buf; i++){
        for(int j=0; j<lny; j++){
            for(int k=0; k<lnz; k++){
                f[lnx*j+lnx*lny*k+(buf-1-i)] = f[lnx*j+lnx*lny*k+(buf  +i)];
            }
        }
    }
}