#include <stdio.h>
#include <stdlib.h>

//Using while loop to loop to above 1 million
int loop_to_above_one_million(double val, double factor)
{
    double x = val;
    int mults = 0;

    printf("Muliplying %lf by %lf.\n", val, factor);

    do
    {
        mults++;
        x *= factor;
        printf("Multiplication #%d. x= %lf.\n", mults, x);
    } while (x <= 1000000.0);

    return mults;
}

//Using while loop to loop to below one
int loop_to_below_one(double val, double divisor)
{
    double x = val;
    int divisions = 0;

    printf("Dividing %lf by %lf.\n", val, divisor);

    while (x >= 1.0)
    {
        divisions++;
        x /= divisor;
        printf("Division #%d. x = %lf.\n", divisions, x);
    }
    return divisions;
}

//Use while loop to print n times with steps
void loop_n_steps(int n, int step)
{
    int i = 1;
    while (i <= n)
    {
        printf("Printing %d times with a step of %d step: %d.\n", n, step, i);
        i += step;
    }
}

//Use while to print n timers
void loop_n_times(int n)
{
    int i = 1;
    while (i <= n)
    {
        printf("This is print #%d out of %d.\n", i, n);
        i++;
    }
}

//Use while loop to print 10 times
void loop_10_times(void)
{
    int i = 1;
    while (i <= 10)
    {
        printf("This print #%d.\n", i);
        i++;
    }
}

int main(void)
{
    loop_10_times();
    loop_n_times(5);
    loop_n_steps(10, 3);

    int how_many_times = loop_to_below_one(50.0, 2.0);
    printf("Divided %d times.\n", how_many_times);
    how_many_times = loop_to_above_one_million(10, 40);
    printf("Multipled %d times.", how_many_times);

    return 0;
}