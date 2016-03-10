#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_THREADS 2

static long num_steps = 100000;
double step;
double omp_get_wtime(void);
double start;
double end;

void main()
{
	int i,nthreads; double pi=0.0;
	step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);
	start = omp_get_wtime();
	#pragma omp parallel
	{
	int i, id, nthrds;
	double x, sum;
	id = omp_get_thread_num();
	nthrds = omp_get_num_threads();
		for(i=id,sum=0.0;i<num_steps;i=i+nthrds)
		{
			x = (i+0.5)*step;
			sum+= 4.0/(1.0+x*x);
		}
		#pragma omp critical
		pi+=sum*step;
	}
		end = omp_get_wtime();
		printf("%f\n",pi);
		printf("Run in parallel will take %f second\n",end-start);
}
