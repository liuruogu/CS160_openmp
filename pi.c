#include"omp.h"
#include<stdio.h>
#include<stdlib.h>

static long num_steps = 100000;
double step;
double omp_get_wtime(void);
double start;
double end;

void main()
{
	int i; double x, pi, sum = 0.0;
	step = 1.0/(double)num_steps;
	start = omp_get_wtime();
	for(i=0;i<num_steps;i++)
	{
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}
	pi = step*sum;
	end = omp_get_wtime();
	printf("%f\n",pi);
	printf("Run sequencially will take %f second\n",end-start);
}
