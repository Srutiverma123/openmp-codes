#include<stdio.h>
#include<omp.h>
int main(){
long long n;
scanf("%lld",&n);
long long counter = 0;
double end,start;
#pragma omp parallel num_threads(32) reduction(+:counter)
{
start = omp_get_wtime();
#pragma omp for schedule(dynamic,16)
for(long long i=2;i<=n;i++){
long long j;
for(j=2;j<=i/2;j++){
if(i%j==0){
break;
}
}
if(j>i/2){
counter++;
}
}
end = omp_get_wtime();
}
printf("%lld\n",counter);
printf("Time Taken %lf",end-start);
}
