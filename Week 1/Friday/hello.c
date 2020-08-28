//Try out opening this folder and then typing g++ test.c -o test.exe. Then type test.exe in the terminal to run the command

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int j;
    int k;

    //Print stuff

    printf("Hello world");
    printf("Notice that this happens first.\n");
    printf("and then this happens.\n");
    printf("and THEN.... another thing happens.\n");

    //Initialize variables
    i = 3;
    j = 5;
    k = i + j;

    //Do some math
    printf("After all that, i = %d and j = %d.\n", i, j);
    printf("And k =%d. We did MATH!\n", k);
    printf("\n");
    printf("Let's do MORE math! Multiply! %d Divide %d Subtract! %d\n", (i * j), (i / j), (i - j));

    return 0;
}