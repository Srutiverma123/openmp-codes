#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
void main(){
long long n=10000;
double start,end;
long long a[n],b[n],c[n],sume=0;
for(long long i=0;i<n;i++){
a[i]=rand();
}
for(long long i=0;i<n;i++){
b[i]=rand();
}
start=omp_get_wtime();
#pragma omp parallel for reduction(+:sume)
for(long long i=0;i<n;i++){
c[i]=a[i]*b[i];
sume+=c[i];
}
end=omp_get_wtime();
printf("Time taken : %lf\n",end-start);
}
 

