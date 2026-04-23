#define DEVICE_NUMBER 0

#define NX  256 //空間サイズ（もともとは格子点数）
#define NY  256

#define NEND   3000 //時間増分を何回増分して実行するか
#define NOUT     20 //時間増分何回あたり、ファイルに出力するのかを決めている（下も同様）
#define NVEL     20
#define INI     100 //初期化プロファイルが維持されているかを確認する回数

#define mgn  1
#define EXT  2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <time.h>
//#include <sys/time.h>
//差分法に余分に上下左右がいるから1枠増やしている。あくまで計算に使用した領域が、256*256と表現できるようにするための工夫

int rank = 0;
clock_t start, mid, end; //CPUの実行時間計測のための変数

//=================================================-=================================================//
//*****************************************Template Function*****************************************//
//=================================================-=================================================//

void swap_f(float **f, float **fn) //ポインタの指す先の置換
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

//零ノイマン条件↓
void BC_2Dxm_zeroflux(float *f, int nx, int ny, int buf) //領域左端の境界条件
{
	int lny = ny + 2*buf;
	int lnx = nx + 2*buf;

	for(int i=0; i<buf; i++){
	for(int j=0; j<lny; j++){
		f[lnx*j+(buf-1-i)] = f[lnx*j+(buf  +i)]; /*1列右のphase-field変数の値をコピーしている***************Initial Profile Settingでは、内側の領域にか設定してないが、コピーする値はあるのか？
												mallocで確保したメモリには、初期値としてゴミが入っているので、四隅には（1回目の計算では）ごみの値が集積するが、二回目以降の計算で、内部領域の情報
												が、正しく入力されるので問題ない*/	
	}
	}
}

//=================================================

void BC_2Dxp_zeroflux(float *f, int nx, int ny, int buf) //領域右端の境界条件
{
	int lny = ny + 2*buf;
	int lnx = nx + 2*buf;

	for(int i=0; i<buf; i++){
	for(int j=0; j<lny; j++){
		f[lnx*j+(buf+nx  +i)] = f[lnx*j+(buf+nx-1-i)]; //-1が入る部分に隙間を開けて、読みやすくしている
	}
	}
}

//=================================================

void BC_2Dym_zeroflux(float *f, int nx, int ny, int buf) //領域下端の境界条件
{
	int lnx = nx + 2*buf;

	for(int j=0; j<buf; j++){
	for(int i=0; i<lnx; i++){
		f[lnx*(buf-1-j) + i] = f[lnx*(buf  +j) + i];
	}
	}
}

//=================================================

void BC_2Dyp_zeroflux(float *f, int nx, int ny, int buf) //領域上端の境界条件
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
	double rep_time = (double)(end-mid  )/(double)CLOCKS_PER_SEC; //midは何のための時間->このプログラムでは使われてない
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

//paraviewがわかってから読むかな？
void paraview //内部で繰り返すから、データ消去の文を書かなくていい//
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


void Initial_profile_output
(
	const float *p,
	const int lnx,
	char *filename
)
{
	char ini[256];
	sprintf(ini, "%s.dat", filename);
	FILE *fini_pro = fopen(ini, "w");
	for(int i=mgn; i<lnx-mgn; i++){
		fprintf(fini_pro, "%10d %16.7e\n", i, p[(lnx*mgn)+i]);
	}

	fclose(fini_pro);
}


void Phase_field
(
	const int  nx, //格子点数
	const int  ny, 
	const int lnx, //外側に1格子増やす文
	const int lny,
	const float rdx, //  1.0/dx　割り算を差分法時に使わないため（なぜかは知らない）
	const float rdy, //  1.0/dy
	const float dt, //時間増分
	const float aaa, //勾配係数
	const float www, //エネルギー障壁
	const float beta,
	const float pmobi, //phaseモビリティ
	const float *p,
	      float *pp,
	int         nstep
)
{
	for(int j=0; j<ny; j++){
	for(int i=0; i<nx; i++){

		const int ix = (j+mgn)*lnx + (i+mgn); //二次元現象を1次元配列に収めるためのカウント方法による式（ノート参照）		
		const int im = ix-1;
		const int ip = ix+1; //x方向は左右の移動は1でいい
		const int jm = ix-lnx; //y方向に移動する場合はlnx（1次元配列内を）移動したと考えなければならない
		const int jp = ix+lnx;
		
		//const int imjm = ix-lnx-1;
		//const int imjp = ix+lnx-1;
		//const int ipjm = ix-lnx+1;
		//const int ipjp = ix+lnx+1;

		//ポインタを配列として使う場合、p[*]は、エイリアスになる（&p[*]が、エイリアスのアドレス）

		const float p_ix = p[ix]; //ポインタを初期化していないが、何が代入されるのか（仮引数だからmain関数内で*p,*ppは決まる）
		const float p_im = p[im]; //mallocでメモリを確保して、Initial profile SettingでP[ix]をきめている
		const float p_ip = p[ip];
		const float p_jm = p[jm];
		const float p_jp = p[jp];

		//const float p_imjm = p[imjm];
		//const float p_imjp = p[imjp];
		//const float p_ipjm = p[ipjm];
		//const float p_ipjp = p[ipjp];

	//<<pattern A>>//

		const float rpx = (p_im-(float)2.0*p_ix+p_ip)*rdx*rdx; //二回偏微分
		const float rpy = (p_jm-(float)2.0*p_ix+p_jp)*rdy*rdy; //二回偏微分

		const float dpi1 = aaa*aaa*(rpx+rpy); //拡散項
		const float dpi2 = (float)4.0*www*p_ix*((float)1.0-p_ix)*(p_ix-(float)0.5+beta); //反応項
		const float dpi  = dpi1+dpi2; //時間発展方程式によるphase-field変数の時間変化

		pp[ix] = p_ix+pmobi*dpi*dt; //次の時間の位置毎のphase-field変数の値の格納

		//異常相を見つけるためのプログラム

		if(i == 20 && j == 20){ // 試しに、点（20，20）に注目
			char ijou[] = "ijou.dat";
			FILE *fijou = fopen(ijou, "a");
			fprintf(fijou, "step:%04d   kakusan:%16.7e   hannou:%16.7e   dpi:%16.7e   pp[2,2]:%16.7e\n", nstep, dpi1*dt*pmobi, dpi2*dt*pmobi, dpi*dt*pmobi, pp[ix]);

			fclose(fijou);
		}
	}
	}
}


//=================================================-=================================================//
//********************************************Main Function******************************************//
//=================================================-=================================================//

int main(void)
{
	float *P, *PP;  //for CPU
	//float *sum;

	const int XX   = 1; //全体の空間サイズを固定するための定数
	const int nend = NEND; 
	const int nout = NOUT;

	const int nx = NX*XX;
	const int ny = NY*XX;

	const int lnx = nx+2*mgn;
	const int lny = ny+2*mgn;

	const int enx = nx/EXT; //paraview用の変数
	const int eny = ny/EXT;

//<<parameter setting>>//
	const float dx = 1.0E-6/(float)XX;
	const float dy = dx;

	const float gamma = 1.0;
	const float nn    = 4.0;
	const float delta = nn*dx;
	const float amobi = 4.0E-12;

	const float ram   = 0.1;
	const float bbb   = 2.0*logf((1.0+(1.0-2.0*ram))/(1.0-(1.0-2.0*ram)))/2.0;
	
	const float aaa   = sqrtf(3.0*delta*gamma/bbb);
	const float www   = 6.0*gamma*bbb/delta;
	const float pmobi = amobi*sqrtf(2.0*www)/(6.0*aaa);
	
	const float beta  = 0.5;
	const float df    = 2.0*www/(3.0)*beta;

	const float dt    = dx*dx/(5.*pmobi*aaa*aaa);

	double error_max=0;
	//file delete
	FILE *delete_vel = fopen("vel.dat", "w");
	fclose(delete_vel);
	FILE *delete_vol = fopen("vol.dat", "w");
	fclose(delete_vol);
	
	char del_th[256];
	sprintf(del_th, "vel_th.dat");
	FILE *delete_th = fopen(del_th, "w");


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
	fprintf(fini, "Interface thickness  [m]        =  %16.7e\n", delta);
	fprintf(fini, "Lattice size         [m]        =  %16.7e\n", dx);
	fprintf(fini, "Time increment       [s]        =  %16.7e\n", dt);
	fprintf(fini, "Interfacial energy   [J/m^2]    =  %16.7e\n", gamma);
	fprintf(fini, "Interfacial mobility [m^4/(Js)] =  %16.7e\n", amobi);
	fprintf(fini, "Beta                 [-]        =  %16.7e\n", beta);

	fclose(fini);
	
//<<MemoryAllocation>>//

	P  = (float *) malloc(lnx*lny*sizeof(float));
	PP = (float *) malloc(lnx*lny*sizeof(float));
	if(P  == NULL){fprintf(stderr,"I can't alloc P\n" );exit(1);} 
	if(PP == NULL){fprintf(stderr,"I can't alloc PP\n");exit(1);} 

//<<Initial profile Setting>>//
	int N0 = 10;
	float r0=N0*dx;
	for(int j=0; j<ny; j++){
	for(int i=0; i<nx; i++){

		const int ix = (j+mgn)*lnx + (i+mgn);
		
		float xx = (float)i*dx; //内側の座標基準
		float yy = (float)j*dy;

		float rr = sqrtf(xx*xx+yy*yy)-r0;

		P[ix] = 0.5*(1.0-tanhf(sqrtf(2.0*www)/(2.0*aaa)*rr));//1次元平衡プロファイル
	}
	}

	//initial_profile_first

	char syoki[256];
	sprintf(syoki, "initial_profile_out_0000");
	Initial_profile_output(P, lnx, syoki);
//<<interface velocity along x-axies initialaize>>//
	float xx05 = 0.0;
	float  x05 = 0.0;
	int   nvel = NVEL;

	//下では、x軸に沿った位置における界面の位置を、界面近傍でphase-field変数のx方向の勾配が幅dxでは一定だと線形近似して、界面の位置を（格子点の座標で表現するよりは）精度よく計算している（ノート参照）
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
		Phase_field(nx,ny,lnx,lny,1.0/dx,1.0/dy,dt,aaa,www,beta,pmobi,P,PP, nstep);
		//**************************************************************************************//

		swap_f(&P,  &PP);

		//interface velocity measuring
		if(nstep%nvel==0){ //PF計算nvelステップごとに界面移動速度を計算している
			static int i=0; //格子点番号の出力のために静的記憶域機関にしている
			for(; i<nx-1; i++){
				const int ix = mgn*lnx + (i+mgn);
				if(P[ix]>=0.5 && P[ix+1]<0.5){
					x05 = (float)(i+1)*dx - (0.5-P[ix+1])/(P[ix]-P[ix+1])*dx;
					break;
				}	
			}
			const float u05 = (x05-xx05)/(dt*(float)nvel);
			xx05 = x05;

			//誤差計算

			double v_th = amobi*(df-gamma/(x05));//対称性より粒半径はx05でいい
			double error_v = fabs((v_th - u05)/u05)*100; //誤差率[%]で計算


			char ferror[] = "error.dat";
			FILE *fp_e = fopen(ferror, "a");
			fprintf(fp_e, "%16.7e %16.7e\n", x05*1.0E6, error_v);

			
			fclose(fp_e);

			char fvel[] = "vel.dat"; //界面移動速度を書き込むファイル
			FILE *fp_v = fopen(fvel,"a"); //追記モード
			fprintf(fp_v, "%6d %16.7e %16.7e %6d %16.7e\n", nstep, (float)nstep*dt, x05*1.0E6, i, u05*1.0E6); /*書き込む内容：ステップ数、物理的な経過時間、界面位置、格子点番号、界面移動速度
																												単位を[μm]に直すために10^6を乗算*/
			fclose(fp_v);
		}

		//grain volume measuring
		if(nstep%nout==0){ //noutステップごとに出力
			
			double vol = 0.;
			for(int j=0; j<ny; j++){
			for(int i=0; i<nx; i++){
				const int ix = (j+mgn)*lnx + (i+mgn);

				vol += P[ix]*dx*dy; //phase-field変数の値が、1の相の面積を計算している（格子点で見て、値としては格子の面積の総和で計算している）
			}
			}

			char fvol[] = "vol.dat";
			FILE *fp_v = fopen(fvol,"a");
			fprintf(fp_v, "%6d %16.7e %16.7e\n", nstep, (float)nstep*dt, vol*1.0E12); //ステップ数、物理的経過時間、面積（単位を[(μm)^2]にするために10^12を乗算）
			fclose(fp_v);
		}

		//visualized　節約のため？か、二倍（面積にすると４倍荒くなっている）
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

		if(nstep%INI==0){
			char fini[256];
			sprintf(fini, "initial_profile_out_%04d", nstep);
			Initial_profile_output(P, lnx, fini);
		}

		
		if (rank==0 && nstep%nout == 0) {
			char ftime[256];
			sprintf(ftime, "nstep = %6d", nstep);
			output_time(ftime);
		}

	}
	//界面速度の理論式output
	for(int N=N0; N<nx; N++) {
        char fvel[128];
        sprintf(fvel, "vel_th.dat");
        double v_th = amobi*(df-gamma/(dx*N));//二次元界面移動速度の理論式（モデル式）
        FILE *fp_v = fopen(fvel, "a");
        fprintf(fp_v, "%6d %16.7e\n", N, v_th*1.0E6);

        fclose(fp_v);
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