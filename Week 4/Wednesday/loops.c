#include <stdio.h>
#include <stdlib.h>

//Loop 10 times
void loop_ten_times(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("I'd like to print this ten times.\n");
    }
}

//Loop n times
void loop_n_times(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("I'm going to print this %d times, this is the %d time.\n", n, i);
    }
}

//Stepped loop n times and return how many runs it had;
int loop_to_n(int n, int step)
{
    int runs = 0;
    for (int i = 1; i <= n; i += step)
    {
        printf("I'm going to print this until I get to %d, I'm at %d.\n", n, i);
        runs++;
    }
    return runs;
}

int main(void)
{
    printf("This is about loops.\n");

    //For loop, loop i 10 times.
    loop_ten_times();
    loop_n_times(7);
    int runs = loop_to_n(10, 3);

    printf("The loop ran %d times.\n", runs);

    return 0;
}