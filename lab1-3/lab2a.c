#include <stdio.h>
#include <math.h>


int main()
{
    double x, h, a, b;
    // h = step, a = start of an interval, b = end of an interval

    printf("Enter the beginning of an interval: ");
    scanf("%lf", &a);
    printf("Enter the ending of an interval: ");
    scanf("%lf", &b);
    printf("Enter the step for an interval: ");
    scanf("%lf", &h);
    x = a; // set x to the beginning of an interval

    while (x >= a && x <= b)
    {
        if (x < 1)
        {
            printf("x = %.1lf | y = %.5lf\n", x, atan(1/x));
        }
        else if (1 <= x && x < 3)
        {
            printf("x = %.1lf | y = %.5lf\n", x, tan(x + log10(x)/log10(4)));
        }
        else if (x >= 3)
        {
            printf("x = %.1lf | y = %lf.5\n", x, 1 / (1 + log(x)));
        }
        else break;
        x += h;
    }
    return 0;
}