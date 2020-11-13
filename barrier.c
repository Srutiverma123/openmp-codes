
#include<stdio.h>
#include<omp.h> 
int main()
{
int y=0;
#pragma omp parallel shared(y)
{
for(int i=0;i<10;i++) y+=i;
#pragma omp barrier
printf("%d\n",y);
}
}
