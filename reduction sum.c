#include<omp.h>
#include<stdio.h>
int main(){
printf("sruti verma 18bce1005 result: ");
int a[5],b[5];
int sum=0;int i;
for(int j=0;j<5;j++){
scanf("%d",&a[j]);
scanf("%d",&b[j]);

}
#pragma omp parallel for reduction(+:sum)
for(i=0;i<5;i++){
sum=sum+a[i]+b[i];

printf("CPU:%d\t Thread:%d\t Value:%d\n",sched_getcpu(), omp_get_thread_num(), sum);
}
printf("sum= %d\n",sum);
return 0;
}
