#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create our line_struct
struct line_struct
{
    float m, b;
    int count;
    double *x, *y;
};

//Define struct as line
typedef struct line_struct line;

//Make a new line and allocate memory needed for this struct
line *make_line(float m, float b, int count, double *x, double *y)
{
    line *l = malloc(sizeof(line) + sizeof(x) + sizeof(y));
    l->m = m;
    l->b = b;
    l->count = count;
    l->x = x;
    l->y = y;

    return l;
}

//Write to the output file
void write_line(FILE *ofp, line *l)
{
    fprintf(ofp, "m: %f\n", l->m);
    fprintf(ofp, "b: %f\n", l->b);
    fprintf(ofp, "count: %d\n", l->count);

    for (int i = 0; i < l->count; i++)
    {
        fprintf(ofp, "X: %3.3lf  Y:%3.3lf\n", l->x[i], l->y[i]);
    }
}

//Free up the memory to eliminate memory leak risk
void dispose_line(line *l, double *x, double *y)
{
    free(l);
    free(x);
    free(y);
}

//Print out the line struct to the terminal
void print_line(line *l)
{
    printf("m: %f\n", l->m);
    printf("b: %f\n", l->b);
    printf("count: %d\n", l->count);

    for (int i = 0; i < l->count; i++)
    {
        printf("X: %3.3lf  Y:%3.3lf\n", l->x[i], l->y[i]);
    }
}

//Compute for y value given m, x and b
double find_y(float m, double x, float b)
{
    return (m * x) + b;
}

int main(void)
{
    //Declare variables
    float m, b;
    int count;
    double *x, *y;
    char buf[256];

    //Open input file
    FILE *ifp;
    ifp = fopen("as5input.txt", "r");

    //Get m and b from same line and print it
    fgets(buf, 255, ifp);
    sscanf(buf, "%f %f", &m, &b);
    printf("m:%f b:%f\n", m, b);

    //Get count from line and print it
    fgets(buf, 255, ifp);
    sscanf(buf, "%d", &count);
    printf("count: %d\n", count);

    //Allocate enough memory for x and y arrays
    x = malloc(sizeof(double) * count);
    y = malloc(sizeof(double) * count);

    //Get line of x values
    fgets(buf, 255, ifp);

    //Get every double (don't have to consider count, that is why we allocated count * sizeof(double))
    int i = 0;
    char *n = strtok(buf, " ");
    do
    {
        x[i++] = atof(n);
    } while (n = strtok(NULL, " "));

    //Close file as we are done reading
    fclose(ifp);

    //Find y values for each x value
    for (int i = 0; i < count; i++)
    {
        y[i] = find_y(m, x[i], b);
    }

    //Create our new line structure and print it out
    line *l = make_line(m, b, count, x, y);
    print_line(l);

    //Open output file and write line to output file
    FILE *ofp;
    ofp = fopen("as5output-seredick-john.txt", "w");
    write_line(ofp, l);

    //Free up the memory we used for line, x and y
    dispose_line(l, x, y);

    return 0;
}