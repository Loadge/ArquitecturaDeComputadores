// gcc -O2 secuencial.c -o secuencial -lrt

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

	double **matriz;
	double *vector;
	double *vSuma;

	clock_gettime(CLOCK_REALTIME,&cgt1);
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
	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=	(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)
		/(1.e+9));

/* -- * /
printf("%f \n", ncgt);
/* -- */

for(i=0; i<n; i++){
	printf("vSuma[%d]=%f /\n",i,vSuma[i]);
}

/* -- */

	free(vector);
	free(vSuma);
	free(matriz);
}
