// gcc -O2 -fopenmp paralelo1.c -o paralelo1

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){
	int i=0,j=0,n=0, suma=0;
	double cgt1,cgt2,ncgt;
	
	if(argc < 2) {
		fprintf(stderr,"\nNumero de argumentos incorrecto.\n");
		exit(-1);
	}
	
	n = atoi(argv[1]);

	double **matriz = (double**)malloc(n*sizeof(double));

	for(i=0;i<n;i++)
		matriz[i] = (double*)malloc(n*sizeof(double));

	double *vector = (double*) malloc(n*sizeof(double));

	double resultado[n];

	#pragma omp parallel
	{	

	//inicializamos la matriz
	#pragma omp for
	for(i = 0;i < n;i++)
		for(j = 0;j < n;j++)
			matriz[i][j] = i+j;
		

	//inicializamos el vector
	#pragma omp for
	for(i = 0;i < n;i++)
		vector[i] = i;

	//inicializamos el vector resultados
	#pragma omp for
	for(i = 0;i < n;i++)
		resultado[i] = 0;

	}

	/*//muestra la matriz
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++)
			printf("%d ",matriz[i][j]);
		printf("\n");
	}*/
	#pragma omp parallel private(j)
	{
	
	cgt1 = omp_get_wtime();
	omp_set_num_threads(n);

	#pragma omp for
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			resultado[i] += (matriz[i][j] * vector[j]);
		}
	}
	
	cgt2 = omp_get_wtime();
	
	ncgt= cgt2-cgt1 + ((cgt2 - cgt1)/(1.e+9));

	}
	//muestra el resultado
	/* -- * /
	for(i = 0;i < n;i++)
		printf("\n Elemento %i %f ",i,resultado[i]);
	/* -- */
	
	printf("%f \n", ncgt);
}
