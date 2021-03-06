// gcc -O2 -fopenmp paralelo2.c -o paralelo2 -lrt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char **argv){
	int n;
	int i,j;
	double aux=0.0;
	struct timespec cgt1,cgt2; double ncgt;
		
	if(argc <2){
		fprintf(stderr, "Falta el tamaño de la matriz cuadrada\n");
		exit(-1);
	}
	n = atoi(argv[1]);

	double **matriz;
	double *vector;
	double *vSuma;

	clock_gettime(CLOCK_REALTIME,&cgt1);
	//Creación de vectores
	vector = (double*) malloc(n*sizeof(double));
	vSuma  = (double*) malloc(n*sizeof(double));
	//Creación de matriz
	matriz = (double**) malloc(n*sizeof(double*));
	
	#pragma omp parallel
	{
	#pragma omp for
	for(i=0; i<n;i++){matriz[i]=(double*) malloc(n*sizeof(double));}
	
	//Inicialización
	#pragma omp for
	for(i=0;i<n;i++){
		vector[i]=i;
		vSuma[i] =0;
		for(j=0;j<n;j++){
			matriz[i][j]=i+j;
		}
	}
	}
	//Operaciones
	omp_set_num_threads(n);
	#pragma omp parallel private(i)
	{
	for(i=0;i<n;i++){
		#pragma omp for
		for(j=0;j<n;j++){
			vSuma[i] += matriz[i][j] * vector[j];
			//printf("vSuma[%d]=%f \n", i, vSuma[i]);
			//printf("thread %d: aux==%f matriz[%d][%d]=%f * vector[%d]=%f", omp_get_thread_num(), aux, i, j, matriz[i][j], j, vector[j]);
		}
		//printf("--> vSuma definitivo[%d]=%f \n\n",i,vSuma[i]);
	}
	}
	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=	(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)
		/(1.e+9));

/* -- */
printf("%f \n", ncgt);
/* -- * /

for(i=0; i<n; i++){
	printf("vSuma[%d]=%f /\n",i,vSuma[i]);
}

/* -- */

	free(vector);
	free(vSuma);
	free(matriz);
}
