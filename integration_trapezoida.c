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
    for (i = 1; i<=n; i++)
    {
        x1 = a + i*h;
        x2 = x1 + h;
        f1 = 4.0/(1.0+x1*x1);
        f2 = 4.0/(1.0+x2*x2);
        s = s+(f1+f2)*h/2.0;
    }

    printf("Trapezoidal rule: %f\n",s);
    return 0;
}