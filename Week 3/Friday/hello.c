#include <stdio.h>
#include <stdlib.h>

// These are single-line comments.  They don't need anything at the end,
// but they have to have a double-slash at the front of each line.

/* This is a multiple-line comment.  Here, we're using it to note that this is
the main function of the program.  A multiple-line comment is delimited with
slash-star at the beginning and star-slash at the end, and does not need any
extra notation per line. */

/* This function checks if we're equal to another value, and prints whether we are or not.
   It's a "void" function because it does not return a value, it just performs actions. */

void check_if_equal(int value_to_check, int value_for_equality)
{
    /* In a CONDITIONAL statement, if the expression inside the if test is TRUE, then the
       code inside the if block is executed.  If the expression inside the if test is FALSE,
       then the code inside the else block is executed. */

    if (value_to_check == value_for_equality)
    {
        printf("Our input %d is equal to our check value %d.\n", value_to_check, value_for_equality);
    }
    else
    {
        printf("Our input %d is not equal to our check value %d.\n", value_to_check, value_for_equality);
    }
}

/* This function checks if we're equal to another value, and prints only if we are. */

void check_if_equal_quietly(int value_to_check, int value_for_equality)
{
    /* Here's another type of conditional, showing that the else block is optional.  If you
       don't have an else block, then if the expression inside the if test is FALSE, nothing
       happens at all. */

    if (value_to_check == value_for_equality)
    {
        printf("Our input %d is equal to our check value %d.\n", value_to_check, value_for_equality);
    }
}

/* This function checks if we're equal to another value in an evil way that should never happen. */

void check_if_equal_evilly(int value_to_check, int value_for_equality)
{
    /* Now we're going to do something bad, that you should not do.  This code sets i equal
       to 5, then the return value of that assignment is 5 - which is true, since it's not 0. 
       
       If that sounds confusing, that's because it's confusing.  If that sounds bad, that's because
       it's bad.  You should never use the return value of an assignment.  Under no circumstances
       whatsoever should you use the return value of an assignment.  There is no time when you 
       should use the return value of an assignment.  Should some sort of ethereal or spiritual
       entity appear to you and suggest that you use the return value of an assignment, you should
       not listen to that entity because it is a demon that intends to claim your soul.  In case
       we are not being clear, you should not, under any circumstances, ever, for any reason, at any
       time, use the return value of an assignment.

       No.  Not even then. 
       
       If you have further questions on when using the return value of an assignment is
       appropriate, please reread the above.
       */

    if (value_to_check = value_for_equality)
    {
        printf("Our input %d is equal to our check value %d.\n", value_to_check, value_for_equality);
        printf("  Of course it is.  We just set it to that, because this function incorrectly\n");
        printf("  tries to compare using a single equals instead of double equals.  The whole\n");
        printf("  purpose of this function is to do that, thus demonstrating the wrong way to\n");
        printf("  compare values.  Knowing that, WHY DID YOU CALL IT!?\n");
    }
}

/* This function checks if we're equal or inequal to another value, and prints the result. */

void check_if_equal_or_inequal(int value_to_check, int value_for_equality)
{
    /* One more type of conditional: We can chain if-else blocks.  Only the appropriate one
       executes - or the last else, if it exists (it's optional here too!) - and none of the
       others do. */

    if (value_to_check < value_for_equality)
    {
        printf("Our input %d is less than our check value %d.\n", value_to_check, value_for_equality);
    }
    else if (value_to_check > value_for_equality)
    {
        printf("Our input %d is greater than our check value %d.\n", value_to_check, value_for_equality);
    }
    else
    {
        printf("Our input %d is equal to our check value %d.\n", value_to_check, value_for_equality);
    }
}

/* Float version of our equality function. */

void check_if_equal_f(float value_to_check, float value_for_equality)
{
    if (value_to_check == value_for_equality)
    {
        printf("Our input %f is equal to our check value %f.\n", value_to_check, value_for_equality);
    }
    else
    {
        printf("Our input %f is not equal to our check value %f.\n", value_to_check, value_for_equality);
    }
}

/* Float version of our quiet equality function. */

void check_if_equal_quietly_f(float value_to_check, float value_for_equality)
{
    if (value_to_check == value_for_equality)
    {
        printf("Our input %f is equal to our check value %f.\n", value_to_check, value_for_equality);
    }
}

/* Float version of our evil equality function. */

void check_if_equal_evilly_f(float value_to_check, float value_for_equality)
{
    if (value_to_check = value_for_equality)
    {
        printf("Our input %f is equal to our check value %f.\n", value_to_check, value_for_equality);
        printf("  Of course it is.  We just set it to that, because this function incorrectly\n");
        printf("  tries to compare using a single equals instead of double equals.  The whole\n");
        printf("  purpose of this function is to do that, thus demonstrating the wrong way to\n");
        printf("  compare values.  Knowing that, WHY DID YOU CALL IT!?\n");
    }
}

/* Float version of our equality/inequality function. */

void check_if_equal_or_inequal_f(float value_to_check, float value_for_equality)
{
    if (value_to_check < value_for_equality)
    {
        printf("Our input %f is less than our check value %f.\n", value_to_check, value_for_equality);
    }
    else if (value_to_check > value_for_equality)
    {
        printf("Our input %f is greater than our check value %f.\n", value_to_check, value_for_equality);
    }
    else
    {
        printf("Our input %f is equal to our check value %f.\n", value_to_check, value_for_equality);
    }
}

/* This function computes some weird integer function.  We don't even know what it 
   does!  We just want to demonstrate returning integer values. */

/* I used silly names in this function just to demonstrate to you that the names
   of the variables don't matter.  YOU SHOULD NEVER USE SILLY NAMES IN YOUR
   FUNCTIONS, and this is the only time I ever, ever will. */

int strange_math_function(int joe, int dave)
{
    int bob;

    bob = (joe + dave - (joe - dave)) * (dave / joe);

    return bob;

    /* When we say "return bob", we are saying "substitute the value of bob for
       this function, whenever this function is called".  So whenever we say
       something like:

       some_variable = strange_math_function(i, j);

       ...some_variable is assigned to the value of bob from this function. */
}

// This function prints out some stuff.  That's why it's called print_stuff.

void print_stuff(void)
{
    printf("Hello, world!\n");
    printf("Notice that this happens first.\n");
    printf("And then this happens.\n");
    printf("And THEN... another thing happens.\n");
    printf("And finally, this happens.\n");
    printf("(Closing credits.  Cue long theme.)\n");
    printf("By the way, if I want to print a %%, I double it.\n");
    printf("And the same thing if I want to print a \\.\n");
}

// Do our integer equality checks.

void check_integer_equalities(int i, int j)
{
    check_if_equal(i, 3);
    check_if_equal(j, 3);
    check_if_equal_quietly(i, 4);
    check_if_equal_or_inequal(i, 2);
    check_if_equal_evilly(i, 5);
}

// Do some basic integer arithmetic and print out the results.

void do_basic_integer_arithmetic(int i, int j)
{
    int k;

    k = i + j; // Addition
    printf("The sum of %d and %d is %d.\n", i, j, k);
    k = i - j; // Subtraction
    printf("The difference of %d and %d is %d.\n", i, j, k);
    k = i * j; // Multiplication
    printf("The product of %d and %d is %d.\n", i, j, k);
    k = i / j; // Division
    printf("The quotient of %d divided by %d is %d.\n", i, j, k);
    k = i % j; // Modulo
    printf("The remainder of %d divided by %d is %d.\n", i, j, k);
    k = strange_math_function(i, j);
    printf("Some function we don't understand of %d and %d is %d.\n", i, j, k);
}

// Do some basic floating point arithmetic and print out the results.

void do_basic_float_arithmetic(float x, float y)
{
    float z;

    z = x + y; // Addition
    printf("The sum of %f and %f is %f.\n", x, y, z);
    z = x - y; // Subtraction
    printf("The difference of %f and %f is %f.\n", x, y, z);
    z = x * y; // Multiplication
    printf("The product of %f and %f is %f.\n", x, y, z);
    z = x / y; // Division
    printf("The quotient of %f divided by %f is %f.\n", x, y, z);
}

// This function plays some games with pi.  Yes, I know the function name is terrible.  I'm not sorry.

void bake_pi(void)
{
    float float_pi = 3.1415926535897932384626433832795028841971693993751058209749445923;
    double double_pi = 3.1415926535897932384626433832795028841971693993751058209749445923;

    printf("Pi:    3.1415926535897932384626433832795028841971693993751058209749445923\n");
    printf("Float: %1.30f\n", float_pi);
    printf("Dbl:   %1.30lf\n", double_pi);
}

// Main function.

int main(void)
{
    int i = 3; // i and j have initial values.  k doesn't.
    int j = 5;
    int k;

    float x = 30000000000.0; // x and y have initial values.  z doesn't.
    float y = 50000.0;
    float z;

    print_stuff(); // Let's do some printing.
    printf("\n");

    check_integer_equalities(i, j); // Do a little testing.
    printf("\n");

    do_basic_integer_arithmetic(i, j); // Look at the basic integer arithmetic operations.
    printf("\n");

    /* Playing with equalities again.  Note that despite the fact that mathematically x should
       equal 30,000 here, it doesn't.
       
       Sometimes we can get around that by changing the order of our operations, or being
       especially careful with how we multiply or divide.  Other times we can't - it's simply
       a limitation of how accurate floating-point numbers are, or rather, aren't.
       
       The lesson is that float and == don't mix well. */

    x /= 1000000.0; // This is like saying x = x / 1000000.0.
    check_if_equal_or_inequal_f(x, 30000.0);
    check_if_equal_f(x, 30000.0);

    printf("\n");

    if (x > 300.0)
    {
        do_basic_float_arithmetic(x, y); // Look at the basic float arithmetic operations.
    }
    else
    {
        printf("x is too small to bother with.\n");
    }

    printf("\n");

    bake_pi(); // Demonstrate the limits of precision, using pi.
    return 0;
}
