#include<stdio.h>
#include<omp.h> 
int main()
{
int a[5],k=4,f=-1;
for(int i=0;i<5;i++)
 a[i]=i;
#pragma omp parallel for shared(f)
for(int i=0;i<5;i++)
 if(a[i]==k)
  f=i;
printf("%d",f);
}

