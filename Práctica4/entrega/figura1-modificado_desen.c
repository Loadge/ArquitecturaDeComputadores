// gcc -O0 figura1-modificado_desen.c -o figura1-modificado_desen-0 -lrt
// gcc -O1 figura1-modificado_desen.c -o figura1-modificado_desen-1 -lrt
// gcc -O2 figura1-modificado_desen.c -o figura1-modificado_desen-2 -lrt
// gcc -O3 figura1-modificado_desen.c -o figura1-modificado_desen-3 -lrt
// gcc -Os figura1-modificado_desen.c -o figura1-modificado_desen-4 -lrt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct {
        int a;
        int b;
}  s[5000];

int main(int argc, char **argv){

	struct timespec cgt1_inic,cgt2_inic; double ncgt_inic; //Para la inicialización.
	struct timespec cgt1_calc,cgt2_calc; double ncgt_calc; //Para los cálculos.

	int X1, X1_0, X1_1, X1_2, X1_3, X1_4; X1=X1_0=X1_1=X1_2=X1_3=X1_4=0;
	int X2, X2_0, X2_1, X2_2, X2_3, X2_4; X2=X2_0=X2_1=X2_2=X2_3=X2_4=0;
	int * R;
	int ii,i;
	R = (int*)malloc(40000*sizeof(int));

	clock_gettime(CLOCK_REALTIME,&cgt1_inic);
	//Inicialización de valores
	for(i=0; i<5000; i+=2){
		s[i].a = i;
		s[i].b = i;
		s[i+1].a = i+1;
		s[i+1].b = i+1;
	}
	clock_gettime(CLOCK_REALTIME,&cgt2_inic);
	ncgt_inic=	(double) (cgt2_inic.tv_sec-cgt1_inic.tv_sec)+
		(double) ((cgt2_inic.tv_nsec-cgt1_inic.tv_nsec)
		/(1.e+9));

	clock_gettime(CLOCK_REALTIME,&cgt1_calc);
/* ------------CUERPO DEL PROGRAMA----------  */

	for (ii=1; ii<=40000;ii++) {
		for(i=0; i<5000;i+=3){
			X1_0+=2*s[i].a+ii;
			X1_1+=2*s[i+1].a+ii;
			X1_2+=2*s[i+2].a+ii;
//			X1_3+=2*s[i+3].a+ii;
//			X1_4+=2*s[i+4].a+ii;

			X2_0+=3*s[i].a+ii;
			X2_1+=3*s[i+1].a+ii;
			X2_2+=3*s[i+2].a+ii;
//			X2_3+=3*s[i+3].a+ii;
//			X2_4+=3*s[i+4].a+ii;
		}
		X1 = X1_0 + X1_1 + X1_2 + X1_3 + X1_4;
		X2 = X2_0 + X2_1 + X2_2 + X2_3 + X2_4;
		if (X1<X2){
			R[ii]=X1;
		}else{
			R[ii]=X2;
		}
	}

/* ------------------------------------------ */
	clock_gettime(CLOCK_REALTIME,&cgt2_calc);
	ncgt_calc=	(double) (cgt2_calc.tv_sec-cgt1_calc.tv_sec)+
		(double) ((cgt2_calc.tv_nsec-cgt1_calc.tv_nsec)
		/(1.e+9));
	printf("Tiempo de inicialización: %f \n", ncgt_inic);

	printf("Tiempo de cálculo: %f \n", ncgt_calc);
	printf("TIEMPO TOTAL: %f \n", ncgt_inic+ncgt_calc);

	/* -- * /
	for(i=0; i<100; i++){
		printf("R[%d]= %d \n",i,R[i]);
	}
	/* -- */
	printf("R[0]=%d R[%d]=%d\n",R[0],ii-1,R[ii-1]);
	/* -- */

	free(R);
	return 0;

}
