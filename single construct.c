#include<omp.h>
 #include<stdio.h> 
int main()
{
printf("SRUTI VERMA18BCE1005:\n"); 
#pragma omp parallel
{
printf("Thread num: %d\n",omp_get_thread_num()); 
#pragma omp single
printf("%d\n",omp_get_num_threads());
}
}

