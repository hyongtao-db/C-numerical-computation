#include <stdio.h>
#include <math.h>
 
int main()
{	
    // 一元二次方程 ax^2+bx+c=0
    double a = 1.0, b = 2.0, c = 1.0, x, x1, x2;

    x = b * b - 4 * a * c; 
    if (x > 0.0) 
    {
        x1 = (-b + sqrt(x)) / (2 * a);
        x2 = (-b - sqrt(x)) / (2 * a);
        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
    } 
    else if (x == 0) 
    {
        x1 = (-b) / (2 * a);
        x2 = x1;
        printf("x = %.2f\n", x1);
    } 
    else 
    {
        printf("no solution\n");
    }
    return 0;
	
}
