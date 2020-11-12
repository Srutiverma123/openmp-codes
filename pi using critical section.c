#include<stdio.h> 
#include<>omp.h>
static long long numsteps = 1000; int main(){
int i=0,j,k,l;
double temp,x,pi,sume=0.0,start,end; double step = 1.0/(double)numsteps; #pragma omp parallel num_threads(5)
{
start = omp_get_wtime(); #pragma omp for schedule(static) for(i=0;i<numsteps;i+=1){
#pragma omp critical
{
x = (i+0.5) * step; sume += 4.0/(1 + x*x);
}
}
end = omp_get_wtime();
}
pi = step * sume;
printf("%lf\nThe time taken to complete : %lf\n",pi,end-start); return 0;
}
