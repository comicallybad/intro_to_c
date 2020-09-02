//Try out opening this folder and then typing g++ test.c -o test.exe. Then type test.exe in the terminal to run the command

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    int j;
    int k;

    //If statement stuff
    if (i == 3)
        printf("i is equal to 3.\n");
    else
        printf("i is not equal to 3.\n");

    if (i == 4)
        printf("i is equal to 4.\n");
    else
        printf("i is not equal to 4.\n");

    if (i < 2)
        printf("i is less than 2.\n");
    else if (i > 2)
        printf("i is greater than 2.\n");
    else
        printf("i is equal to 2.\n");

    printf("\n");

    float x;
    float y;
    float z;

    //Print stuff

    printf("Hello world");
    printf("Notice that this happens first.\n");
    printf("and then this happens.\n");
    printf("and THEN.... another thing happens.\n");

    //Initialize variables
    i = 3;
    j = 5;

    //Let's look at the four basic arithmetic operations.

    k = i + j; //Addition
    printf("The sum of %d and %d is %d.\n", i, j, k);

    k = i - j; //Subtraction
    printf("The difference of %d and %d is %d.\n", i, j, k);

    k = i * j; //Multiplication
    printf("The product of %d and %d is %d.\n", i, j, k);

    k = i / j; //Multiplication
    printf("The quotient of %d and %d is %d.\n", i, j, k);

    k = i % j; //Multiplication
    printf("The remainder of %d and %d is %d.\n", i, j, k);

    ///Initialize our float variables

    x = 3.0;
    y = 5.0;

    //Now let's do some math

    z = x + y; //Addition
    printf("The sum of %f and %f is %f.\n", x, y, z);

    z = x - y; //Subtraction
    printf("The difference of %f and %f is %f.\n", x, y, z);

    z = x * y; //Multiplication
    printf("The product of %f and %f is %f.\n", x, y, z);

    z = x / y; //Division
    printf("The quotient of %f and %f is %f.\n", z, y, z);

    return 0;
}