#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int i1 = 3;
    int i2 = 500;
    int i3 = 1048576;
    int i4 = INT_MAX;
    double d1 = 5.0;
    double pi = M_PI;
    double e = M_E;
    double hundred = 100.00;
    double dmax = DBL_MAX;
    char internal_string[] = "Example String";

    printf("Hello world! This is how you print an ordinary string.\n");

    printf("\n");

    printf("This is how you print an integer: %d\n", i1);
    printf("This is how you print a double: %lf\n", pi);
    printf("This is how you print a simpler double: %lf\n", d1);
    printf("This is how you print a string within a string: %s\n", internal_string);

    printf("\n");

    printf("Value of i1: %010d\n", i1);
    printf("Value of i2: %010d\n", i2);
    printf("Value of i3: %010d\n", i3);
    printf("Value of i4: %010d\n", i4);

    printf("\n");

    printf("Value of i1: %10d\n", i1);
    printf("Value of i2: %10d\n", i2);
    printf("Value of i3: %10d\n", i3);
    printf("Value of i4: %10d\n", i4);

    printf("\n");

    printf("Value of d1:   %lf\n", d1);
    printf("Value of pi:    %lf\n", pi);
    printf("Value of e:     %lf\n", e);
    printf("Value of max:%lf\n", dmax);

    printf("\n");

    printf("Value of five:           %6.4lf\n", d1);
    printf("Value of pi:             %6.4lf\n", pi);
    printf("Value of one hundred:  %6.4lf\n", hundred);
    printf("Value of e:              %6.4lf\n", e);

    printf("pi: %.2f\n", pi);
    printf("pi: %.5f\n", pi);
    printf("pi: %.10f\n", pi);
    printf("pi: %.20f\n", pi);
    printf("pi: %.30f\n", pi);
    printf("pi: %.40f\n", pi);

    printf("\n");

    printf("DBL_MAX: %10E\n", dmax);

    return 0;
}