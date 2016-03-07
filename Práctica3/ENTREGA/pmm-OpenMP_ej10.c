// gcc -O2 -fopenmp pmm-OpenMP_ej10.c -o pmm-OpenMP_ej10 -lrt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char **argv){
	int n, ambito, chunk, nhebras;
	int i,j;
	omp_sched_t kind;
	struct timespec cgt1,cgt2; double ncgt;
		
	if(argc <5){
		fprintf(stderr, "Parámetros: 1º-> tamaño\n             2º-> runtime(1:static 2:dynamic 3:guided 4:default)\n             3º-> chunk             4º->n hebras\n");
		exit(-1);
	}
	n = atoi(argv[1]);
	ambito = atoi(argv[2]);
	chunk = atoi(argv[3]);
	nhebras = atoi(argv[4]);
	
	if(ambito==4){
		//Automático (por defecto). No tomaremos este caso en este ejercicio.
		kind=4;
	}else if(ambito==1){
		//Estático
		kind=1;
	}else if(ambito==2){
		//Dinámico
		kind=2;
	}else if(ambito==3){
		//Guiado
		kind=3;
	}else{
		fprintf(stderr, "1:static 2:dynamic 3:guided 4:default\n");
		exit(-1);
	}
	double **matrizA;
	double **matrizB;
	double **matrizC;

	clock_gettime(CLOCK_REALTIME,&cgt1);
	//Creación de matrices
	matrizA = (double**) malloc(n*sizeof(double*));
	matrizB = (double**) malloc(n*sizeof(double*));
	matrizC = (double**) malloc(n*sizeof(double*));
	omp_set_num_threads(nhebras);
	#pragma omp parallel
	{
	#pragma omp for schedule(runtime)
	for(i=0; i<n;i++){matrizA[i]=(double*) malloc(n*sizeof(double));}
	#pragma omp for schedule(runtime)
	for(i=0; i<n;i++){matrizB[i]=(double*) malloc(n*sizeof(double));}
	#pragma omp for schedule(runtime)
	for(i=0; i<n;i++){matrizC[i]=(double*) malloc(n*sizeof(double));}
	}
	
	//Inicialización
	#pragma omp for schedule(runtime)
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
	#pragma omp parallel private(j)
	{
	#pragma omp for schedule(runtime)
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				matrizA[i][j] = matrizB[i][j] * matrizC[j][i];
		}
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
	printf("Ejecución con %d hebras\n", nhebras);
	printf("matrizA[0][0]=%f /\nmatrizA[%d][%d]=%f  /\n",matrizA[0][0],n-1,n-1,matrizA[n-1][n-1]);

/* -- */

	free(matrizA);
	free(matrizB);
	free(matrizC);
}
