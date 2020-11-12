#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<omp.h>
#define MAX_SIZE 1000
void merge(int * X, int n, int * tmp) {
 int i = 0;
 int j = n/2;
 int ti = 0;
 while (i<n/2 && j<n) {
 if (X[i] < X[j]) {
 tmp[ti] = X[i];
 ti++; i++;
 } else {
 tmp[ti] = X[j];
 ti++; j++;
 }
 }
 while (i<n/2) {
 tmp[ti] = X[i];
 ti++; i++;
 }
 while (j<n) {
 tmp[ti] = X[j];
 ti++; j++;
 }
 memcpy(X, tmp, n*sizeof(int));
}
void mergesort(int * X, int n, int * tmp)
{
 if (n < 2) return;
 #pragma omp task firstprivate (X, n, tmp)
 mergesort(X, n/2, tmp);
 #pragma omp task firstprivate (X, n, tmp)
 mergesort(X+(n/2), n-(n/2), tmp);
 #pragma omp taskwait
 merge(X, n, tmp);
}
void printArr(int * x, int n) {
 int i;
 for (i = 0; i < n; i++) {
 printf("%d ",x[i]);
 }
}
void main()
{
int n = 100,i,j,t;;
double start, stop;
int arr[MAX_SIZE], tmp[MAX_SIZE];
for (i = 0; i < n; i++)
arr[i] = i;
for (i = 0; i < n; i++) {
j = rand() % n;
t = arr[i];
arr[i] = arr[j];
arr[j] = t;
}
printf("Before Sorting : \n");
printArr(arr, n);
start = omp_get_wtime();
#pragma omp parallel num_threads(16)
{
#pragma omp single
mergesort(arr, n, tmp);
}
stop = omp_get_wtime();
printf("\nAfter Sorting :\n");
printArr(arr, n);
printf("\nTime: %g\n",stop-start);
}
