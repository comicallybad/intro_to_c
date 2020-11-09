#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

//This defines our line structure we will be using
struct line_struct
{
    char title[64];
    double m, b, x[10], y[10];
};

typedef struct line_struct line;

line *new_line(char *title, double slope, double intercept, double *xValues, double *yValues)
{
    line *new_line = malloc(sizeof(line));

    //Copy the title, slope and intercept.
    strcpy(new_line->title, title);
    new_line->m = slope;
    new_line->b = intercept;

    //This assigns the corresponding x and y values from xValues and yValues to new_line.
    for (int i = 0; i < 10; i++)
    {
        new_line->x[i] = xValues[i];
        new_line->y[i] = yValues[i];
    }

    return new_line;
}

//Write the line struct to a binary file.
line *write_line(line *new_line)
{
    FILE *ofp;
    ofp = fopen("as4output-seredick-john.bin", "ab");
    fwrite(new_line, sizeof(line), 1, ofp);
    fclose(ofp);
}

// Read the line from the binary file. This won't be used yet I have it here to test
// line *read_line()
// {
//     FILE *ifp;
//     ifp = fopen("as4output-seredick-john.bin", "rb");
//     line *new_line = malloc(sizeof(line));
//     fread(new_line, sizeof(line) * 4, 4, ifp);
//     return new_line;
// }

//Prints out the content of the line struct, spacing is to make it stand out in console.
void print_line(line *new_line)
{
    printf("%s\n\n", new_line->title);
    printf("Slope: %lf intercept: %lf\n\n", new_line->m, new_line->b);
    for (int i = 0; i < 10; i++)
    {
        printf("    X:\t%6.2lf,   Y:\t%6.2lf\n", new_line->x[i], new_line->y[i]);
    }
}

//Computes the y value given an x value, slope and intercept.
double compute_y(double x, double slope, double intercept)
{
    double y;

    y = (slope * x) + intercept;

    return y;
}

int main(void)
{
    //Define needed values for the program
    char buf[256];
    char title[64];
    char n;
    double slope, intercept;
    double xValues[10];
    double yValues[10];

    //Kinda bad practice to have line *line, but we are defining our structure here
    line *line;

    //Open out input file for read mode
    FILE *ifp;
    ifp = fopen("as4input.txt", "r");

    //This is used to keep from appending to a previous run of the application. It essentially
    //whipes the file each time, before then going back into append mode which is needed.
    FILE *ofp;
    ofp = fopen("as4output-seredick-john.bin", "w");
    fclose(ofp);

    //Read how many structures we are going to create
    fgets(buf, 255, ifp);
    remove_crlf(buf);
    sscanf(buf, "%d", &n);

    //This will loop through n structsand fill each struct with it's contents
    for (int i = 0; i < n; i++)
    {
        //Get title
        fgets(title, 255, ifp);
        remove_crlf(title);

        //Get slope and intercept
        fgets(buf, 255, ifp);
        remove_crlf(buf);
        sscanf(buf, "%lf %lf", &slope, &intercept);

        //Get the 10 x values that we will use to compute the y values. Assign into xValues array.
        fgets(buf, 255, ifp);
        remove_crlf(buf);
        sscanf(buf, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
               &xValues[0], &xValues[1], &xValues[2], &xValues[3], &xValues[4],
               &xValues[5], &xValues[6], &xValues[7], &xValues[8], &xValues[9]);

        //For each xValue we are going to compute it's yValue by calling compute_y
        for (int j = 0; j < 10; j++)
        {
            yValues[j] = compute_y(xValues[j], slope, intercept);
        }

        //Here we are actually assigning the values inside the struct.
        line = new_line(title, slope, intercept, xValues, yValues);

        //Print out the line struct
        print_line(line);

        //Write the line struct to the binary file
        write_line(line);
        printf("\n");
    }

    // printf("\n\n");
    // for (int i = 0; i < n; i++)
    // {
    //     line = read_line();
    //     print_line(line);
    // }

    return 0;
}