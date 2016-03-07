// gcc -O2 pmm-secuencial.c -o pmm-secuencial -lrt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	int n;
	int i,j;
	struct timespec cgt1,cgt2; double ncgt;
		
	if(argc <2){
		fprintf(stderr, "Falta el tamaño de la matriz cuadrada\n");
		exit(-1);
	}
	n = atoi(argv[1]);

	double **matrizA;
	double **matrizB;
	double **matrizC;

	clock_gettime(CLOCK_REALTIME,&cgt1);
	//Creación de matrices
	matrizA = (double**) malloc(n*sizeof(double*));
	matrizB = (double**) malloc(n*sizeof(double*));
	matrizC = (double**) malloc(n*sizeof(double*));

	for(i=0; i<n;i++){matrizA[i]=(double*) malloc(n*sizeof(double));}
	for(i=0; i<n;i++){matrizB[i]=(double*) malloc(n*sizeof(double));}
	for(i=0; i<n;i++){matrizC[i]=(double*) malloc(n*sizeof(double));}
	
	//Inicialización
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				matrizB[i][j]=i+j;
				matrizC[i][j]=i+j;
		}
	}
	/* -- * /
	//Mostrar una de las matrices
	for(i=0; i < n; i++){
		for(j=0; j < n; j++){
			printf("%f ", matrizB[i][j]);
		}
		printf("\n");
	}
	/* -- */
	//Operaciones
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				matrizA[i][j] = matrizB[i][j] * matrizC[j][i];
		}
	}

	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=	(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)
		/(1.e+9));

/* -- */
printf("%f \n", ncgt);
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
}
