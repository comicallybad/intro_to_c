#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double half_square(int i)
{
    double x = i;

    x *= x;
    x /= 2;

    return x;
}

void print_int_array(int *int_array, int n, char *name)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s[%d] is %d.\n", name, i, int_array[i]);
    }
}

void initialize_linear_int_array(int *int_array, int n, int slope, int intercept)
{
    for (int i = 0; i < n; i++)
    {
        int_array[i] = i * slope + intercept;
    }
}

void print_double_array(double *double_array, int n, char *name)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s[%d] is %f.\n", name, i, double_array[i]);
    }
}

void initialize_halfsquare_double_array(double *double_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        double_array[i] = half_square(i);
    }
}

int main(void)
{
    int int_array[10]; //Integer array with 10 elements
    int slighty_larger_int_array[11];
    int much_larger_int_array[100];
    int genuinely_large_int_array[1000];

    double double_array[10];

    int_array[3] = 5;

    printf("This should be 5: %d.\n", int_array[3]);
    printf("We have no idea what this will be: %d.\n", int_array[4]);

    printf("\n");

    initialize_linear_int_array(int_array, 10, 10, 1);
    print_int_array(int_array, 10, "int_array");
    printf("\n");

    initialize_linear_int_array(much_larger_int_array, 100, 10, 1);
    print_int_array(much_larger_int_array, 100, "much_larger_int_array");
    printf("\n");

    initialize_linear_int_array(genuinely_large_int_array, 1000, 25, 3);
    print_int_array(genuinely_large_int_array, 1000, "genuinely_large_int_array");
    printf("\n");

    initialize_halfsquare_double_array(double_array, 10);
    print_double_array(double_array, 10, "double_array");

    return 0;
}