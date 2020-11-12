#include <stdio.h>
#include <omp.h>
#include <math.h>
int main()
{
    double a[10],maximum=0.0,avg,minimum=10000.0;
int i,sum=0;
printf("SRUTI VERMA 18BCE1005:\n");
    for( i=0; i<10; i++)
        scanf("%lf",&a[i]);
    #pragma omp parallel for reduction(+:sum)
    for(i=0;i<10;i++){
    sum=sum+a[i];
	}
    avg=sum/10;
printf("THE CLASS AVERAGE IS = %f\n",avg);

    #pragma omp parallel for reduction(max : maximum)
    for( i=0;i<10; i++)
    {
        printf("thread id = %d and i = %d\n", omp_get_thread_num(), i);
        if(a[i] > maximum)
        {
            maximum = a[i];  
        }
    }
  
    printf("\nTHE MAXIMUM MARKS IS = %f\n", maximum);
    minimum = maximum;
    #pragma omp parallel for reduction(min : minimum)
    for( i=0;i<10; i++)
    {
        printf("thread id = %d and i = %d\n", omp_get_thread_num(), i);
        if(a[i] < minimum)
        {
            minimum = a[i];  
        }
    }
  
    printf("\nTHE MINIMUM MARKS IS = %f\n", minimum);
    double d=0;
    #pragma omp parallel for reduction(+ : d)
    for( i=0;i<10; i++)
    {
		d = d + ((a[i]-avg)*(a[i]-avg));
    }
	double stadev = sqrt(d/10);
	printf("THE STANDARD DEVIATION OF MARKS IS =  %f\n",stadev);
   
    	return 0; 
}


