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
        x = a + (2.0*i + 1.0)/2.0*h;
        y = 4.0/(1.0+x*x);
        s = s+y*h;
    }

    printf("Area midpoint rule: %f\n",s);
    return 0;
}