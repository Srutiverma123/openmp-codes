
#include <stdio.h>
#include <omp.h>

#define N 3

int A[N][N];
int B[N][N];

int main() 
{
    int i,j,k;
    for (i= 0; i< N; i++)
        for (j= 0; j< N; j++)
	{
            A[i][j] = i;
	}
    
    #pragma omp parallel for private(i,j) shared(A,B)
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
                B[j][i] = A[i][j];
        }
    }


    
   for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
        {
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
}
