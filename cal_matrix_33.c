#include<stdio.h>
  
int main()
{
	// 3*3矩阵乘法
	double arr1[3][3] = { {1,1,1}, {2,2,2}, {3,3,3} };
	double arr2[3][3] = { {10,10,10}, {15,15,15}, {20,20,20} };
	double arr3[3][3] = {0};

    int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arr3[i][j] = arr1[i][0]*arr2[0][j] + arr1[i][1]*arr2[1][j] + arr1[i][2]*arr2[2][j];
		}
	}

    for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
            printf("%2.3f\t", arr3[i][j]);
		}
        printf("\n");
	}
	return 0;
}