#include<time.h> 
#include<stdio.h>
#include<omp.h> 
int main()
{
long int fact=1;
printf("18bce1005 sruti verma:\n"); 
clock_t t0 = clock();
#pragma omp parallel for reduction(*:fact) 
for(int i=0;i<10;i++)
fact = fact*(i+1); t0 = clock()-t0;
double ft = ((double)t0)/CLOCKS_PER_SEC; printf("%ld\t%lf\n",fact,ft);
}

