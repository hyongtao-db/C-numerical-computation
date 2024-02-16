#include<stdio.h>

int main(void)
{
    int i, n;
    float a = 0.0, b = 1.0;
    float x1, x2, y, h, s=0.0, f1 =0.0, f2 = 0.0;
    printf("The number of divisions = ");
    scanf("%d", &n);
    h = (b-a)/n;
    // 梯形法求积分
    for (i = 0; i<n; i++)
    {
        // (1) 根据步长h计算当前的x1和x2
        x1 = a + i*h;
        x2 = x1 + h;
        // (2) 根据x1和x2计算f1和f2 y=f(x)
        f1 = 4.0/(1.0+x1*x1);
        f2 = 4.0/(1.0+x2*x2);
        // (3) 根据h,x1和x2,f1和f2计算梯形面积，并叠加
        s = s+(f1+f2)*h/2.0;
    }

    printf("Trapezoidal rule: %f\n",s);
    return 0;
}