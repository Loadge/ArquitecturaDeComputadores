// gcc -O2 pmm-secuencial-modificado.c -o pmm-secuencial-modificado -lrt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	int n;
	int i,j;
struct timespec cgt1_inic,cgt2_inic; double ncgt_inic; //Para la inicialización.
	struct timespec cgt1_calc,cgt2_calc; double ncgt_calc; //Para los cálculos.
		
	n = 10000;

	double **matrizA;
	double **matrizB;
	double **matrizC;

	//Creación de matrices
	matrizA = (double**) malloc(n*sizeof(double*));
	matrizB = (double**) malloc(n*sizeof(double*));
	matrizC = (double**) malloc(n*sizeof(double*));

	for(i=0; i<n;i++){matrizA[i]=(double*) malloc(n*sizeof(double));}
	for(i=0; i<n;i++){matrizB[i]=(double*) malloc(n*sizeof(double));}
	for(i=0; i<n;i++){matrizC[i]=(double*) malloc(n*sizeof(double));}
	
	//Inicialización
	clock_gettime(CLOCK_REALTIME,&cgt1_inic);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				matrizB[i][j]=i+j;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				matrizC[i][j]=i+j;
		}
	}
	clock_gettime(CLOCK_REALTIME,&cgt2_inic);
	ncgt_inic=	(double) (cgt2_inic.tv_sec-cgt1_inic.tv_sec)+
		(double) ((cgt2_inic.tv_nsec-cgt1_inic.tv_nsec)
		/(1.e+9));
	/* -- * /
	//Mostrar una de las matrices
	for(i=0; i < n; i++){
		for(j=0; j < n; j++){
			printf("%f ", matrizB[i][j]);
		}
		printf("\n");
	}
	/* -- */

	clock_gettime(CLOCK_REALTIME,&cgt1_calc);
/* ------------CUERPO DEL PROGRAMA----------  */
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				matrizA[i][j] = matrizB[i][j] * matrizC[j][i];
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
	for(i=0; i < n; i++){
		for(j=0; j < n; j++){
			printf("%f ", matrizA[i][j]);
		}
		printf("\n");
	}

/* -- */
	printf("matrizA[0][0]=%f /\nmatrizA[%d][%d]=%f  /\n",matrizA[0][0],n-1,n-1,matrizA[n-1][n-1]);

/* -- */

	free(matrizA);
	free(matrizB);
	free(matrizC);

	return 0;

}
