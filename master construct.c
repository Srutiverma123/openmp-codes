#include<stdio.h> 
int main()
{
printf("18BCE1005 SRUTI VERMA:\n"); 
#pragma omp parallel
{
printf("Thread num: %d\n",omp_get_thread_num()); 
#pragma omp master
printf("%d\n",omp_get_num_threads());
}
}

