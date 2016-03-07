#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

main(int argc, char **argv) {
	int i, n = 7, auxchunk,chunk, a[n],suma=0; //auxchunk sirve para capturar el valor del chunk cuando hacemos omp_get_thread_limit() (modifica los atributos por referencia). No queremos que nos modifique nuestro chunk
	int nhebras;
	omp_sched_t kind;
	if(argc < 3) {
		fprintf(stderr,"\nFalta chunk, hebras \n");
	exit(-1);
	}
	chunk = atoi(argv[1]);
	nhebras = atoi(argv[2]);

	for (i=0; i<n; i++) a[i] = i;

	printf("\n------------------------------------------------\n");
	printf("Antes de la región paralela: ");
	printf("\n    dyn-var: %d", omp_get_dynamic());
	printf("\n    nthreads-var: %d", omp_get_max_threads());
	printf("\n    thread-limit-var: %d", omp_get_thread_limit());
	omp_get_schedule(&kind,&auxchunk);
	printf("\n    kind: %d", kind);
	printf("\n    auxchunk: %d", auxchunk);
	printf("\n------------------------------------------------\n");
	
	omp_set_num_threads(nhebras);
	#pragma omp parallel for firstprivate(suma) lastprivate(suma) schedule(runtime)
	for (i=0; i<n; i++)
	{ suma = suma + a[i];
	  if(i==n-1){
		printf("\n------------------------------------------------\n");
		printf("Durante la región paralela: ");
		printf("\n    dyn-var: %d", omp_get_dynamic());			printf("\n    nthreads-var: %d", omp_get_max_threads());
		printf("\n    thread-limit-var: %d", omp_get_thread_limit());
		omp_get_schedule(&kind,&auxchunk);
		printf("\n    kind: %d", kind);
		printf("\n    auxchunk: %d", auxchunk);
		printf("\n------------------------------------------------\n");
	  }
	}
	printf("\n------------------------------------------------\n");
	printf("Después de la región paralela: ");
	printf("\n    dyn-var: %d", omp_get_dynamic());
	printf("\n    nthreads-var: %d", omp_get_max_threads());
	printf("\n    thread-limit-var: %d", omp_get_thread_limit());
	omp_get_schedule(&kind,&auxchunk);
	printf("\n    kind: %d", kind);
	printf("\n    auxchunk: %d", auxchunk);
	printf("\n------------------------------------------------\n");
}
