// gcc -O2 -fopenmp pmtv-OpenMP.c -o pmtv-OpenMP -lrt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char **argv){
	int n, ambito, chunk;
	int i,j;
	omp_sched_t kind;
	struct timespec cgt1,cgt2; double ncgt;
		
	if(argc <4){
		fprintf(stderr, "Parámetros: 1º-> tamaño\n             2º-> runtime(1:static 2:dynamic 3:guided 4:default)\n             3º-> chunk\n");
		exit(-1);
	}
	n = atoi(argv[1]);
	ambito = atoi(argv[2]);
	chunk = atoi(argv[3]);
	
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
	double **matriz;
	double *vector;
	double *vFinal;

	clock_gettime(CLOCK_REALTIME,&cgt1);
	//Creación de vectores
	vector = (double*) malloc(n*sizeof(double));
	vFinal  = (double*) malloc(n*sizeof(double));
	//Creación de matriz
	matriz = (double**) malloc(n*sizeof(double*));

	omp_set_num_threads(omp_get_num_procs());
	omp_set_schedule(kind,chunk);
	#pragma omp parallel
	{
	#pragma omp for schedule(runtime)
	for(i=0; i<n;i++){matriz[i]=(double*) malloc(n*sizeof(double));}
	
	//Inicialización
	#pragma omp for schedule(runtime)
	for(i=0;i<n;i++){
		vector[i]=i;
		vFinal[i] =0;
		for(j=0;j<n;j++){
			if(i>=j){
				matriz[i][j]=i+j;
			}else{
				matriz[i][j]=0;
			}
		}
	}
	}
	/* -- * /
	//Mostrar la matriz
	for(i=0; i < n; i++){
		for(j=0; j < n; j++){
			printf("%f ", matriz[i][j]);
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
			if(i >= j){
				vFinal[i] += matriz[i][j] * vector[j];
				//printf(" thread %d opera matriz[%d][%d]=%f y vector[%d]=%f \n", omp_get_thread_num(),i,j,matriz[i][j],j,vector[j]);
			}
		}
	}
	}

	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=	(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)
		/(1.e+9));

/* -- */
printf("%f \n", ncgt);
/* -- */
	printf("vFinal[0]=%f /\n vFinal[%d]=%f  /\n",vFinal[0],n-1,vFinal[n-1]);
/* -- * /
for(i=0; i<n; i++){
	printf("vFinal[%d]=%f /\n",i,vFinal[i]);
}

/* -- */

	free(vector);
	free(vFinal);
	free(matriz);
}
