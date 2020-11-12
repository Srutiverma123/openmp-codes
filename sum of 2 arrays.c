#include<omp.h>
#include<stdio.h>
void main()
{
int a[10],b[10],sum[10];
int i;
printf("SRUTI VERMA 18BCE1005:\n");
for(i=0;i<10;i++)
{
b[i] = a[i] = i+1;
}
#pragma omp parallel for
for(i=0;i<10;i++)
{
sum[i] = a[i] + b[i];
printf("CPU:%d\tThread:%d\tValue:%d\n",sched_getcpu(),omp_get_thread_num(),sum[i]);
}
}

