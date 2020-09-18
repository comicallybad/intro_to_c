#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}