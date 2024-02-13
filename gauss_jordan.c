#include <stdio.h>
#define  N 3
/* 联立N元一次方程式 */

int main(void) 
{
    int i, j, k;
    double a[N][N+1] = {{3.0, 2.0, 1.0, 10.0},
                        {2.0, 5.0, 2.0, 18.0},
                        {1.0, 4.0, 1.0, 12.0}};
    double pivot, d;

    for (k=0; k<N; k++) 
    {
        pivot = a[k][k];
        for(j=k; j<N+1; j++) 
            a[k][j] /= pivot;

        for (i=0; i<N; i++)
        {
            if (i != k) {
                d = a[i][k];
                for (j=k; j<N+1; j++)
                    a[i][j] -= d*a[k][j];
            }
        }

        for(i=0; i<N; i++) 
            printf(" x%d = %10.5f \n", i+1, a[i][N]);
    }

    printf("\n");
    return 0;
}