#include<omp.h>
#include<stdio.h>
int main()
{
    int arr[5]={4,5,3,2,1};
    int array[5]={1,2,3,4,5};
    int i;
    int result;
    printf("sruti verma 18bce1005 result: ");
    #pragma omp parallel sections
    {
    #pragma omp section
    #pragma omp parallel for
    for(int i=0;i<5;i++)
    {
        result = arr[i]+array[i];
        printf("Value post addition%d\n",result);
    }
    #pragma omp section
    #pragma omp parallel for
    for(int i=0;i<5;i++)
    {
        result = arr[i]*array[i];
        printf("Value post multiplication %d\n",result);
    }}
}
