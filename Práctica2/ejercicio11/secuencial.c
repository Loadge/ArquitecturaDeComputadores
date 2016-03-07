// gcc -O2 secuencial.c -o secuencial -fopenmp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){
	int n;
	int i,j;
	double cgt1,cgt2,ncgt;
		
	if(argc <2){
		fprintf(stderr, "Falta el tamaño de la matriz cuadrada\n");
		exit(-1);
	}
	n = atoi(argv[1]);

	double **matriz;
	double *vector;
	double *vSuma;

	cgt1 = omp_get_wtime();
	//Creación de vectores
	vector = (double*) malloc(n*sizeof(double));
	vSuma  = (double*) malloc(n*sizeof(double));
	//Creación de matriz
	matriz = (double**) malloc(n*sizeof(double*)); 
	for(i=0; i<n;i++){
		matriz[i]=(double*) malloc(n*sizeof(double));
	}
	
	//Inicialización
	for(i=0;i<n;i++){
		vector[i]=i;
		vSuma[i] =0;
		for(j=0;j<n;j++){
			matriz[i][j]=i+j;
		}
	}
	//Operaciones
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			vSuma[i] += matriz[i][j] * vector[j];
			//printf("Vector 1: %d  ", vector[j]);
			//printf("vSuma actual: %d \n", vSuma[i]);
		}
		//printf("vSuma[%d]=%d /\n",i,vSuma[i]);
	}
	cgt2 = omp_get_wtime();
	ncgt = cgt2 - cgt1 + ((cgt2-cgt1)/(1.e+9));

/* -- * /
for(i=0; i<n; i++){
	printf("vSuma[%d]=%f /\n",i,vSuma[i]);
}
/* -- */

printf("%f \n", ncgt);
/* -- */
}
