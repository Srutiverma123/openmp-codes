#include<stdio.h>
#include<omp.h> 
int main()
{
int a[4],b[4],k=4;
#pragma omp parallel{
#pragma omp for nowait
 for(int i=0;i<5;i++)
 a[i]=i;
}

#pragma omp parallel for 
for(int i=0;i<4;i++)
 b[i]=a[i]+i;
for(int i=0;i<5;i++)
 printf("%d",b[i]);
}
