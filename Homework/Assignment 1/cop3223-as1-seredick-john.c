//Quadratic formula: x= (-b +- srt(b^2-4ac))/2a
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//When adding in the equation
double check_plus_quadratic(double a, double b, double discriminant)
{
    double answer;

    answer = ((-1 * b) + sqrt(discriminant)) / (2 * a);

    return answer;
}

//When subtracting in equation
double check_minus_quadratic(double a, double b, double discriminant)
{
    double answer;

    answer = ((-1 * b) - sqrt(discriminant)) / (2 * a);

    return answer;
}

double get_discriminant(double a, double b, double c)
{
    printf("a: %f, b:%f, c:%f\n", a, b, c);
    return (b * b) - (4 * a * c);
}

int main(void)
{
    double a = 5;
    double b = 10;
    double c = 15;

    double discriminant = get_discriminant(a, b, c);
    printf("The discriminant is: %f\n", discriminant);

    //Imaginary roots
    if (discriminant < 0)
    {
        printf("The roots are: x=(%f+i*%f)/(%f), and x=(%f-i*%f)/(%f)", (-1 * b), (-1 * discriminant), (2 * a), (-1 * b), (-1 * discriminant), (2 * a));
    }
    //1 Root
    else if (discriminant == 0)
    {
        double answer = check_plus_quadratic(a, b, discriminant);
        printf("The root is: x=%f", answer);
    }
    //2 Roots
    else
    {
        double answer_plus = check_plus_quadratic(a, b, discriminant);
        double answer_minus = check_minus_quadratic(a, b, discriminant);
        printf("The roots are: x=%f, and x=%f", answer_plus, answer_minus);
    }
}
