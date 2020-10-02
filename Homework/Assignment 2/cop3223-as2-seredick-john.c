//Quadratic formula: x= (-b +- srt(b^2-4ac))/2a
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include <string.h>

void remove_crlf(char *s)
{
    char *t = s + strlen(s); // t begins at the null sentinel at the end of s.
    t--;
    /* t is now at the last character of s - unless s didn't contain any characters, in        
     which case, t is now *BEFORE* s.  We have to keep checking for that. */
    /* We repeat until EITHER t slides to the left of s, OR we find a character that is        
     not a line feed (\n) or a carriage return (\r). */
    while ((t >= s) && (*t == '\n' || *t == '\r'))
    {
        *t = '\0'; // Clobber the character t is pointing at.
        t--;       // Decrement t.
    }
}

//When adding in the quadratic equation
double check_plus_quadratic(double a, double b, double discriminant)
{
    double answer;

    answer = ((-1 * b) + sqrt(discriminant)) / (2 * a);

    return answer;
}

//When subtracting in quadratic equation
double check_minus_quadratic(double a, double b, double discriminant)
{
    double answer;

    answer = ((-1 * b) - sqrt(discriminant)) / (2 * a);

    return answer;
}

//Simplify -b / 2a if imaginary answer
double simplify_b_imaginary(double a, double b)
{
    double simplified;

    simplified = (-1 * b) / (2 * a);

    return simplified;
}

//Simplify discriminant / 2a if imaginary answer
double simplify_discriminant_imaginary(double discriminant, double a)
{
    double simplified;

    simplified = (-1 * discriminant) / (2 * a);

    return simplified;
}

// b^2 - 4 * a * c
double get_discriminant(double a, double b, double c)
{
    printf("a: %f, b:%f, c:%f\n", a, b, c);
    return (b * b) - (4 * a * c);
}

int main(void)
{
    char a_buffer[128];
    char b_buffer[128];
    char c_buffer[128];
    double a;
    double b;
    double c;
    char again[128] = "yes";

    while (stricmp(again, "yes") == 0)
    {
        printf("What is your a value? ");
        fgets(a_buffer, 127, stdin);
        a = atof(a_buffer);
        printf("What is your b value? ");
        fgets(b_buffer, 127, stdin);
        b = atof(b_buffer);
        printf("What is your c value? ");
        fgets(c_buffer, 127, stdin);
        c = atof(c_buffer);

        if (a == 0)
        {
            if (b == 0)
            {
                printf("No solution");
            }
            else
            {
                double x = (-1 * c) / b;
                printf("The root is x=%f", x);
            }
        }
        else
        {
            //Get and print discriminant
            double discriminant = get_discriminant(a, b, c);
            printf("The discriminant is: %f\n", discriminant);

            //Imaginary roots simplified
            if (discriminant < 0)
            {
                printf("The roots are: x=(%f+i*%f), and x=(%f-i*%f)",
                       simplify_b_imaginary(a, b), simplify_discriminant_imaginary(discriminant, a),
                       simplify_b_imaginary(a, b), simplify_discriminant_imaginary(discriminant, a));
            }
            //1 Root
            else if (discriminant == 0)
            {
                double x = check_plus_quadratic(a, b, discriminant);
                printf("The root is: x=%f", x);
            }
            //2 Roots
            else
            {
                double x1 = check_plus_quadratic(a, b, discriminant);
                double x2 = check_minus_quadratic(a, b, discriminant);
                printf("The roots are: x=%f, and x=%f", x1, x2);
            }
        }
        printf("\nWould you like to compute another? yes or no : ");
        fgets(again, 127, stdin);
        remove_crlf(again);

        if (stricmp(again, "yes") == 0)
        {
            printf("\n");
        }
        else if (stricmp(again, "no") == 0)
        {
            printf("Okay, sorry to see you go..");
        }
    }

    return 0;
}
