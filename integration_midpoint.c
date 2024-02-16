#include<stdio.h>

int main(void)
{
    int i, n;
    float a = 0.0, b = 1.0;
    float x,y,h,s=0.0;
    printf("The number of divisions = ");
    scanf("%d", &n);
    h = (b-a)/n;
    // 中点法求积分
    for (i = 0; i< n; i++)
    {
        // (1) 根据步长h计算当前的中点
        x = a + (2.0*i + 1.0)/2.0*h;
        // (2) 根据中点x计算y y=f(x)
        y = 4.0/(1.0+x*x);
        // (3) 根据h,x,y计算长方形面积，并叠加
        s = s+y*h;
    }

    printf("Area midpoint rule: %f\n",s);
    return 0;
}