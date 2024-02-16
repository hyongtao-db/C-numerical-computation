#include<stdio.h>

#define N 2

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

int main()
{
	// 高斯消元法 Gaussian elimination method=
	// 二元一次方程 linear equation of two variables
	// 3x + 4y = 11
	// 5x + 6y = 17
    int i, j, k;
    double d;

	double a[N][N+1] = { {3.0, 4.0, 11.0}, 
					   {5.0, 6.0, 17.0} };
    
    // 这一组for循环，把左小角都变成0
    for (k = 0; k < N; k++) // k = 0, 1，第k列
    {
        printf("k = %d \n", k);
        for (i = k+1; i < N; i++) // k = 0: i =1; k =1: none 第i行
        {
            d = a[i][k] / a[k][k]; // 求放大倍数
            for (j = k; j <= N; j++)  // 第j列
                a[i][j] -= d*a[k][j];
        }
         print_mat(a);
    }

    // 输出消元后的结果
    // 3x + 4.00y = 11
    // 0x - 0.67y = -1.33

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