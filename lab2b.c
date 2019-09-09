#include <stdio.h>
#include <math.h>


double compute(double, int);

int main()
{
    double x, h, a, b, d, sum = 0;
    int n = 1;
    // h = step, a = start of an interval, b = end of an interval, d = deviation

    printf("Enter the beginning of an interval: ");
    scanf("%lf", &a);
    printf("Enter the ending of an interval: ");
    scanf("%lf", &b);
    printf("Enter the step for an interval: ");
    scanf("%lf", &h);
    printf("Enter value of deviation: ");
    scanf("%lf", &d);
    x = a; // set x to the beginning of an interval
    double current = compute(x, n);

    while (a <= x && x <= b && fabs(current - compute(x, n)) < d)
    {
        // first, we check the borders, and then the value of deviation
        sum -= current;
        printf("Sum = %lf\nn = %d\n", sum, n);
        n++;
        x += h;
        current = compute(x, n); // compute next step of the row
    }
    printf("The resulting sum is: %.10lf\n", sum);

    return 0;
}


double compute(double x, int n)
{
    double result = pow(x, n)/n;
    return result;
}