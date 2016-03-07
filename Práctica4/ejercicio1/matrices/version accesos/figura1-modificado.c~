// gcc -O0 figura1-modificado.c -o figura1-modificado-0
// gcc -O1 figura1-modificado.c -o figura1-modificado-1
// gcc -O2 figura1-modificado.c -o figura1-modificado-2
// gcc -O3 figura1-modificado.c -o figura1-modificado-3
// gcc -Os figura1-modificado.c -o figura1-modificado-4

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
	int X1, X2;
	int * R;
	int ii,i;
	R = (int*)malloc(40000*sizeof(int));
	
	clock_gettime(CLOCK_REALTIME,&cgt1_inic);
	//Inicialización de valores
	for(i=0; i<5000; i++){
		s[i].a = i;
		s[i].b = i;
	}
	clock_gettime(CLOCK_REALTIME,&cgt2_inic);


	ncgt_inic=	(double) (cgt2_inic.tv_sec-cgt1_inic.tv_sec)+
		(double) ((cgt2_inic.tv_nsec-cgt1_inic.tv_nsec)
		/(1.e+9));

	clock_gettime(CLOCK_REALTIME,&cgt1_calc);
/* ------------CUERPO DEL PROGRAMA----------  */

	for (ii=1; ii<=40000;ii++) {
		for(i=0; i<5000;i++)  X1+=2*s[i].a+ii; //Sumatoria en X1
		for(i=0; i<5000;i++)  X2+=3*s[i].b-ii; //Sumatoria en X2
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
