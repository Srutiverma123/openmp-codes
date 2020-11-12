
#include <omp.h>
#include <stdio.h>
int main ()
{
int i,sum=0;
int a[10], o[10], e[10],j=0,k=0;
printf("SRUTI VERMA 18BCE1005:\n");
for (i=0; i < 10; i++)
{
 a[i] = i+1;
}

#pragma omp parallel shared(a,e,o,k,j) private(i)
{
#pragma omp sections nowait
{
 #pragma omp section
for (i=0; i < 10; i++)
{ 
if(a[i]%2==0)
  e[k++] = a[i] ;
}

#pragma omp section
for (i=0; i < 10; i++) {
{ 
if(a[i]%2==1)
  o[j++] = a[i] ;}
}
}  
}
#pragma omp parallel for reduction(+:sum)
for(i=0;i<j;i++){
sum=sum+o[i];
}
printf("sum of odd numbers is = %d\n",sum);

sum=0;
#pragma omp parallel for reduction(+:sum)
for(i=0;i<k;i++){
sum=sum+e[i];
}
printf("sum of even numbers is = %d\n",sum);

return 0;
}
