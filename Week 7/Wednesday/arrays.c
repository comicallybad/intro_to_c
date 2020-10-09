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

int main(void)
{
    int int_array[10]; //Integer array with 10 elements
    int slighty_larger_int_array[11];
    int much_larger_int_array[100];

    double double_array[10];

    int_array[3] = 5;

    printf("This should be 5: %d.\n", int_array[3]);
    printf("We have no idea what this will be: %d.\n", int_array[4]);

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        int_array[i] = (i + 1) * 10;
    }

    print_int_array(int_array, 10, "int_array");

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        double_array[i] = half_square(int_array[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("double_array[%d] is %f.\n", i, double_array[i]);
    }

    return 0;
}