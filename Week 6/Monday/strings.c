#include <stdio.h>
#include <stdlib.h>
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

int main(void)
{
    char hello[128] = "hello, world!\n";
    char name[128];
    char integer_buffer[128];

    char x_buffer[128];
    char y_buffer[128];
    double x;
    double y;

    printf(hello);

    strcpy(hello, "Hello, Earth-2!\n");

    printf(hello);

    //fgets is the function to get a string from a File. We use it instead of the older gets because your compiler will have a fit if you use it.

    printf("What is your name? : ");
    fgets(name, 127, stdin);
    remove_crlf(name);
    printf("Hello, %s!\n", name);

    printf("How many times would you like me to say hello to you? : ");
    fgets(integer_buffer, 127, stdin);

    int how_many_times = atoi(integer_buffer);

    for (int i = 1; i <= how_many_times; i++)
    {
        printf("Hello, time %d, %s\n", i, name);
    }

    printf("What am I multiplying? : ");
    fgets(x_buffer, 127, stdin);
    printf("And by what? : ");
    fgets(y_buffer, 127, stdin);

    x = atof(x_buffer);
    y = atof(y_buffer);

    printf("The product is: %lf.\n", x * y);

    return 0;
}