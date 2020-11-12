#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int p,i,j,flag=1;
scanf("%d",&p);
printf("SRUTI VERMA 18BCE1005:\n");
#pragma omp parallel for firstprivate(flag)
for(i=2;i<=p;i++)
{
f=1;
for(j=2;j<=i/2;j++)
if(i%j==0)
	flag=0;
if(flag)
	printf("Thread no: %d\t%d is a prime number\n",omp_get_thread_num(),i);
}
}


