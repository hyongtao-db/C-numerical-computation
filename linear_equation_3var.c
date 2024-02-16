#include <stdio.h>
#define N 3 /* 三元一次方程式 */

void print_mat(double a[N][N+1])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N+1; j++)
        {
            printf("%2.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("======================\n");
}

int main(void) 
{
    int i, j, k;
    double d;
    
    double a[N][N+1] = {{3.0, 2.0, 1.0, 10.0},
                        {2.0, 5.0, 2.0, 18.0},
                        {1.0, 4.0, 1.0, 12.0}};
    
    // 这一组for循环，把左小角都变成0
    for (k = 0; k < N; k++)
    {
        printf("k = %d \n", k);
        for (i = k+1; i < N; i++) 
        {
            d = a[i][k] / a[k][k];
            for (j = k; j <= N; j++) 
                a[i][j] -= d*a[k][j];
        }
        print_mat(a);
    }

    // 输出消元后的结果
    // 3.00x + 2.00y + 1.00z = 10.00 -> a00 x + a01 y + a02 z = a03 -> a00 x + a01 y + a02 z = a03
    // 0.00x + 3.67y + 1.33z = 11.33 -> a10 x + a11 y + a12 z = a13 ->         a11 y + a12 z = a13
    // 0.00x + 0.00y - 0.55z = -1.64 -> a20 x + a21 y + a22 z = a23 ->                 a22 z = a23
    // a23 = [a23                    ] / a22  -> z = a23
    // a13 = [a13           - a12*a23] / a11  -> y = a13
    // a03 = [a03 - a01*a13 - a02*a23] / a00  -> x = a03

    // 更新 a[xxx][N] 的值为结果值
    for (i = N-1; i >= 0; i--) 
    {
        for (j = i+1; j < N; j++)
        {
            a[i][N] -= a[i][j]*a[j][N];
        }
        a[i][N] /= a[i][i]; 
    }

    for(i = 0; i < N; i++)
    {
        printf(" x%d = %10.5f\n", i+1, a[i][N]);
    }

    return 0;
}
