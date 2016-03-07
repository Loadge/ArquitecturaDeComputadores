#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


//echo 'practica2/ejer8 2 2' | qsub -q ac
int main(int argc, char **argv) {
	
	int i=0,j=0,filas=0, columnas=0, suma=0;
	double cgt1,cgt2,ncgt;  //timers
	
	if(argc < 3) {
		fprintf(stderr,"\nNumero de argumentos incorrecto.\n");
		exit(-1);
	}
	
	filas = atoi(argv[1]);
	columnas = atoi(argv[2]);

	double **matriz = (double**)malloc(filas*sizeof(double));

	for(i=0;i<columnas;i++)
		matriz[i] = (double*)malloc(columnas*sizeof(double));

	double *vector = (double*) malloc(columnas*sizeof(double));

	double resultado[columnas];

	#pragma omp parallel
	{	

	//inicializamos la matriz
	#pragma omp for
	for(i = 0;i < filas;i++)
		for(j = 0;j < columnas;j++)
			matriz[i][j] = i+j;
		

	//inicializamos el vector
	#pragma omp for
	for(i = 0;i < columnas;i++)
		vector[i] = i;

	//inicializamos el vector resultados
	#pragma omp for
	for(i = 0;i < columnas;i++)
		resultado[i] = 0;

	}

	/*//muestra la matriz
	for(i = 0;i < filas;i++){
		for(j = 0;j < columnas;j++)
			printf("%d ",matriz[i][j]);
		printf("\n");
	}*/
	#pragma omp parallel private(j)
	{
	
	cgt1 = omp_get_wtime();

	#pragma omp for
	for(i = 0;i < filas;i++){
		for(j = 0;j < columnas;j++){
			resultado[i] += (matriz[i][j] * vector[j]);
		}
	}
	
	cgt2 = omp_get_wtime();
	
	ncgt= cgt2-cgt1 + ((cgt2 - cgt1)/(1.e+9));

	}
	//muestra el resultado
	for(i = 0;i < columnas;i++)
		printf("\n Elemento %i %f ",i,resultado[i]);
	
	
	printf("\nTiempo(seg.):%11.9f\t\n", ncgt);
}
