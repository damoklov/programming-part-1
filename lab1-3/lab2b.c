#include <stdio.h>
#include <math.h>


double compute(double, int);

int main()
{
    double x, h, a, b, d, current, sum = 0.0;
    int n = 1;
    /* h = step, a = start of an interval, b = end of an interval, d = deviation, x = user's value */

    printf("Enter the beginning of an interval: ");
    scanf("%lf", &a);
    printf("Enter the ending of an interval: ");
    scanf("%lf", &b);
    printf("Enter the step for an interval: ");
    scanf("%lf", &h);
    printf("Enter value of deviation: ");
    scanf("%lf", &d);
    x = a; // set x to the beginning of an interval

    while (a <= x && x <= b)
    {
        // first, we check the borders, and then the value of deviation
        do{
            current = compute(x, n); // compute next step of the row
            sum -= current;
            n++;
        } while(fabs(current) > d);

        printf("x = %.2lf | y = %.5lf\n", x, sum);
        sum = 0.0; // set new value for sum
        x += h;
        n = 1; // set n to the beginning again
    }
    return 0;
}


double compute(double x, int n)
{
    double result = pow(x, n)/n;
    return result;
}
