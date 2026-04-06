#define DEVICE_NUMBER 0

#define NX  256
#define NY  256

#define NEND  3000
#define NOUT    20
#define NVEL    20

#define mgn  1
#define EXT  2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int rank = 0;
clock_t start, mid, end;

//=================================================-=================================================//
//*****************************************Template Function*****************************************//
//=================================================-=================================================//

void swap_f(float **f, float **fn)
{
    float *tmp = *f;
    *f = *fn;
    *fn = tmp;
}

//=======================================================================

void swap_i(int **f, int **fn)
{
    int *tmp = *f;
    *f = *fn;
    *fn = tmp;
}

//=================================================-=================================================//

void BC_2Dxm_zeroflux(float *f, int nx, int ny, int buf)
{
	int lny = ny + 2*buf;
	int lnx = nx + 2*buf;

	for(int i=0; i<buf; i++){
	for(int j=0; j<lny; j++){
		f[lnx*j+(buf-1-i)] = f[lnx*j+(buf  +i)];
	}
	}
}

//=================================================

void BC_2Dxp_zeroflux(float *f, int nx, int ny, int buf)
{
	int lny = ny + 2*buf;
	int lnx = nx + 2*buf;

	for(int i=0; i<buf; i++){
	for(int j=0; j<lny; j++){
		f[lnx*j+(buf+nx  +i)] = f[lnx*j+(buf+nx-1-i)];
	}
	}
}

//=================================================

void BC_2Dym_zeroflux(float *f, int nx, int ny, int buf)
{
	int lnx = nx + 2*buf;

	for(int j=0; j<buf; j++){
	for(int i=0; i<lnx; i++){
		f[lnx*(buf-1-j) + i] = f[lnx*(buf  +j) + i];
	}
	}
}

//=================================================

void BC_2Dyp_zeroflux(float *f, int nx, int ny, int buf)
{
	int lnx = nx + 2*buf;

	for(int j=0; j<buf; j++){
	for(int i=0; i<lnx; i++){
		f[lnx*(buf+ny  +j) + i] = f[lnx*(buf+ny-1-j) + i];
	}
	}
}

//=================================================-=================================================//

void output_time(const char *outname)
{
	end = clock();
	double pas_time = (double)(end-start)/(double)CLOCKS_PER_SEC;
	double rep_time = (double)(end-mid  )/(double)CLOCKS_PER_SEC;
	int pas_timeofday_hou = (int)pas_time/3600;
	int pas_timeofday_min = (int)pas_time%3600/60;
	int pas_timeofday_sec = (int)pas_time%3600%60;
	//int rep_timeofday_hou = (int)rep_time/3600;
	//int rep_timeofday_min = (int)rep_time%3600/60;
	//int rep_timeofday_sec = (int)rep_time%3600%60;	
	mid = clock();

	time_t ltimer = time(NULL);
	struct tm *local = localtime(&ltimer);
	printf("%4d/", local->tm_year + 1900);
	printf("%2d/", local->tm_mon + 1);
	printf("%2d ", local->tm_mday);
	printf("%2d:", local->tm_hour);
	printf("%02d:", local->tm_min);
	printf("%02d", local->tm_sec);
	printf(" [%2d:%02d:%02d]",
		pas_timeofday_hou,
		pas_timeofday_min,
		pas_timeofday_sec);
	printf("(%7.2lf[sec])", rep_time);
	//printf(" [%2d:%02d:%02d]",
	//	rep_timeofday_hou,
	//	rep_timeofday_min,
	//	rep_timeofday_sec);
	printf(" %s\n",outname);
}

//=======================================================================

void paraview
(
	char *filename,
	int nx, 
	int ny,
	float dx,
	float dy,
	const float *p
)
{
   char fName[256];

   sprintf(fName,"%s.vtk",filename);
   FILE *fp = fopen(fName,"w");

   const int nx_1  = 0;
   const int nx_2  = nx;
   const int ny_1  = 0;
   const int ny_2  = ny;
   const int n_xa  = nx_2-nx_1;
   const int n_ya  = ny_2-ny_1;

   fprintf(fp, "# vtk DataFile Version 3.0\n");
   fprintf(fp, "output\n");
   fprintf(fp, "ASCII\n");
   fprintf(fp, "DATASET STRUCTURED_GRID\n");
   fprintf(fp, "DIMENSIONS %6d %6d %6d\n",n_xa,n_ya,1);
   fprintf(fp, "POINTS %10d float\n",n_xa*n_ya);
   
   for (int j=ny_1; j<ny_2; j++) {
   for (int i=nx_1; i<nx_2; i++) {
        fprintf(fp, "%16.7e %16.7e %16.7e\n",(float)i*dx, (float)j*dy, 0.);
   }
   }

   fprintf(fp, "POINT_DATA %10d\n",n_xa*n_ya*1);

   fprintf(fp, "SCALARS Phase-field float\n");
   fprintf(fp, "LOOKUP_TABLE default\n");

   for (int j=ny_1; j<ny_2; j++) {
   for (int i=nx_1; i<nx_2; i++) {
        const int ix = j*nx + i ;
        fprintf(fp, "%16.7e\n",p[ix]);
   }
   }

   fclose(fp);

}

//=================================================-=================================================//

void Phase_field
(
	const int  nx,
	const int  ny,
	const int lnx,
	const int lny,
	const float rdx,
	const float rdy,
	const float dt,
	const float aaa,
	const float www,
	const float beta,
	const float pmobi,
	const float *p,
	      float *pp
)
{
	for(int j=0; j<ny; j++){
	for(int i=0; i<nx; i++){

		const int ix = (j+mgn)*lnx + (i+mgn);
		
		const int im = ix-1;
		const int ip = ix+1;
		const int jm = ix-lnx;
		const int jp = ix+lnx;
		
		//const int imjm = ix-lnx-1;
		//const int imjp = ix+lnx-1;
		//const int ipjm = ix-lnx+1;
		//const int ipjp = ix+lnx+1;

		const float p_ix = p[ix];
		const float p_im = p[im];
		const float p_ip = p[ip];
		const float p_jm = p[jm];
		const float p_jp = p[jp];

		//const float p_imjm = p[imjm];
		//const float p_imjp = p[imjp];
		//const float p_ipjm = p[ipjm];
		//const float p_ipjp = p[ipjp];

	//<<pattern A>>//

		const float rpx = (p_im-(float)2.0*p_ix+p_ip)*rdx*rdx;
		const float rpy = (p_jm-(float)2.0*p_ix+p_jp)*rdy*rdy;

		const float dpi1 = aaa*aaa*(rpx+rpy);
		const float dpi2 = (float)4.0*www*p_ix*((float)1.0-p_ix)*(p_ix-(float)0.5+beta);
		const float dpi  = dpi1+dpi2;

		pp[ix] = p_ix+pmobi*dpi*dt;

	//<<pattern B>>//

		//pp[ix] = p_ix+pmobi*aaa*aaa*((p_im-(float)2.0*p_ix+p_ip)*rdx*rdx+(p_jm-(float)2.0*p_ix+p_jp)*rdy*rdy)
		//	    +(float)4.0*www*p_ix*((float)1.0-p_ix)*(p_ix-(float)0.5+beta)*dt;
	}
	}
}


//=================================================-=================================================//
//********************************************Main Function******************************************//
//=================================================-=================================================//

int main(int argc, char** argv)
{
	float *P, *PP;  //for CPU
	float *sum;

	const int nend = NEND;
	const int nout = NOUT;

	const int nx = NX;
	const int ny = NY;

	const int lnx = nx+2*mgn;
	const int lny = ny+2*mgn;

	const int enx = nx/EXT;
	const int eny = ny/EXT;

//<<parameter setting>>//
	const float dx = 0.02;
	const float dy = dx;

	const float gamma = 1.0;
	const float nn    = 4.0;
	const float delta = nn*dx;
	const float amobi = 1.0;

	const float ram   = 0.1;
	const float bbb   = 2.0*logf((1.0+(1.0-2.0*ram))/(1.0-(1.0-2.0*ram)))/2.0;
	
	const float aaa   = sqrtf(3.0*delta*gamma/bbb);
	const float www   = 6.0*gamma*bbb/delta;
	const float pmobi = amobi*sqrtf(2.0*www)/(6.0*aaa);
	
	const float beta  = 0.05*nn;
	const float df    = 2.0*www/(3.0)*beta;

	const float dt    = dx*dx/(5.*pmobi*aaa*aaa);

	//Initial data output
	FILE *fini = fopen("initial.dat", "w");
	if(fini == NULL){
		fprintf(stderr,"I can't open initial.dat\n");
		exit(1);
	} 

	fprintf(fini, "<<<<< Setting Data >>>>> \n");
	fprintf(fini, "nx                 [-] =  %10d\n", nx);
	fprintf(fini, "ny                 [-] =  %10d\n", ny);

	fprintf(fini, "<<<<< Dimensional values >>>>> \n");
	fprintf(fini, "Interface thickness [m] =  %16.7e\n", delta);
	fprintf(fini, "Lattice size        [m] =  %16.7e\n", dx);
	fprintf(fini, "Time increment      [s] =  %16.7e\n", dt);
	fclose(fini);
	
//<<MemoryAllocation>>//

	P  = (float *) malloc(lnx*lny*sizeof(float));
	PP = (float *) malloc(lnx*lny*sizeof(float));
	if(P  == NULL){fprintf(stderr,"I can't alloc P\n" );exit(1);} 
	if(PP == NULL){fprintf(stderr,"I can't alloc PP\n");exit(1);} 

//<<Initial profile Setting>>//
	float r0=10.*dx;
	for(int j=0; j<ny; j++){
	for(int i=0; i<nx; i++){

		const int ix = (j+mgn)*lnx + (i+mgn);
		
		float xx = (float)i*dx;
		float yy = (float)j*dy;

		float rr = sqrtf(xx*xx+yy*yy)-r0;

		P[ix] = 0.5*(1.0-tanhf(sqrtf(2.0*www)/(2.0*aaa)*rr));
	}
	}

//<<interface velocity along x-axies initialaize>>//
	float xx05 = 0.0;
	float  x05 = 0.0;
	int   nvel = NVEL;

	for(int i=0; i<nx-1; i++){
		const int ix = mgn*lnx + (i+mgn);
		if(P[ix]>=0.5 && P[ix+1]<0.5){
			xx05 = (float)(i+1)*dx - (0.5-P[ix+1])/(P[ix]-P[ix+1])*dx;
			break;
		}	
	}

	if (rank==0) {
		char ftime[256];
		sprintf(ftime, "main loop start");
		output_time(ftime);
	}

//<<<<<<<<<<<<<<<<<<<<<<<<< main loop start >>>>>>>>>>>>>>>>>>>>>>>>>//

	for(int nstep=1; nstep<=nend ; nstep++){
		
		//zero flux boundary condition apply
		BC_2Dxm_zeroflux(P, nx, ny, mgn);
		BC_2Dxp_zeroflux(P, nx, ny, mgn);
		BC_2Dym_zeroflux(P, nx, ny, mgn);
		BC_2Dyp_zeroflux(P, nx, ny, mgn);

		//**************************************************************************************//
		Phase_field(nx,ny,lnx,lny,1.0/dx,1.0/dy,dt,aaa,www,beta,pmobi,P,PP);
		//**************************************************************************************//

		swap_f(&P,  &PP);

		//interface velocity measuring
		if(nstep%nvel==0){

			for(int i=0; i<nx-1; i++){
				const int ix = mgn*lnx + (i+mgn);
				if(P[ix]>=0.5 && P[ix+1]<0.5){
					x05 = (float)(i+1)*dx - (0.5-P[ix+1])/(P[ix]-P[ix+1])*dx;
					break;
				}	
			}
			const float u05 = (x05-xx05)/(dt*(float)nvel);
			xx05 = x05;

			char fvel[] = "vel.dat";
			FILE *fp_v = fopen(fvel,"a");
			fprintf(fp_v, "%6d %16.7e %16.7e %16.7e\n", nstep, (float)nstep*dt, x05, u05);
			fclose(fp_v);
		}

		//grain volume measuring
		if(nstep%nout==0){
			
			double vol = 0.;
			for(int j=0; j<ny; j++){
			for(int i=0; i<nx; i++){
				const int ix = (j+mgn)*lnx + (i+mgn);

				vol += P[ix]*dx*dy;
			}
			}

			char fvol[] = "vol.dat";
			FILE *fp_v = fopen(fvol,"a");
			fprintf(fp_v, "%6d %16.7e %16.7e\n", nstep, (float)nstep*dt, vol);
			fclose(fp_v);
		}

		//visualized
		if(nstep%nout==0){
			
			for(int j=0; j<eny; j++){
			for(int i=0; i<enx; i++){
				const int ix1 = (j*EXT+mgn)*lnx + (i*EXT+mgn);
				const int ix0 = j*enx + i;

				PP[ix0] = P[ix1];

			}
			}
			
			char fvti[256];
			sprintf(fvti,"out_%08d",nstep);	
			paraview(fvti,enx, eny, dx*(float)EXT, dy*(float)EXT, PP);
		}

		if (rank==0 && nstep%nout == 0) {
			char ftime[256];
			sprintf(ftime, "nstep = %6d", nstep);
			output_time(ftime);
		}

	}
	
//<<<<<<<<<<<<<<<<<<<<<<<<< main loop finish >>>>>>>>>>>>>>>>>>>>>>>>>//
	
	if (rank==0) {
		char ftime[256];
		sprintf(ftime, "main loop finish");
		output_time(ftime);
	}

	free(P);
	free(PP);

	return 0;
}

//=================================================-=================================================//
//************************************************END************************************************//
//=================================================-=================================================//