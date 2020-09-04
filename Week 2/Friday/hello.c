//Try out opening this folder and then typing g++ test.c -o test.exe. Then type test.exe in the terminal to run the command

#include <stdio.h>
#include <stdlib.h>

void printStuff(void)
{
    //Print stuff
    printf("\n");
    printf("Hello world");
    printf("Notice that this happens first.\n");
    printf("and then this happens.\n");
    printf("and THEN.... another thing happens.\n");
    printf("\n");
}

void check_if_equal(int check_variable, int value_for_equality)
{
    //If statement stuff
    if (check_variable == value_for_equality)
        printf("Our input %d is equal to %d.\n", check_variable, value_for_equality);
    else
        printf("Our input %d is not equal to %d.\n", check_variable, value_for_equality);
}

void check_if_equal_quietly(int value_to_check, int value_for_equality)
{
    if (value_to_check == value_for_equality)
        printf("Our input %d is equal to %d.\n", value_to_check, value_for_equality);
}

void check_if_equal_or_inequal(int value_to_check, int value_for_equality)
{
    if (value_to_check < value_for_equality)
        printf("%d is less than %d", value_to_check, value_for_equality);
    else if (value_to_check > value_for_equality)
        printf("%d is greater than %d", value_to_check, value_for_equality);
    else
        printf("%d is equal to %d", value_to_check, value_for_equality);
}

int main(void)
{
    int i;
    int j;
    int k;

    //Initialize variables
    i = 3;
    j = 5;

    //Calling the function to printStuff
    printStuff();

    //Check if i==3
    check_if_equal(i, 3);
    check_if_equal(j, 3);
    check_if_equal_quietly(i, 4);
    check_if_equal_or_inequal(i, 2);

    //Let's look at the four basic arithmetic operations.

    float x;
    float y;
    float z;

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