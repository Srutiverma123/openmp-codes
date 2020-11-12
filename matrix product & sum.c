#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
void main(){
long long n=100;
double start,end;
long long a[n][n],b[n],c[n],sume=0;
for(long long i=0;i<n;i++){
for(long long j=0;j<n;j++){
a[i][j]=rand();
}
}
for(long long i=0;i<n;i++){
b[i][j]=rand();
}
start=omp_get_wtime();
#pragma omp parallel for reduction(+:sume)
for(long long i=0;i<n;i++){
for(long long j=0;j<n;j++){
c[i]+=a[i][j]*b[j];
}
sume+=c[i];
}
end=omp_get_wtime();
printf("Time taken : %lf\n",end-start);
}
