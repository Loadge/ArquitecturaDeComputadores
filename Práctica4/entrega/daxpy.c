// gcc daxpy.c -o daxpy-0 -lrt
// gcc -O1 daxpy.c -o daxpy-1 -lrt
// gcc -O2 daxpy.c -o daxpy-2 -lrt
// gcc -O3 daxpy.c -o daxpy-3 -lrt
// gcc -Os daxpy.c -o daxpy-4 -lrt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	int n;
	int i;
	struct timespec cgt1_inic,cgt2_inic; double ncgt_inic; //Para la inicialización.
	struct timespec cgt1_calc,cgt2_calc; double ncgt_calc; //Para los cálculos.
		
	n =152000000;
	//    |  | 

	double *vector;
	double *vFinal;
	double alpha=500;

	//Creación de vectores
	vector = (double*) malloc(n*sizeof(double));
	vFinal  = (double*) malloc(n*sizeof(double));
	
	//Inicialización
	clock_gettime(CLOCK_REALTIME,&cgt1_inic);

	for(i=0;i<n;i+=3){vector[i]=i; vector[i+1]=i+1; vector[i+2]=i+2;}
	for(i=0;i<n;i+=3){vFinal[i]=i; vFinal[i+1]=i+1; vFinal[i+2]=i+2;}

	clock_gettime(CLOCK_REALTIME,&cgt2_inic);
	ncgt_inic=	(double) (cgt2_inic.tv_sec-cgt1_inic.tv_sec)+
		(double) ((cgt2_inic.tv_nsec-cgt1_inic.tv_nsec)
		/(1.e+9));

	clock_gettime(CLOCK_REALTIME,&cgt1_calc);
/* ------------CUERPO DEL PROGRAMA----------  */
	for(i=0;i<n;i+=3){
		vFinal[i] = alpha*vector[i] + vFinal[i];
		vFinal[i+1] = alpha*vector[i+1] + vFinal[i+1];
		vFinal[i+2] = alpha*vector[i+2] + vFinal[i+2];
	}
/* ------------------------------------------ */
	clock_gettime(CLOCK_REALTIME,&cgt2_calc);
	ncgt_calc=	(double) (cgt2_calc.tv_sec-cgt1_calc.tv_sec)+
		(double) ((cgt2_calc.tv_nsec-cgt1_calc.tv_nsec)
		/(1.e+9));
	printf("Tiempo de inicialización: %f \n", ncgt_inic);

	printf("Tiempo de cálculo: %f \n", ncgt_calc);
	printf("TIEMPO TOTAL: %f \n", ncgt_inic+ncgt_calc);

/* -- */
	printf("vFinal[0]=%f /\nvFinal[%d]=%f  /\n",vFinal[0],n-1,vFinal[n-1]);
/* -- */

	return 0;

}
