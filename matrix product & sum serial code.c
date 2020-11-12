#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
long long n=100;
double start,end;
long long a[n][n],b[n][n],c[n][n],sume=0;
for(long long i=0;i<n;i++){
for(long long j=0;j<n;j++){
a[i][j]=rand();
}
}
for(long long i=0;i<n;i++){
b[i]=rand();
}
start=clock();
for(long long i=0;i<n;i++){
for(long long j=0;j<n;j++){
c[i]+=a[i][j]*b[j];
}
sume+=c[i];
}
end=clock();
printf("Time taken : %lf\n",(double)(end-start)/CLOCKS_PER_SEC);
}
