#include <stdio.h>

void fill_int_array(int *array_to_fill, int n, int mult)
{
    for (int i = 0; i < n; i++)
    {
        array_to_fill[i] = i * mult;
    }
}

void print_int_array(int *array_to_print, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Value %d: %d\n", i, array_to_print[i]);
    }
}

int main(void)
{
    int my_array[100];
    int *array_ptr = my_array;
    int i;
    int my_n = 100;
    int my_mult = 10;

    fill_int_array(array_ptr, my_n, my_mult);
    print_int_array(array_ptr, my_n);

    return 0;
}