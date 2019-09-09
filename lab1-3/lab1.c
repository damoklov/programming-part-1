#include <stdio.h>
#include <math.h>


int main()
{
    double x, y, result;

    printf("Enter first number, please: ");
    scanf("%lf", &x);
    printf("Enter second number, please: ");
    scanf("%lf", &y);

    result = sqrt((x*pow(y, 2)) + (y*sin(x)) + (142*pow(x, 2)*y)) + tan(x*y) - (142*(y-x))/16.32;
    printf("Result is: %.20lf\n", result);

    return 0;
}